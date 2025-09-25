# CLUSPROP_FTSET_INFO structure

## Description

Contains information about an FT (fault tolerant) set. It is used as an entry in a
[value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of a [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) and a [CLUS_FTSET_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_ftset_info) structure.

## Members

### `CLUSPROP_VALUE`

A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure that describes the format,
type, and length of the resource class value.

### `CLUS_FTSET_INFO`

A [CLUS_FTSET_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_ftset_info) value that describes the
FT set.

## See also

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)