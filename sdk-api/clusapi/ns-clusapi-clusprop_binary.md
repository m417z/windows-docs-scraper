# CLUSPROP_BINARY structure

## Description

Describes a binary data value. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a value
  of **CLUSPROP_SYNTAX_LIST_VALUE_BINARY** (0x00010001).
* A byte array containing the data.

## Members

### `rgb`

Array of bytes containing the data.

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_LIST_VALUE_BINARY** (0x00010001) and a **cbLength** field indicating
the count of bytes in the **rgb** member.

## Remarks

Use the [CLUSPROP_BINARY_DECLARE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusprop_binary_declare) macro to
initialize a **CLUSPROP_BINARY** structure.

## See also

[CLUSPROP_BINARY_DECLARE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusprop_binary_declare)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)