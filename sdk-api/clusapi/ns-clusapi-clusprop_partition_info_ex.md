# CLUSPROP_PARTITION_INFO_EX structure

## Description

Specifies a collection of information about a physical disk resource, such as its device name and volume label.
The **CLUSPROP_PARTITION_INFO_EX**
structure contains information relevant to
[storage class resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly). It is
used as an entry in a [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure describing the format,
  type, and length of the partition information.
* A [CLUS_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info_ex)
  structure.

## Members

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_PARTITION_INFO_EX** (0x000d0001) and a **cbLength** field indicating
the count of bytes in the **CLUS_PARTITION_INFO_EX** member.

### `CLUS_PARTITION_INFO_EX`

A [CLUS_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info_ex) structure.

## See also

[CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)

[CLUSPROP_PIFLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-clusprop_piflags)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[CLUS_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_partition_info_ex)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)