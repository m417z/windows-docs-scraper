# CLUSPROP_VALUE structure

## Description

Describes the syntax and
length of a data value used in a [value list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/value-lists). The
**CLUSPROP_VALUE** structure is used as a generic header in
all of the structures that describe data of a particular type, such as
[CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary) and
[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85)).

## Members

### `Syntax`

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax) union that describes a
value.

### `cbLength`

Count of bytes in the data that follows this
**CLUSPROP_VALUE** structure.

## Remarks

The **CLUSPROP_VALUE** structure is used to describe the
format, type, and length of a data value in the following structures:

* [CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary)
* [CLUSPROP_DISK_NUMBER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_dword)
* [CLUSPROP_DISK_SIGNATURE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368374(v=vs.85))
* [CLUSPROP_DWORD](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368375(v=vs.85))
* [CLUSPROP_FILETIME](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_filetime)
* [CLUSPROP_LONG](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_long)
* [CLUSPROP_MULTI_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_sz)
* [CLUSPROP_PARTITION_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info)
* [CLUSPROP_PARTITION_INFO_EX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_partition_info_ex)
* [CLUSPROP_PROPERTY_NAME](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368382(v=vs.85))
* [CLUSPROP_REQUIRED_DEPENDENCY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_required_dependency)
* [CLUSPROP_RESOURCE_CLASS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class)
* [CLUSPROP_RESOURCE_CLASS_INFO](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_resource_class_info)
* [CLUSPROP_SCSI_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_scsi_address)
* [CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85))
* [CLUSPROP_ULARGE_INTEGER](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_ularge_integer)
* [CLUSPROP_WORD](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_word)

## See also

[CLUSPROP_BINARY](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_binary)

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[CLUSPROP_SZ](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/aa368390(v=vs.85))

[CLUSPROP_VALUE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_value)

[Data structures](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-structures)