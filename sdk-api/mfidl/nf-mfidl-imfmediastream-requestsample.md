# IMFMediaStream::RequestSample

## Description

Requests a sample from the media source.

## Parameters

### `pToken` [in]

Pointer to the **IUnknown** interface to an object that is used as a token for the request. The caller must implement this object. This parameter can be **NULL**. See Remarks.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_END_OF_STREAM** | The end of the stream was reached. |
| **MF_E_MEDIA_SOURCE_WRONGSTATE** | The media source is stopped. |
| **MF_E_SHUTDOWN** | The source's [Shutdown](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfmediasource-shutdown) method has been called. |

## Remarks

If *pToken* is not **NULL**, the media stream calls **AddRef** on *pToken* and places the token in a first-in, first-out queue.

When the next sample is available, the media stream stream does the following:

1. Pulls the first token from the queue.
2. Sets the [MFSampleExtension_Token](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-token-attribute) attribute on the media sample. The attribute data is a pointer to the token object.
3. Sends an [MEMediaSample](https://learn.microsoft.com/windows/desktop/medfound/memediasample) event. The event data is a pointer to the media sample's [IMFSample](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfsample) interface.
4. Calls **Release** on the token.

If the media stream cannot fulfill the caller's request for a sample, it simply releases the token object and skips steps 2 and 3.

The caller should monitor the reference count on the request token. If the media stream sends an [MEMediaSample](https://learn.microsoft.com/windows/desktop/medfound/memediasample) event, get the [MFSampleExtension_Token](https://learn.microsoft.com/windows/desktop/medfound/mfsampleextension-token-attribute) attribute from the sample and match the attribute value against the token. If the token's reference count falls to zero and you did not receive an MEMediaSample event, it means that the request was dropped.

Because the Media Foundation pipeline is multithreaded, the source's **RequestSample** method might get called after the source has stopped. If the media source is stopped, the method should return **MF_E_MEDIA_SOURCE_WRONGSTATE**. The pipeline does not treat this return code as an error condition. If the source returns any other error code, the pipeline treats it as fatal error and halts the session.

**Note** Earlier versions of the documentation listed the wrong error code for this case.

If the media source is paused, the method succeeds, but the stream does not deliver the sample until the source is started again.

If a media source encounters an error asynchronously while processing data, it should signal the error in one of the following ways (but not both):

* Return an error code from the next **RequestSample** call.
* Send an [MEError](https://learn.microsoft.com/windows/desktop/medfound/meerror) event.

## See also

[IMFMediaStream](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfmediastream)

[Media Sources](https://learn.microsoft.com/windows/desktop/medfound/media-sources)