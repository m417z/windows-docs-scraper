## Description

Describes multiple
**NULL**-terminated Unicode strings. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the partition information.
* A string array.

For convenience, the [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) members are listed
explicitly.

## Members

### `sz`

Multiple null-terminated Unicode strings with the last string followed by an additional **NULL**-terminating character.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)