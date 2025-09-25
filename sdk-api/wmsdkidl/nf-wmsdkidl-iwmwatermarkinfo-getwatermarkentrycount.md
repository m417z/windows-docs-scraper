# IWMWatermarkInfo::GetWatermarkEntryCount

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetWatermarkEntryCount** method retrieves the total number of installed watermarking systems of a specified type. Use this method in conjunction with [IWMWatermarkInfo::GetWatermarkEntry](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwatermarkinfo-getwatermarkentry) to enumerate the installed watermarking [DMOs](https://learn.microsoft.com/windows/desktop/wmformat/wmformat-glossary).

## Parameters

### `wmetType` [in]

A value from the [WMT_WATERMARK_ENTRY_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsdkidl/ne-wmsdkidl-wmt_watermark_entry_type) enumeration type specifying the type of watermarking system..

### `pdwCount` [out]

Pointer to a **DWORD** containing the number of watermark entries.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

No watermarking DMOs are provided with the Windows Media Format SDK. You can install third-party DMOs to use with your application.

## See also

[IWMWatermarkInfo Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwatermarkinfo)

[IWMWatermarkInfo::GetWatermarkEntry](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwatermarkinfo-getwatermarkentry)