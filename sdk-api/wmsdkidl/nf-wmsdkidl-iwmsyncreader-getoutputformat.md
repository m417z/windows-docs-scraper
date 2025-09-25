# IWMSyncReader::GetOutputFormat

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetOutputFormat** method retrieves the supported formats for a specified output media stream.

## Parameters

### `dwOutputNum` [in]

**DWORD** containing the output number.

### `dwFormatNum` [in]

**DWORD** containing the format number.

### `ppProps` [out]

Pointer to a pointer to an [IWMOutputMediaProps](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmoutputmediaprops) interface. This object is created by a successful call to this method.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *ppProps* is **NULL**. |
| **E_UNEXPECTED** | No file is open in the synchronous reader. |

## Remarks

To enumerate the supported formats for an output media stream, call [GetOutputFormatCount](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-getoutputformatcount) to get the number of formats, and then call **GetOutputFormat** in succession to get the formats.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)