# IWMWriterFileSink3::SetUnbufferedIO

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **SetUnbufferedIO** method specifies whether unbuffered I/O is used for the file sink. You can improve performance by using unbuffered I/O for writer sessions with a high bit rate and a long running time.

## Parameters

### `fUnbufferedIO` [in]

A **BOOL** that specifies whether to use unbuffered I/O.

### `fRestrictMemUsage` [in]

A **BOOL** that specifies whether memory usage should be restricted. Passing True for this parameter severely limits the size of the buffers used to prepare data for unbuffered writing. This limitation usually counteracts any performance gains from using unbuffered I/O.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **NS_E_INVALID_REQUEST** | The header has already been written. |

## Remarks

This method enables the application to override the writer's decision about whether to use unbuffered I/O.

If you want to use unbuffered I/O, you must call this method before writing the header of the file.

This method dynamically allocates a set of buffers to prepare data for unbuffered writing. The size of these buffers is dependent upon the amount of available physical memory.

## See also

[IWMWriterFileSink3 Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterfilesink3)

[IWMWriterFileSink3::GetUnbufferedIO](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmwriterfilesink3-getunbufferedio)