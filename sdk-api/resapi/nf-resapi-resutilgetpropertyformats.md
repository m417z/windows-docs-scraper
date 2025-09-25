# ResUtilGetPropertyFormats function

## Description

Returns a property format list describing the format of a specified set of properties. The **PRESUTIL_GET_PROPERTY_FORMATS** type defines a pointer to this function.

## Parameters

### `pPropertyTable` [in]

Pointer to a [RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item) property
table specifying the properties whose formats are to be retrieved.

### `pOutPropertyFormatList` [out]

On input, pointer to a buffer. On a successful return, pointer to a property format list describing the
format of each property specified by *pPropertyTable*.

### `cbPropertyFormatListSize` [in]

Specifies the allocated size (in bytes) of the buffer pointed to by
*pOutPropertyFormatList*.

### `pcbBytesReturned` [out]

Pointer to the actual size (in bytes) of the property format list that results from the operation.

### `pcbRequired` [out]

If the buffer pointed to by the *pOutPropertyFormatList* parameter is too small to
hold the resulting data, *pcbRequired* points to the required buffer size (in
bytes).

## Return value

Returns **ERROR_SUCCESS** if the operation was successful.

## See also

[CLUSCTL_CLUSTER_GET_COMMON_PROPERTY_FMTS](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusctl-cluster-get-common-property-fmts)

[General Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/general-utility-functions)

[RESUTIL_PROPERTY_ITEM](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/ns-resapi-resutil_property_item)