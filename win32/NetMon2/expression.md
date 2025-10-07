# EXPRESSION structure

The **EXPRESSION** structure contains a group of **ANDEXP** arrays evaluated as peers in logical AND expressions, which have the format

(ANDEXP 1 && ANDEXP 2 && ANDEXP 3).

## Members

**nAndExps**

Number of **ANDEXP** patterns.

**AndExp**

Array of **ANDEXP** patterns. The capture filter arranges all rows of this array as logical AND statements. Be aware that each EXPRESSION structure can contain a maximum of four **ANDEXP** patterns.

## Remarks

For more information about implementing this structure as part of a capture filter, see [Capture Filters](https://learn.microsoft.com/windows/win32/netmon2/capture-filters).

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Netmon.h |

## See also

[ANDEXP](https://learn.microsoft.com/windows/win32/netmon2/andexp)

[CAPTUREFILTER](https://learn.microsoft.com/windows/win32/netmon2/capturefilter)

