# IPerPropertyBrowsing::MapPropertyToPage

## Description

Retrieves the CLSID of the property page associated with the specified property.

## Parameters

### `dispID` [in]

The dispatch identifier of the property.

### `pClsid` [out]

A pointer to the CLSID identifying the property page associated with the property specified by *dispID*. If this method fails, **pClsid* is set to CLSID_NULL.

## Return value

This method can return the standard return values E_INVALIDARG and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_NOTIMPL** | The object does not support property pages at all or does not support mapping properties to the page CLSID. In other words, this feature of specific property browsing is not supported. |
| **E_POINTER** | The address in *pClsid* is not valid. For example, it may be **NULL**. |

## Remarks

The CLSID returned from this method can be passed to [OleCreatePropertyFrameIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframeindirect) to specify the initial page to display in the property sheet.

## See also

[IPerPropertyBrowsing](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-iperpropertybrowsing)