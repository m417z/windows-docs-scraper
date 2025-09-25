# IWMCodecInfo3::SetCodecEnumerationSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetCodecEnumerationSetting** method sets the value of one codec enumeration setting. Codec enumeration settings dictate the codec formats that can be enumerated by the methods of [IWMCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo).

## Parameters

### `guidType` [in]

GUID identifying the major type of digital media. This must be one of the following constants.

| Constant | Description |
| --- | --- |
| WMMEDIATYPE_Video | Specifies a video codec. |
| WMMEDIATYPE_Audio | Specifies an audio codec. |

### `dwCodecIndex` [in]

**DWORD** containing the codec index ranging from zero to one less than the number of supported codecs of the type specified by *guidType*. To retrieve the number of individual codecs supporting a major type, use the [IWMCodecInfo::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo-getcodecinfocount) method.

### `pszName` [in]

Pointer to a wide-character null-terminated string containing the name of the enumeration setting. Use one of the following constants.

| Constant | Description |
| --- | --- |
| g_wszVBREnabled | Use to enumerate the supported codec formats that use variable bit rate (VBR) encoding.The value returned in *pValue* is a **BOOL**. |
| g_wszNumPasses | Use to enumerate the supported codec formats that use a number of passes equal to the value in *pValue*.The value returned in *pValue* is a **DWORD** specifying the number of passes. |

### `Type` [in]

A [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) value specifying the data type of the value in *pValue*.

### `pValue` [in]

A pointer to a **BYTE** array containing the setting value.

### `dwSize` [in]

**DWORD** containing the size of the *pValue* **BYTE** array.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded; the feature is supported by the codec. |
| **NS_E_UNSUPPORTED_PROPERTY** | The enumeration setting specified is not valid for the codec. |

## Remarks

The Windows Media Audio and Video 9 Series codecs can potentially enumerate four different sets of codec formats, as listed in the following table.

|  | Constant bit rate (CBR) stream | Two-pass CBR stream | Quality-based variable bit rate (VBR) stream | Bit-rate-based VBR stream (constrained or unconstrained) |
| --- | --- | --- | --- | --- |
| g_wszVBREnabled | FALSE | FALSE | TRUE | TRUE |
| g_wszNumPasses | 1 | 2 | 1 | 2 |

Not all codecs support all formats.

If you make a call to this method and get the NS_E_UNSUPPORTED_PROPERTY error code, then the codec does not support that feature. For example, if an attempt to set g_wszNumPasses returns NS_E_UNSUPPORTED_PROPERTY, the codec does not support multiple encoding passes.

The return value of a call made to this method does not guarantee support of a codec feature. For example, the Windows Media Audio 9 Lossless codec does not return NS_E_UNSUPPORTED_PROPERTY for calls that set the number of passes, even though the codec does not support two-pass encoding.

## See also

[GetCodecEnumerationSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo3-getcodecenumerationsetting)

[IWMCodecInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo3)