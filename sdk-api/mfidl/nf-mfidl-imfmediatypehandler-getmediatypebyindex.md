# IMFMediaTypeHandler::GetMediaTypeByIndex

## Description

Retrieves a media type from the object's list of supported media types.

## Parameters

### `dwIndex` [in]

Zero-based index of the media type to retrieve. To get the number of media types in the list, call [IMFMediaTypeHandler::GetMediaTypeCount](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-getmediatypecount).

### `ppType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_NO_MORE_TYPES** | The *dwIndex* parameter is out of range. |

## Remarks

Media types are returned in the approximate order of preference. The list of supported types is not guaranteed to be complete. To test whether a particular media type is supported, call [IMFMediaTypeHandler::IsMediaTypeSupported](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediatypehandler-ismediatypesupported).

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler)