# ResUtilGetResourceName function

## Description

Returns the name of a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The
**PRESUTIL_GET_RESOURCE_NAME** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Resource handle (see
[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)).

### `pszResourceName` [out]

Pointer to a buffer that receives the resource name.

### `pcchResourceNameInOut` [in, out]

On input, specifies the size of the buffer pointed to by *pszResourceName*, in wide
characters. On output, specifies the actual size of the resource name returned as a count of wide
characters.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).