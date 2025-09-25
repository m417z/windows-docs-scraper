# IWMWriterSink::AllocateDataUnit

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AllocateDataUnit** method is called by the writer object when it needs a buffer to deliver a data unit. Your implementation of this method returns a buffer of at least the size passed in. You can manage buffers internally in any way that you like. The simplest method is to create a new buffer object for each call, but doing so is quite inefficient. Instead, most sinks maintain several buffers that are reused.

## Parameters

### `cbDataUnit` [in]

Size of the data unit that the writer needs to deliver, in bytes. The buffer you assign to *ppDataUnit* must be this size or bigger.

### `ppDataUnit` [out]

On return, set to a pointer to the [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface of a buffer object.

## Return value

This method is implemented by the application. It should always return S_OK.

## See also

[IWMWriterSink Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwritersink)