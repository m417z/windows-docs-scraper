# IWMHeaderInfo3::AddCodecInfo

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AddCodecInfo** method adds codec information to a file. When you copy a compressed stream from one file to another, use this method to include the information about the encoding codec in the file header.

## Parameters

### `pwszName` [in]

Pointer to a wide-character null-terminated string containing the name.

### `pwszDescription` [in]

Pointer to a wide-character null-terminated string containing the description.

### `codecType` [in]

A value from the [WMT_CODEC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_codec_info_type) enumeration specifying the codec type.

### `cbCodecInfo` [in]

The size of the codec information, in bytes.

### `pbCodecInfo` [in]

Pointer to an array of bytes that contains the codec information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The parameters passed to this method should be obtained from the original file with a call to [IWMHeaderInfo2::GetCodecInfo](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmheaderinfo2-getcodecinfo).

## See also

[IWMHeaderInfo3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmheaderinfo3)