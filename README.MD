## Register-Accessed Macros

- U32 WDT_REGISTER[4] act as target register to be access.
- struct WDT_REGS: a base register with their contained sub-register.
- macro WDT: a macro for access register.

---

```c
(volatile WDT_REGS *) (&WDT_REGISTER)
```

#####When pointing "WDT_REGS" to WDT_REGISTER[0]. Trust all member in "WDT_REGS" will point to WDT_REGISTER[x] respectively.   
#####Trust, "WDT_REGISTER[4]" will never access because no pointer from WDT pointing to it.
---

```c
#define WDT    ((volatile WDT_REGS *) (&WDT_REGISTER))
```

#####Then we use a macro WDT to shotten a statement "(volatile WDT_REGS *) (&WDT_REGISTER)"
---


