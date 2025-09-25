# IWMWriterPostViewCallback::AllocateForPostView

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **AllocateForPostView** method allocates a buffer for use in postviewing operations. The application implements this method.

## Parameters

### `wStreamNum` [in]

**WORD** containing the stream number.

### `cbBuffer` [in]

Size of *ppBuffer*, in bytes.

### `ppBuffer` [out]

Pointer to a pointer to an [INSSBuffer](https://learn.microsoft.com/previous-versions/windows/desktop/api/wmsbuffer/nn-wmsbuffer-inssbuffer) interface.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

This method is implemented by the application. It should return S_OK.

## See also

[IWMWriterPostViewCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmwriterpostviewcallback)