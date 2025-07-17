# Real-Time Limit Order Book & Matching Engine

**High-Performance, Multi-threaded Matching Engine in C++ with PostgreSQL Integration**

---

## Overview

This project implements a **real-time Limit Order Book (LOB)** and **price-time priority matching engine** in C++, designed for ultra-low latency and high throughput. It supports **multi-symbol trading**, persistent logging to **PostgreSQL**, and is **stress-tested** with over **100,000+ trades** using simulated order flow.

---

## Core Features

### Matching Engine
- Implements **price-time priority** matching logic.
- Uses **Red-Black Trees** for each side of the book to enable **logarithmic-time insert/search/delete** operations.

### Engine Architecture
- **Object-Oriented Design** following **SOLID principles** for modularity and future extensibility.
- Written in **modern C++ (C++17)** with clear separation between matching logic, order book data structures, and database layers.
- Developed with **unit tests using Google Test (gtest)** to ensure correctness and robustness.

### Multithreading
- Supports **parallel order books** for multiple symbols using **C++ std::thread**.
- Optimized for **multi-core processors**, achieving **~2× speedup** vs. sequential round-robin processing.
- Thread-safe queueing and matching without compromising latency or consistency.

### PostgreSQL Integration
- All **matched trades and order events** are persisted to a **PostgreSQL database** for auditability and offline analysis.
- Asynchronous logging layer to minimize database latency impact on order matching.

---

## Performance

- **100,000+ trades** simulated and matched within seconds on commodity hardware.
- Red-Black Tree matching ensures **O(log N)** order book operations even at scale.
- **2× speedup** using multi-threaded symbol handling vs. single-threaded baseline.

---

## Project Structure
```
├── src/ # Core engine logic (LOB, Order, Matching)
├── tests/ # Google Test unit test cases
├── data/ # Simulated order flow and output logs
├── CMakeLists.txt # Build configuration
└── README.md # Project documentation
```

## Architecture Overview
The Limit Order Book & Matching Engine is designed for high-performance and reliability, separating concerns into distinct, interconnected modules. At its core, it processes incoming orders, matches them against existing orders in the book, executes trades, and logs all significant events for persistence.

### Core Components:
- Order Input & Validation: The entry point for all new orders and modifications. It's responsible for initial syntax and basic business rule validation before orders proceed to the matching engine.
- Matching Engine: The brain of the system. For each trading instrument, it manages a dedicated Limit Order Book.
-  Limit Order Book (LOB): Implemented using highly optimized red-black trees for both bid and ask sides. This ensures O(log N) complexity for order insertion, deletion, and matching operations, maintaining price-time priority.
-  Matching Logic: When a new incoming order arrives, the matching logic attempts to cross it with resting orders in the LOB based on price-time priority rules.
-  Trade Execution & Notification: Upon a successful match, this component generates trade execution reports. These reports contain details of the executed trade (price, quantity, participants) and are then logged.
-  Persistence Layer (PostgreSQL): All critical events, including order receipts and trade executions, are persistently logged into a PostgreSQL database. This provides an immutable audit trail, supports debugging, and could be used for state recovery in event of crash.
-  Multi-Book Handler (Multithreading): For scenarios involving multiple trading instruments or assets, the system employs C++ multithreading. This allows different order books to be processed concurrently, significantly enhancing overall throughput and responsiveness by leveraging multi-core processors.

## Future Enhancements
- Custom Tree Structure (to attempt O(1) functionality)
- Support for Limit Order Cancel & Update
- Support for Market Orders
- Support for Fill-or-Kill (FOK) and Immediate-or-Cancel (IOC) order types
- Visualisation Tool
- State Recovery Logic from logs
- Live WebSocket API for real-time order entry
- Real-time Kafka integration for event streaming


