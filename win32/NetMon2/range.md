# RANGE structure

The **RANGE** structure defines a range of valid property values.

## Members

**MinValue**

Lowest possible value in a range.

**MaxValue**

Highest possible value in a range.

## Remarks

The **RANGE** structure is used to specify a valid range of numbers for a protocol property. If the **DataQualifier** member of the **PROPERTYINFO** structure is set to **PROP\_QUAL\_RANGE**, the **lpRange** member of the [PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo) structure must provide a pointer to a **RANGE** structure.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[PROPERTYINFO](https://learn.microsoft.com/windows/win32/netmon2/propertyinfo)

