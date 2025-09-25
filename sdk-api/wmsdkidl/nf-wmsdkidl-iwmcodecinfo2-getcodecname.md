# IWMCodecInfo2::GetCodecName

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecName** method retrieves the name of a specified codec.

## Parameters

### `guidType` [in]

GUID identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `dwCodecIndex` [in]

**DWORD** containing the codec index ranging from zero to one less than the number of supported codecs of the type specified by *guidType*. To retrieve the number of individual codecs supporting a major type, use the [IWMCodecInfo::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecinfocount) method.

### `wszName` [out]

Pointer to a wide-character **null**-terminated string that receives the codec name.

### `pcchName` [in, out]

On input, pointer to a **DWORD** containing the size, in wide characters, of the buffer *wszName*. On output, pointer to a variable containing the number of characters in *wszName*, including the terminating **null** character.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | An invalid or **null** value has been passed in. |

## Remarks

You should make two calls to **GetCodecName**. On the first call, pass **NULL** as *wszName*. On return, the value at *pcchName* will be set to the buffer size required to hold the codec name, including the terminating character. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *wszName* on the second call.

## See also

[IWMCodecInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo2)