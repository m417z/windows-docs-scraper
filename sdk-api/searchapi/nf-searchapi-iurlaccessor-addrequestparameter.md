# IUrlAccessor::AddRequestParameter

## Description

Requests a property-value set.

## Parameters

### `pSpec` [in]

Type: **[PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec)***

Pointer to a [PROPSPEC](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propspec) structure containing the requested property.

### `pVar` [in]

Type: **[PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant)***

Pointer to a [PROPVARIANT](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-propvariant) structure containing the value for the property specified by *pSpec*.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Implement this method to obtain additional information from the content source (for instance, the If-Modified-Since header in an HTTP request).