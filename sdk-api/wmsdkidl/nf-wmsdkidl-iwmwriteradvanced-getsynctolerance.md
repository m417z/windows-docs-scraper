# IWMWriterAdvanced::GetSyncTolerance

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **GetSyncTolerance** method retrieves the amount of time during which the inputs can fall out of synchronization before the samples are discarded.

## Parameters

### `pmsWindow` [in]

Pointer to the limit of the number of milliseconds that the inputs can be out of synchronization. Note that this parameter is in milliseconds and not 100-nanosecond units.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | *pmsWindow* is **NULL**. |

## Remarks

The default tolerance is 3000 milliseconds.

## See also

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[IWMWriterAdvanced::SetSyncTolerance](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-setsynctolerance)