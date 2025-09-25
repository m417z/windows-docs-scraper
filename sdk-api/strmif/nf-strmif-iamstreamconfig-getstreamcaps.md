# IAMStreamConfig::GetStreamCaps

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetStreamCaps** method retrieves a set of format capabilities.

## Parameters

### `iIndex` [in]

Specifies the format capability to retrieve, indexed from zero. To determine the number of capabilities that the pin supports, call the [IAMStreamConfig::GetNumberOfCapabilities](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-getnumberofcapabilities) method.

### `ppmt` [out]

Address of a pointer to an [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure. The method allocates the structure and fills it with a media type.

### `pSCC` [out]

Pointer to a byte array allocated by the caller. For video, use the [VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-video_stream_config_caps) structure (see Remarks). For audio, use the [AUDIO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-audio_stream_config_caps) structure. To determine the required size of the array, call the **GetNumberOfCapabilities** method. The size is returned in the *piSize* parameter.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | Specified index is too high. |
| **S_OK** | Success. |
| **E_INVALIDARG** | Invalid index. |
| **E_OUTOFMEMORY** | Insufficient memory. |
| **E_POINTER** | **NULL** pointer value. |
| **VFW_E_NOT_CONNECTED** | The input pin is not connected. |

## Remarks

This method returns two pieces of information:

* The *pmt* parameter receives a filled-in [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure, which describes one supported output format.
* The *pSCC* parameter receives a structure that contains additional format information. For video, *pSCC* receives a [VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-video_stream_config_caps) structure. For audio, it receives an [AUDIO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-audio_stream_config_caps) structure.

**Note** Use of the [VIDEO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-video_stream_config_caps) structure to configure a video device is deprecated. Although the caller must allocate the buffer, it should ignore the contents after the method returns. The capture device will return its supported formats through the *pmt* parameter.

To configure the output pin so that it uses this format, call the [IAMStreamConfig::SetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-setformat) method and pass in the value of *pmt*.

Before calling [SetFormat](https://learn.microsoft.com/windows/desktop/api/strmif/nf-strmif-iamstreamconfig-setformat), you can modify the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure in *pmt*, using the information in *pSCC*. For example, an audio pin might return a default media type of 44-kHz, 16-bit stereo in the *pmt* parameter. Based on the values returned in the [AUDIO_STREAM_CONFIG_CAPS](https://learn.microsoft.com/windows/win32/api/strmif/ns-strmif-audio_stream_config_caps) structure, you might change this format to 8-bit mono before calling **SetFormat**.

The method allocates the memory for the [AM_MEDIA_TYPE](https://learn.microsoft.com/windows/desktop/api/strmif/ns-strmif-am_media_type) structure that is returned in the *pmt* parameter. The caller must release the memory, including the format block. You can use the [DeleteMediaType](https://learn.microsoft.com/windows/desktop/DirectShow/deletemediatype) helper function in the base class library. The caller must allocate the memory for the *pSCC* parameter.

On some compression filters, this method fails if the filter's input pin is not connected.

**Filter Developers**: For more information on implementing this method, see [Exposing Capture and Compression Formats](https://learn.microsoft.com/windows/desktop/DirectShow/exposing-capture-and-compression-formats).

#### Examples

The following example retrieves the first supported format (index zero) on a video output pin and then sets this format on the pin.

| C++ |
| --- |
| ``` int iCount, iSize; BYTE *pSCC = NULL; AM_MEDIA_TYPE *pmt;<br><br>hr = pConfig->GetNumberOfCapabilities(&iCount, &iSize);<br><br>pSCC = new BYTE[iSize]; if (pSCC == NULL) {     // TODO: Out of memory error. }<br><br>// Get the first format. hr = pConfig->GetStreamCaps(0, &pmt, pSCC)); if (hr == S_OK) {     // TODO: Examine the format. If it's not suitable for some     // reason, call GetStreamCaps with the next index value (up     // to iCount). Otherwise, set the format:     hr = pConfig->SetFormat(pmt);     if (FAILED(hr))     {         // TODO: Error handling.     }     DeleteMediaType(pmt); } delete [] pSCC; ``` |

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IAMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iamstreamconfig)