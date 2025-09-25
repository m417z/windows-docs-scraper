# IAMStreamSelect::Info

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `Info` method retrieves information about a given stream.

## Parameters

### `lIndex` [in]

Zero-based index of the stream.

### `ppmt` [out]

Address of a variable that receives a pointer to the stream's media type. This parameter is optional and can be **NULL**. If the value is non-**NULL**, the method returns a pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure. The caller must delete the structure, including the format block. (You can use the [DeleteMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/deletemediatype) function from the DirectShow base-class library.)

### `pdwFlags` [out]

Pointer to a variable that receives one of the following values:

| Value | Description |
| --- | --- |
| Zero | This stream is disabled. |
| AMSTREAMSELECTINFO_ENABLED | The stream is enabled, and others in this group might be enabled too. |
| AMSTREAMSELECTINFO_EXCLUSIVE | This stream is the only enabled stream in the group. |

This parameter is optional and can be **NULL**.

### `plcid` [out]

Pointer to a variable that receives a locale context (LCID) value. If the stream is associated with a particular locale, the LCID is returned in this variable. Otherwise, the variable receives the value zero. This parameter is optional and can be **NULL**.

### `pdwGroup` [out]

Pointer to a variable that receives the logical group with which the stream is associated. This parameter is optional and can be **NULL**.

### `ppszName` [out]

Address of a variable that receives a pointer to the stream name. The caller must free the returned string by calling the **CoTaskMemFree** function. This parameter is optional and can be **NULL**.

### `ppObject` [out]

Address of a variable that receives an **IUnknown** interface pointer. The method might return a pointer to a pin or filter associated with the stream, or it might return the value **NULL**. If the method returns a non-**NULL** value, the caller must release the **IUnknown** pointer.

Calling the [IAMStreamSelect::Enable](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamselect-enable) method might invalidate the object returned by this method.

This parameter is optional and can be **NULL**.

The [MPEG-1 Stream Splitter](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-1-stream-splitter-filter), [MPEG-2 Splitter](https://learn.microsoft.com/windows/desktop/DirectShow/mpeg-2-splitter), and [SAMI (CC) Parser](https://learn.microsoft.com/windows/desktop/DirectShow/sami--cc--parser-filter) filters return a pointer to the pin associated with the selected stream.

### `ppUnk` [out]

Address of a variable that receives an **IUnknown** interface pointer. The method might return a pointer to an interface that is specific to the stream, or it might return the value **NULL**. If the method returns a non-**NULL** value, the caller must release the **IUnknown** pointer. This parameter is optional and can be **NULL**.

The MPEG-1 Stream Splitter, MPEG-2 Splitter, and SAMI (CC) Parser filters all return the value **NULL**. Third party filters might return a pointer to a custom filter interface.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_FAIL** | Failure. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **S_FALSE** | The index is out of range. |
| **S_OK** | Success. |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamSelect Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamselect)