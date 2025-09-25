# CLUSPROP_LONG structure

## Description

Describes signed
**LONG** data. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the numeric data.
* A **LONG** value.

## Members

### `l`

Signed **LONG** value.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_LIST_VALUE_LONG** (0x00010007) and a **cbLength** field indicating
the count of bytes in the **l** member.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)