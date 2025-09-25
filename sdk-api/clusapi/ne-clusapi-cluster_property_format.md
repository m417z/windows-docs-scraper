# CLUSTER_PROPERTY_FORMAT enumeration

## Description

Specifies the data type of a property value in a
[property list](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/property-lists).

## Constants

### `CLUSPROP_FORMAT_UNKNOWN:0`

Data is in an unknown format.

### `CLUSPROP_FORMAT_BINARY`

Data is a binary value.

### `CLUSPROP_FORMAT_DWORD`

Data is a **DWORD** value.

### `CLUSPROP_FORMAT_SZ`

Data is a null-terminated Unicode string.

### `CLUSPROP_FORMAT_EXPAND_SZ`

Data is a null-terminated Unicode string with unexpanded references to environment variables.

### `CLUSPROP_FORMAT_MULTI_SZ`

Data is an array of null-terminated Unicode strings.

### `CLUSPROP_FORMAT_ULARGE_INTEGER`

Data is an **ULARGE_INTEGER**.

### `CLUSPROP_FORMAT_LONG`

Data is a signed **LONG** value.

### `CLUSPROP_FORMAT_EXPANDED_SZ`

Data is a null-terminated Unicode string with expanded references to environment variables.

### `CLUSPROP_FORMAT_SECURITY_DESCRIPTOR`

Data is a [SECURITY_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/winnt/ns-winnt-security_descriptor) in
[self-relative](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly)
format. For more information about self-relative security descriptors, see
[Absolute and Self-Relative Security Descriptors](https://learn.microsoft.com/windows/desktop/SecAuthZ/absolute-and-self-relative-security-descriptors).

### `CLUSPROP_FORMAT_LARGE_INTEGER`

Data is a signed **LARGE_INTEGER**.

### `CLUSPROP_FORMAT_WORD`

Data is a **WORD** value.

### `CLUSPROP_FORMAT_FILETIME`

Data is a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime).

### `CLUSPROP_FORMAT_VALUE_LIST`

### `CLUSPROP_FORMAT_PROPERTY_LIST`

### `CLUSPROP_FORMAT_USER:32768`

Reserved for future use.

## See also

[CLUSPROP_SYNTAX](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ns-clusapi-clusprop_syntax)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[Format Property of the ClusProperty Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusproperty-format)

[Format Property of the ClusPropertyValue Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluspropertyvalue-format)