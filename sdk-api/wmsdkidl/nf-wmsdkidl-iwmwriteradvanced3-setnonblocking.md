# IWMWriterAdvanced3::SetNonBlocking

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetNonBlocking** method configures the writer so that the calling thread is not blocked while writing samples.

## Return value

The method always returns S_OK.

## Remarks

You should use this method only for time-critical threads. After calling **SetNonBlocking**, it is the responsibility of the calling application to control the amount of data that is queued to the writer. It is possible to queue too much data for the writer to handle, or to take up too many of the resources of the computer. In extreme cases, the encoding session can stop unexpectedly as a result.

This method has no effect when writing from a live source. It is normal for the writer to refrain from blocking the caller's thread in a live encoding situation.

## See also

[IWMWriterAdvanced3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriteradvanced3)