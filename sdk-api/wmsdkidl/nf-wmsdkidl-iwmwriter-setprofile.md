# IWMWriter::SetProfile

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetProfile** method specifies the profile to use for the current writing task.

## Parameters

### `pProfile` [in]

Pointer to an [IWMProfile](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **ASF_E_STREAMNUMBERINUSE** | More than one stream in the profile has the same stream number. |
| **NS_E_INVALIDPROFILE** | The profile has zero streams.<br><br>The bit rate was specified as zero for a CBR-encoding mode.<br><br>More than one script stream was specified.<br><br>The bandwidth-sharing information is incorrect or inconsistent. |
| **NS_E_INVALID_STATE** | The writer is not in a configurable state. |
| **NS_E_INVALID_STREAM** | For any stream:<br><br>* A buffer window greater than 100,000 was specified.<br>* A stream number was specified as less than one or greater than 63.<br><br>For audio streams:<br><br>* The **formattype** is not **WMFORMAT_WaveFormatEx**.<br>* The **wformatTag** is not WAVE_FORMAT_PCM and **nAvgBytesPerSec** is zero.<br>* The FOURCC derived from the subtype **GUID** does not match the **dwFormatTag**.<br>* For PCM audio, **nAvgBytesPerSec** is not equal to (**nSamplesPerSec** * **nBlockAlign**).<br>* For PCM audio, **nBlockAlign** is not equal to (**nChannels** * **wBitsPerSample** / 8).<br><br>For video streams:<br><br>* The **formattype** is not **WMFORMAT_VideoInfo**.<br>* **cbFormat** is not equal to sizeof(**WMVIDEOINFOHEADER**).<br>* The bit rate specified through **IWMStreamConfig** is not equal to the value of **dwBitrate** in the **VIDEOINFOHEADER**. (Does not apply if [IWMStreamConfig::SetBitrate](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstreamconfig-setbitrate) was used to set a bit rate of zero.)<br>* On uncompressed video streams, **bmiHeader.biSizeImage** has been specified incorrectly.<br>* The rectangle width or height specified in the **bmiHeader** is not valid for the compression type. (Some types require two- or four-byte alignment.)<br>* Any member of the **rcSource** or **rcTarget** rectangles is negative.<br>* The FOURCC derived from the subtype **GUID** does not match **bmiHeader.biCompression**.<br>* The **bmiHeader.biCompression** member is BI_BITFIELDS, but **cbFormat** is incorrect.<br>* When **bmiHeader.biCompression** = BI_RGB or BI_BITFIELDS, the **biBitCount**, **biClrUsed**, or **cbFormat** values are inconsistent or invalid. (Remember that the size of the format block is larger if the **BITMAPINFOHEADER** contains an index of palette values.)<br><br>For script streams:<br><br>* The **formattype** is not specified as **WMFORMAT_Script**.<br>* The subtype is not specified as **GUID_NULL**. |
| **NS_E_SDK_BUFFERTOOSMALL** | The size specified for a language string in an audio stream is too small. |

## Remarks

Calling this method removes any previously set header attribute information.

Changes to the profile object made after this method is called do not take effect until **SetProfile** is called again.

The maximum number of streams in a profile is 63, as defined by the constant WM_MAX_STREAMS. Another constant, WM_MAX_VIDEO_STREAMS, defines the maximum number of video streams, which is also 63.

## See also

[Attributes](https://learn.microsoft.com/windows/desktop/wmformat/attributes)

[IWMProfile Interface](https://learn.microsoft.com/windows/desktop/wmformat/iwmprofile)

[IWMWriter Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriter)

[IWMWriter::SetProfileByID](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setprofilebyid)

[To Use Profiles with the Writer](https://learn.microsoft.com/windows/desktop/wmformat/to-use-profiles-with-the-writer)