# IWMCodecInfo2::GetCodecFormatDesc

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecFormatDesc** method retrieves a description of a specified codec format. This method also retrieves a stream configuration object containing the settings for the codec format.

## Parameters

### `guidType` [in]

GUID identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `dwCodecIndex` [in]

**DWORD** containing the codec index ranging from zero to one less than the number of supported codecs of the type specified by *guidType*. To retrieve the number of individual codecs supporting a major type, use the [IWMCodecInfo::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecinfocount) method.

### `dwFormatIndex` [in]

**DWORD** containing the format index ranging from zero to one less than the number of supported formats. To retrieve the number of individual formats supported by a codec, use the [IWMCodecInfo::GetCodecFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecformatcount) method.

### `ppIStreamConfig` [out]

Pointer to a pointer to the [IWMStreamConfig](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstreamconfig) interface of a stream configuration object containing the settings of the specified format. When calling **GetCodecFormatDesc** to retrieve the size of the description string, pass **NULL** for this parameter.

### `wszDesc` [out]

Pointer to a wide-character **null**-terminated string containing the codec format description.

### `pcchDesc` [in, out]

On input, a pointer to the length of the *wszDesc* buffer. On output, a pointer to the length of the codec format description string, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An invalid or **null** value has been passed in. |

## Remarks

You should make two calls to **GetCodecFormatDesc**. On the first call, pass **NULL** as *wszDesc*. On return, the value pointed to by *pcchDesc* will be set to the number of wide characters required to hold the description, including the terminating **null** character. Then you can allocate a buffer of the appropriate size and pass a pointer to it as *wszDesc* on the second call.

Some formats of the Windows Media Audio 9 codec and Windows Media Audio 9 Professional codec have very similar descriptions. For example both "64 kbps, 44 kHz, stereo CBR" and "64 kbps, 44 kHz, stereo (A/V) CBR" are listed. In these cases, the format with "(A/V)" in its description is designed for use in files that also contain one or more video streams. The other format is for files that contain only audio.

## See also

[IWMCodecInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo2)