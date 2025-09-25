# CLUSPROP_WORD structure

## Description

Describes numeric data. It
is used as an entry in a [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the numeric data.
* A **WORD** value.

## Members

### `w`

Numeric value.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing
the format, type, and
the count of bytes in the **w** member.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)