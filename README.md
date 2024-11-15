# Government-Budget-Management-System



This **Government Budget Management System** is designed using the **Composite Design Pattern**, a structural pattern that helps manage entities in a hierarchical structure. This project models the relationships between Central, State, and Local governments as components that can be handled dynamically. The system allows users to manage the budgets of these entities by adding or removing governments at any level.

### **Key Features:**
- **Composite Design Pattern**:
  - The project uses the Composite Design Pattern, which allows treating individual and composite objects uniformly. Central, State, and Local governments are treated as `GovernmentComponent` objects, which means they can be managed consistently regardless of whether they are at the highest or lowest level of the hierarchy.
  
- **Dynamic Entity Handling**:
  - The system supports adding and removing government entities at all levels (Central, State, Local). This flexibility allows the structure to grow or shrink dynamically as needed, making the system adaptable to different scenarios or changes in governance.
  
- **Budget Calculation and Management**:
  - Each government entity (Central, State, Local) has a budget. The system allows for calculating the total budget for any government entity by aggregating the budgets of its sub-entities (like States under Central Government, or Locals under State Governments).

- **Polymorphism & Virtual Destructors**:
  - The project makes use of polymorphism to handle various types of government entities in a consistent manner. Virtual destructors ensure that the memory is properly managed, avoiding memory leaks when objects are deleted.

- **Exception Handling**:
  - The system ensures that negative budget values are not allowed. If any entity is assigned a negative budget, an exception is thrown, maintaining the integrity of the data.

### **Technologies Used:**
- **Programming Language**: C++
  - The system is implemented in C++, leveraging the object-oriented principles and C++ features like inheritance, polymorphism, and exception handling.

- **Design Pattern**: Composite Pattern
  - This pattern is essential in creating a tree structure where objects at various levels can be treated uniformly, allowing for simplified management of the complex hierarchy.

- **Core Concepts**: 
  - **Polymorphism**: The ability to treat objects of different classes (Central, State, Local) in a similar way through a common interface (`GovernmentComponent`).
  - **Virtual Destructors**: To handle dynamic memory allocation and ensure proper cleanup when objects are deleted.
  - **Exception Handling**: Used to ensure that invalid operations (such as assigning negative budgets) do not disrupt the program's flow.

### **Project Structure:**
- `main.cpp`: This is the entry point of the program. It initializes the government entities (Central, State, Local) and demonstrates how to add/remove entities and display their budgets.
- `GovernmentComponent.h` & `GovernmentComponent.cpp`: Defines the `GovernmentComponent` interface and its derived classes (Central, State, Local).
- `BudgetManagement.cpp`: Contains the logic for managing and calculating the total budgets of the entities.

### **Getting Started:**
To run the project locally, follow these steps:

1. **Clone the repository** to your local machine:
   ```bash
   git clone https://github.com/your-username/government-budget-management-system.git





