# DEFINE_PROPERTYKEY macro

## Syntax

```cpp
void DEFINE_PROPERTYKEY(
     name,
    DWORD l,
    WORD w1,
    WORD w2,
    BYTE b1,
    BYTE b2,
    BYTE b3,
    BYTE b4,
    BYTE b5,
    BYTE b6,
    BYTE b7,
    BYTE b8,
    DWORD pid
);
```

## Description

Used to pack a format identifier (FMTID) and property identifier (PID) into a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that represents a property key.

## Parameters

### `name`

The name of a [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure that represents a property key.

### `l`

The value of the **Data1** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `w1`

The value of the **Data2** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `w2`

The value of the **Data3** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b1`

The value of the **Data4[0]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b2`

The value of the **Data4[1]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b3`

The value of the **Data4[2]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b4`

The value of the **Data4[3]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b5`

The value of the **Data4[4]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b6`

The value of the **Data4[5]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b7`

The value of the **Data4[6]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `b8`

The value of the **Data4[7]** member of the **fmtid** member of the [PROPERTYKEY](https://learn.microsoft.com/windows/desktop/api/wtypes/ns-wtypes-propertykey) structure.

### `pid`

A property identifier (PID). It is recommended that you set this value to PID_FIRST_USABLE. Any value greater than or equal to 2 is acceptable.

**Note** Values of 0 and 1 are reserved and should not be used.

## Remarks

The **DEFINE_PROPERTYKEY** macro is defined as follows.

```
#ifdef INITGUID
#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
EXTERN_C const PROPERTYKEY DECLSPEC_SELECTANY name = \
{ { l, w1, w2, { b1, b2,  b3,  b4,  b5,  b6,  b7,  b8 } }, pid }
#else
#define DEFINE_PROPERTYKEY(name, l, w1, w2, b1, b2, b3, b4, b5, b6, b7, b8, pid) \
EXTERN_C const PROPERTYKEY name
#endif // INITGUID
```

When using this macro, you have two options:

* Include Initguid.h in your project. In this case, the macro declares the property key names and defines the property keys for you. This approach works in most cases, but can cause naming collisions in large, complex projects.
* Do not include Initguid.h. Instead, compile your definitions into a static library file that has the .lib file name extension. In this case, the macro declares the property key names for the compiler to use, but you must reference your .lib file in the linker settings for your project. This approach works best in large projects that use multiple modules because it avoids the naming collisions mentioned in option 1.

Using the macro without including Initguid.h and without referencing a library file raises the LNK2001 linker error.