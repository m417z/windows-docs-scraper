# IWMCodecInfo::GetCodecInfoCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecInfoCount** method retrieves the number of supported codecs for a specified major type of digital media (audio or video).

## Parameters

### `guidType` [in]

**GUID** identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `pcCodecs` [out]

Pointer to a count of supported codecs.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *pcCodecs* has been passed a null value. |
| **E_INVALIDARG** | *guidType* is not a type for which codecs are used. |

## Remarks

Use this method along with **GetCodecFormatCount** and **GetCodecFormat** to enumerate through the supported codecs for each media type, and the supported formats for each codec.

The Windows Media Format SDK provides codecs only for audio and video. If you specify another major type, this method will return an error.

## See also

[IWMCodecInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo)

[IWMCodecInfo::GetCodecFormat](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformat)

[IWMCodecInfo::GetCodecFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformatcount)