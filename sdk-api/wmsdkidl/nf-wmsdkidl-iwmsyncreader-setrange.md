# IWMSyncReader::SetRange

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetRange** method enables you to specify a start time and duration for playback by the synchronous reader.

## Parameters

### `cnsStartTime` [in]

Offset into the file at which to start playback. This value is measured in 100-nanosecond units.

### `cnsDuration` [in]

Duration in 100-nanosecond units, or zero to continue playback to the end of the file.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** | The *cnsDuration* parameter is negative. |
| **E_OUTOFMEMORY** | The method is unable to allocate memory for an internal object. |
| **E_UNEXPECTED** | No file is loaded in the synchronous reader. |

## Remarks

This method specifies a range for the whole file only. You cannot specify a range for an individual stream.

You can call **SetRange** at any time after a file has been loaded.

The start time you specify might not be the presentation time of the first sample received. The synchronous delivers video samples starting with the key frame before the specified time.

## See also

[IWMSyncReader Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmsyncreader)

[IWMSyncReader::SetRangeByFrame](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmsyncreader-setrangebyframe)