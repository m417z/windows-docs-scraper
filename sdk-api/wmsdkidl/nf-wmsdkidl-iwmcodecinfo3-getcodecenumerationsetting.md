# IWMCodecInfo3::GetCodecEnumerationSetting

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecEnumerationSetting** method retrieves the current value for one codec enumeration setting. Codec enumeration settings dictate the codec formats that can be enumerated by the methods of [IWMCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo). You can change codec enumeration settings in order to retrieve codec formats supporting specific features by calling [IWMCodecInfo3::SetCodecEnumerationSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo3-setcodecenumerationsetting).

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

Pointer to a wide-character **null**-terminated string containing the name of the enumeration setting. Use one of the following constants.

| Constant | Description |
| --- | --- |
| g_wszVBREnabled | Use to enumerate the supported codec formats that use variable bit rate (VBR) encoding.The value returned in *pValue* is a BOOL. |
| g_wszNumPasses | Use to enumerate the supported codec formats that use a number of passes equal to the value in *pValue*.The value returned in *pValue* is a **DWORD** specifying the number of passes. |

### `pType` [out]

Pointer to a [WMT_ATTR_DATATYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_attr_datatype) enumeration value specifying the data type of the value returned in *pValue*.

### `pValue` [out]

Pointer to a **BYTE** array containing the codec enumeration data. The data type and meaning of the data returned in this array depends on the setting specified by *pszName*. You can set this value to **NULL** to retrieve the required size of the array in *pdwSize*.

### `pdwSize` [in, out]

Pointer to a **DWORD** containing the size of the setting value in bytes. If you set *pValue* to **NULL**, this value will be set to the size required to hold the setting value.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_UNSUPPORTED_PROPERTY** | The enumeration setting specified is not valid for the codec. |

## See also

[IWMCodecInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo3)

[SetCodecEnumerationSetting](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmcodecinfo3-setcodecenumerationsetting)