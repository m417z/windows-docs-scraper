# IWMWriterAdvanced::SetSyncTolerance

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetSyncTolerance** method sets the amount of time that the inputs can fall out of synchronization before the samples are discarded.

## Parameters

### `msWindow` [in]

Amount of time that the inputs can be out of synchronization, in milliseconds. Note that this parameter is in milliseconds and not 100-nanosecond units.

## Return value

This method always returns S_OK.

## Remarks

The default tolerance value is 3000 milliseconds.

Regardless of what the tolerance is set to, keeping samples as tightly synchronized as possible results in the best performance and the highest-quality content.

## See also

[IWMWriterAdvanced Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced)

[IWMWriterAdvanced::GetSyncTolerance](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriteradvanced-getsynctolerance)