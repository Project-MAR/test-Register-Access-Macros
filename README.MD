## Register-Accessed Macros

- U32 WDT_REGISTER[4] a simulate for target register to be accessed.
- struct WDT_REGS: a base register with their contained sub-register.
- macro WDT: a macro for access register.

---

```c
(volatile WDT_REGS *) (&WDT_REGISTER)
```

When pointing "WDT_REGS" to WDT_REGISTER[0]. Trust all member in "WDT_REGS" will point to WDT_REGISTER[x] respectively. Trust, "WDT_REGISTER[4]" will never access because no pointer from WDT_REGS is pointing to.

---

```c
#define WDT    ((volatile WDT_REGS *) (&WDT_REGISTER))
```
Then we use a macro WDT to shorten a statement "(volatile WDT_REGS *) (&WDT_REGISTER)"

---

####volatile Keyword
If you face...
 - Code that works fine, until you enable compiler optimizations
 - Code that works fine, until interrupts are enabled
 - Flaky hardware drivers
 - RTOS tasks that work fine in isolation--until some other task is spawned

[wiki](https://en.wikipedia.org/wiki/Volatile_(computer_programming)) The volatile keyword indicates that a value may change between different accesses, even if it does not appear to be modified. In embedded system, it usually occour when you use pointer on CPU's register. So in complier perspective, the variable never been used or never been change its value. Trust, when compiling, the complier try to optimize this variable, Trust, in the a or strange Behaviour.
---


