# IWMCodecInfo3::GetCodecFormatProp

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecFormatProp** method retrieves a property from one format of a codec.

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

### `pszName` [in]

Pointer to a wide-character **null**-terminated string containing the name of the property to retrieve.

Currently only one codec format property is supported; it is listed in the following table. The format property determines the data type and value of the property; this information is included in the table.

| Global constant | Data type | Description |
| --- | --- | --- |
| g_wszSpeechCaps | **WMT_TYPE_DWORD** | The value is one from the [WMT_MUSICSPEECH_CLASS_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_musicspeech_class_mode) enumeration type indicating the supported mode of the format. This property applies only to the Windows Media Audio 9 Voice codec. |

### `pType` [out]

Pointer to a variable that will receive a member of the **WMT_ATTR_DATATYPE** enumeration type. This value specifies the type of information returned to the buffer pointed to by *pValue*.

### `pValue` [out]

Pointer to a buffer that will receive the value of the property. The data returned is of a type specified by *pType*.

### `pdwSize` [in, out]

Pointer to a **DWORD** value specifying the length of the buffer pointed to by *pValue*.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pszName* or *pType* or *pdwSize* is **NULL**.<br><br>OR<br><br>*guidType* specifies an invalid input type.<br><br>OR<br><br>*pszName* specifies an invalid property name. |

## Remarks

You should make two calls to **GetCodecFormatProp** for each property you want to retrieve. On the first call, pass **NULL** as *pValue*. On return, the value of *pdwSize* will be set to the buffer size required to hold the value of the specified property. Then you can allocate the required amount of memory for the buffer and pass a pointer to it as *pValue* on the second call.

## See also

[IWMCodecInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmcodecinfo3)