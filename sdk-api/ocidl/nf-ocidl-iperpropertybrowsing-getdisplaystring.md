# IPerPropertyBrowsing::GetDisplayString

## Description

Retrieves a text string describing the specified property.

## Parameters

### `dispID` [in]

The dispatch identifier of the property whose display name is requested.

### `pBstr` [out]

A pointer to a variable that receives the display name for the property identified in *dispID*. The string is allocated by this method using **SysAllocString**. Upon return, the string is the responsibility of the caller, which must free it with **SysFreeString** when it is no longer needed.

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The display name was successfully returned. |
| **E_NOTIMPL** | The object does not provide display names for individual properties. The caller has the recourse to check the object's type information for the text name of the object in this case. |
| **E_POINTER** | The address in pbstr is not valid. For example, it may be **NULL**. |

## See also

[IPerPropertyBrowsing](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing)