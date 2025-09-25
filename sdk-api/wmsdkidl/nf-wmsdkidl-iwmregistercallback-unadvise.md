# IWMRegisterCallback::Unadvise

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Unadvise** method unregisters the application's **IWMStatusCallback** callback interface. Call this method when the application has finished using the sink object. It notifies the object to stop sending status events to the application.

## Parameters

### `pCallback` [in]

Pointer to the [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface of an object.

### `pvContext` [in]

Generic pointer, for use by the application.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## See also

[IWMRegisterCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistercallback)

[IWMRegisterCallback::Advise](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistercallback-advise)