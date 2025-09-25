# IWMReaderAdvanced2::GetSaveAsProgress

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSaveAsProgress** method retrieves the percentage of data that has been saved.

## Parameters

### `pdwPercent` [out]

Pointer to a **DWORD** containing the percentage of data that has been saved.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

This method must only be called after [IWMReaderAdvanced2::SaveFileAs](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmreaderadvanced2-savefileas) has been called.

When saving a file, the operation can take some time. This call must be made between the events WMT_SAVEAS_START and WMT_SAVEAS_STOP. If it is called before WMT_SAVEAS_START, or there is an error, this method returns zero. It returns 100 following a successful WMT_SAVEAS_STOP event.

## See also

[IWMReaderAdvanced2 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmreaderadvanced2)