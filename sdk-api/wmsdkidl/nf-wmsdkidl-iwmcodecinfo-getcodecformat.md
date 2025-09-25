# IWMCodecInfo::GetCodecFormat

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecFormat** method retrieves one format supported by a specified codec. This method retrieves a pointer to the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface of a stream configuration object containing the stream settings for the supported format.

## Parameters

### `guidType` [in]

**GUID** identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `dwCodecIndex` [in]

**DWORD** containing the codec index ranging from zero to one less than the number of supported codecs of the type specified by *guidType*. To retrieve the number of individual codecs supporting a major type, use the [IWMCodecInfo::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecinfocount) method.

### `dwFormatIndex` [in]

**DWORD** containing the format index ranging from zero to one less than the number of supported formats. To retrieve the number of individual formats supported by a codec, use the [IWMCodecInfo::GetCodecFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformatcount) method.

### `ppIStreamConfig` [out]

Pointer to a pointer to the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface of a stream configuration object containing the settings of the specified format.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An invalid or null value has been passed in. |

## Remarks

Use this method along with **GetCodecFormatCount** to enumerate the formats supported by the codec.

The codec format describes the characteristics of the compressed data stream in the file, and has no direct correlation to the uncompressed format of the input media or the output media. The format of input media data is determined at the time of encoding, using the [IWMWriter::SetInputProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriter-setinputprops) method. The format of output media data is determined at the time of decoding, using the **SetOutputProps** method of either the [IWMReader](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreader) interface or the [IWMSyncReader](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader) interface.

The Windows Media Format SDK provides codecs only for audio and video. If you specify another major type, this method will return an error.

The Windows Media Video codecs all support a single format that you must complete with your desired settings. When obtaining a video format, you can always use format index 1. For more information see [Configuring Video Streams](https://learn.microsoft.com/windows/desktop/wmformat/configuring-video-streams).

## See also

[IWMCodecInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo)

[IWMCodecInfo::GetCodecFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformatcount)

[IWMStreamConfig Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig)