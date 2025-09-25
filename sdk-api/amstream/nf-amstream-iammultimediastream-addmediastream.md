# IAMMultiMediaStream::AddMediaStream

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

**Note** This interface is deprecated. New applications should not use it.

The `AddMediaStream` method adds a new media stream to the filter graph.

## Parameters

### `pStreamObject` [in]

Pointer to the **IUnknown** interface of an object that is used to create the new media stream. This parameter can be **NULL**. See Remarks for more information.

### `PurposeId` [in]

Pointer an [MSPID](https://learn.microsoft.com/windows/desktop/DirectShow/mspid) the specifies the type of media stream to create. This parameter can be **NULL**.

### `dwFlags` [in]

Bitwise combination of zero or more of the following flags.

| Value | Description |
| --- | --- |
| AMMSF_ADDDEFAULTRENDERER | Add a default renderer (audio streams only). |
| AMMSF_CREATEPEER | Create a new stream based on the object specified in *pStreamObject*. |
| AMMSF_NOSTALL | Create a stream that does not block waiting for **Update** calls. |
| AMMSF_STOPIFNOSAMPLES | Create a stream that stops if there are not samples. |

### `ppNewStream` [out]

Address of a variable that receives an [IMediaStream](https://learn.microsoft.com/windows/desktop/api/mmstream/nn-mmstream-imediastream) interface pointer.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Invalid argument. |
| **E_POINTER** | **NULL** pointer argument. |
| **MS_E_PURPOSEID** | Invalid purpose ID. |
| **S_OK** | Success. |

## Remarks

If *pPurposeID* is **NULL**, *pStreamObject* must specify an **IMediaStream** object. The object's **GetInformation** method is used to determine the purpose ID, which is then used to create the new media stream.

If the purpose ID is MSPID_PrimaryAudio and *dwFlags* includes the AMMSF_ADDDEFAULTRENDERER flag, the method adds the DirectSound Renderer to the filter graph.

If *dwFlags* includes the AMMSF_CREATEPEER flag, the method uses the object specified by *pStreamObject* to create a new media stream. In that case, *pStreamObject* can specify any of the following:

* An **IAMMediaStream** pointer.
* An **IMediaStream** pointer.
* An **IDirectDraw** pointer.

If neither flag is set, *pStreamObject* can be any of the following:

* An **IAMMediaStream** pointer. The object is added to the multimedia stream.
* An **IDirectDraw** pointer. The DirectDraw object is used to create a default video stream.
* **NULL**. A default media stream object is created.

If the method succeeds, the caller must release the returned **IMediaStream** interface.

## See also

[IAMMultiMediaStream Interface](https://learn.microsoft.com/windows/desktop/api/amstream/nn-amstream-iammultimediastream)