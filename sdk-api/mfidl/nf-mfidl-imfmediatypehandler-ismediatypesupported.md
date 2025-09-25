# IMFMediaTypeHandler::IsMediaTypeSupported

## Description

Queries whether the object supports a specified media type.

## Parameters

### `pMediaType` [in]

Pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the media type to check.

### `ppMediaType` [out]

Receives a pointer to the [IMFMediaType](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfmediatype) interface of the closest matching media type, or receives the value **NULL**. If non-**NULL**, the caller must release the interface. This parameter can be **NULL**. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_INVALIDMEDIATYPE** | The object does not support this media type. |

## Remarks

If the object supports the media type given in *pMediaType*, the method returns **S_OK**. For a media source, it means the source can generate data that conforms to that media type. For a media sink, it means the sink can receive data that conforms to that media type. If the object does not support the media type, the method fails.

The *ppMediaType* parameter is optional. If the method fails, the object might use *ppMediaType* to return a media type that the object does support, and which closely matches the one given in *pMediaType*. The method is not guaranteed to return a media type in *ppMediaType*. If no type is returned, this parameter receives a **NULL** pointer. If the method succeeds, this parameter receives a **NULL** pointer. If the caller sets *ppMediaType* to **NULL**, this parameter is ignored.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with Service Pack 2 (SP2) and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

This interface is available on the following platforms if the Windows Media Format 11 SDK redistributable components are installed:

* Windows XP with SP2 and later.
* Windows XP Media Center Edition 2005 with KB900325 (Windows XP Media Center Edition 2005) and KB925766 (October 2006 Update Rollup for Windows XP Media Center Edition) installed.

## See also

[IMFMediaTypeHandler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediatypehandler)