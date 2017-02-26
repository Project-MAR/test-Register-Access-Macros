## Register-Accessed Macros

- U32 WDT_REGISTER[4] act as target register to be access.
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


