# CLUSPROP_LARGE_INTEGER structure

## Description

Describes a signed large integer. It is used as an entry in a [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure indicating the format and type of the integer value.
* Assigned large integer value.

## Members

### `li`

Signed large integer value.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a **cbLength** field indicating
the count of bytes in the **li** member.

## Remarks

Use caution when referencing large integer values in **DWORD**-aligned structures such
as value lists, [property lists](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists), and
[parameter blocks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/parameter-blocks). For Windows Server for Itanium-based
systems, a naturally-aligned large integer value always begins on an address ending in 0h or 8h.
**DWORD**-alignment can cause large values to begin on unaligned boundaries (addresses
ending in 4h or Ch), which will cause an alignment fault when the data is read or written. You can avoid
alignment faults by separately copying the high and low **DWORD**s of large values into
local variables, which are guaranteed to be naturally aligned.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)

[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)