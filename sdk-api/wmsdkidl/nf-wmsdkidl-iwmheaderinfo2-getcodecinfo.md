# IWMHeaderInfo2::GetCodecInfo

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetCodecInfo** method retrieves information about a codec that is used to create the content of a file.

## Parameters

### `wIndex` [in]

**DWORD** that contains the zero-based codec index.

### `pcchName` [in, out]

On input, pointer to the length of *pwszName* in wide characters. On output, pointer to a count of the characters that are used in *pwszName*.This includes the terminating **null** character.

### `pwszName` [out]

Pointer to a wide-character **null**-terminated string buffer into which the name of the codec is copied.

### `pcchDescription` [in, out]

On input, pointer to the length of *pwszDescription* in wide characters. On output, pointer to a count of the characters that are used in *pwszDescription*. This includes the terminating **null** character.

### `pwszDescription` [out]

Pointer to a wide-character **null**-terminated string buffer into which the description of the codec is copied.

### `pCodecType` [out]

Pointer to one member of the [WMT_CODEC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_codec_info_type) enumeration type.

### `pcbCodecInfo` [in, out]

On input, pointer to the length of *pbCodecInfo*, in bytes. On output, pointer to a count of the bytes used in *pbCodecInfo*.

### `pbCodecInfo` [out]

Pointer to a byte array.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

You should make two calls to **GetCodecInfo**. On the first call, pass **NULL** for *pwszName*, *pwszDescription*, and *pbCodecInfo*. On return the values pointed to by *pcchName* and *pcchDescription* are set to the number of characters. These include the terminating **null** character, which is required to hold the name string in *pcchName* and the description string in *pcchDescription*. The value pointed to by *pcbCodecInfo* is set to the buffer size required to hold the codec information. With these sizes, you can allocate the required amount of memory to receive each value. Pass pointers to the buffers are *pwszName*, *pwszDescription*, and *pbCodecInfo* on the second call.

Use this method, and the **GetCodecInfoCount** method, to enumerate through the codec information.

## See also

[IWMHeaderInfo2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo2)

[IWMHeaderInfo2::GetCodecInfoCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo2-getcodecinfocount)

[IWMHeaderInfo3](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)

[WMT_CODEC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_codec_info_type)