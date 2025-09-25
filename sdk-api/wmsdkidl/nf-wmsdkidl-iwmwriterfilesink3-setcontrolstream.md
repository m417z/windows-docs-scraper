# IWMWriterFileSink3::SetControlStream

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetControlStream** method enables you to specify that a stream should be used as a control stream. You can also use this method to indicate that a previously specified control stream should no longer be used as a control stream.

## Parameters

### `wStreamNumber` [in]

A **WORD** specifying the stream number to configure. Stream numbers must be in the range of 1 through 63.

### `fShouldControlStartAndStop` [in]

A BOOL specifying whether or not the stream should be used as a control stream.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The stream number specified by *wStreamNumber* is greater than the maximum. |

## Remarks

Control streams add accuracy to **Start** and **Stop** calls. Instead of trying to find the best starting or stopping place for the file based on times in interleaved streams, the file sink starts and stops the file at exactly the specified time in the control stream. The other streams are then synchronized with the control stream.

You can have more than one control stream, by making multiple calls to this method. The file sink will start or stop at the first encountered instance of the desired time.

## See also

[IWMWriterFileSink3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink3)