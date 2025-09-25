# IMFMediaTypeHandler::SetCurrentMediaType

## Description

Sets the object's media type.

## Parameters

### `pMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the new media type.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDREQUEST** | Invalid request. |

## Remarks

For media sources, setting the media type means the source will generate data that conforms to that media type. For media sinks, setting the media type means the sink can receive data that conforms to that media type.

Any implementation of this method should check whether *pMediaType* differs from the object's current media type. If the types are identical, the method should return S_OK but avoid releasing and recreating resources unnecessarily. If the types are not identical, the method should validate the new type.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler)