# CLUSPROP_SCSI_ADDRESS structure

## Description

Describes an address for a [SCSI](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/s-gly)
device. It is used as an entry in a [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists) and consists
of:

* A [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure indicating the format
  and type of the resource class information.
* A [CLUS_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_scsi_address) structure.

For convenience, the [CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) and
[CLUS_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_scsi_address) members are listed explicitly.

## Members

### `CLUSPROP_VALUE`

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value) structure with a [CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) with a value
of **CLUSPROP_SYNTAX_SCSI_ADDRESS** (0x00060002) and a **cbLength** field indicating
the count of bytes in the **CLUS_SCSI_ADDRESS** member. Padding bytes are not included in the count.

### `CLUS_SCSI_ADDRESS`

A [CLUS_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_scsi_address) structure.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[CLUS_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clus_resource_class_info)

[ClusScsiAddress](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusscsiaddress-object)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)