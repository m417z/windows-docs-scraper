## Description

Describes a
numeric value identifying the physical drive of a disk. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the numeric data.
* A **DWORD** value identifying the physical drive of a disk.

For convenience, the [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) members are listed
explicitly.

## Members

### `dw`

Numeric value identifying the physical drive of the disk. Valid values begin at zero.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)