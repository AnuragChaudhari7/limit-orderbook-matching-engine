# simulate_orders.py
import random
import time
import argparse
from datetime import datetime
import csv

ORDER_TYPES = ["LIMIT"]#, "MARKET"]
SIDES = ["BUY", "SELL"]

def generate_order(order_id, price_range, quantity_range, tick_size=0.01, user_id_range=(1, 100)):
    order_type = random.choice(ORDER_TYPES)
    side = random.choice(SIDES)
    quantity = int(random.uniform(*quantity_range))
    user_id = random.randint(*user_id_range)

    order = {
        # "timestamp": datetime.utcnow().isoformat(),
        # "order_id": order_id,
        "user_id": user_id,
        "type": order_type,
        "side": side,
        "quantity": quantity,
        "price": ""
    }

    if order_type == "LIMIT":
        raw_price = random.uniform(*price_range)
        #order["price"] = round(round(raw_price / tick_size) * tick_size, 2)
        order["price"] = int(round(raw_price / tick_size) * tick_size)

    return order

def simulate_stream(output_file, num_orders, delay_ms, price_range, quantity_range):
    """
    Simulate real-time order stream to a CSV file with random LIMIT orders.

    Args:
        output_file (str): Path to the CSV file (default: 'orders.csv').
        num_orders (int): Number of orders to generate (default: 100).
        delay_ms (int): Delay between order generations in milliseconds (default: 50 ms).
        price_range (tuple): Price range for orders (min=99.5, max=100.5).
        quantity_range (tuple): Quantity range for orders (min=1.0, max=10.0).
    """
    with open(output_file, mode="w", newline="", encoding="utf-8") as f:
        # writer = csv.DictWriter(f, fieldnames=["timestamp", "order_id", "type", "side", "quantity", "price"])
        writer = csv.DictWriter(f, fieldnames=["user_id", "type", "side", "quantity", "price"], lineterminator="\n")
        writer.writeheader()
        for order_id in range(1, num_orders + 1):
            order = generate_order(order_id, price_range, quantity_range)
            writer.writerow(order)
            f.flush()
            time.sleep(delay_ms / 1000.0)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Simulate real-time order flow (CSV)")
    parser.add_argument("--output", type=str, default="orders.csv", help="Output CSV file path")
    parser.add_argument("--num_orders", type=int, default=100, help="Number of orders to generate")
    parser.add_argument("--delay_ms", type=int, default=50, help="Delay between orders (ms)")
    parser.add_argument("--min_price", type=float, default=99.5, help="Minimum price")
    parser.add_argument("--max_price", type=float, default=100.5, help="Maximum price")
    parser.add_argument("--min_qty", type=float, default=1.0, help="Minimum quantity")
    parser.add_argument("--max_qty", type=float, default=10.0, help="Maximum quantity")

    args = parser.parse_args()

    simulate_stream(
        output_file=args.output,
        num_orders=args.num_orders,
        delay_ms=args.delay_ms,
        price_range=(args.min_price, args.max_price),
        quantity_range=(args.min_qty, args.max_qty)
    )
