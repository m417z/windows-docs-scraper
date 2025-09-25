# IWMCodecInfo::GetCodecFormatCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecFormatCount** method retrieves the number of formats supported by the specified codec. Each codec format is a stream configuration that is valid for use with the codec.

## Parameters

### `guidType` [in]

**GUID** identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `dwCodecIndex` [in]

**DWORD** containing the codec index ranging from zero to one less than the number of supported codecs of the type specified by *guidType*. To retrieve the number of individual codecs supporting a major media type, use the [IWMCodecInfo::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecinfocount) method.

### `pcFormat` [out]

Pointer to a count of the formats supported by the codec.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pcFormat* has been passed a null value. |
| **E_INVALIDARG** | Other unspecified failure. |

## Remarks

Use this method along with **GetCodecFormat** to enumerate the formats supported by the codec.

The Windows Media Format SDK provides codecs only for audio and video. If you specify another major type, this method will return an error.

You do not need to call this method for the Windows Media Video codecs; each video codec supports only a single format. For more information see [Configuring Video Streams](https://learn.microsoft.com/windows/desktop/wmformat/configuring-video-streams).

## See also

[IWMCodecInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo)

[IWMCodecInfo::GetCodecFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformat)