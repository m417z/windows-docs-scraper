# IWMRegisterCallback::Advise

## Description

\[The feature associated with this page, [Windows Media Format 11 SDK](https://learn.microsoft.com/windows/win32/wmformat/windows-media-format-11-sdk), is a legacy feature. It has been superseded by [Source Reader](https://learn.microsoft.com/windows/win32/medfound/source-reader) and [Sink Writer](https://learn.microsoft.com/windows/win32/medfound/sink-writer). **Source Reader** and **Sink Writer** have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **Source Reader** and **Sink Writer** instead of **Windows Media Format 11 SDK**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The **Advise** method registers the application to receive status messages from the sink object.

## Parameters

### `pCallback` [in]

Pointer to the application's [IWMStatusCallback](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmstatuscallback) interface. The application must implement this interface.

### `pvContext` [in]

Generic pointer, for use by the application. This is passed to the application in calls to **OnStatus**.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an **HRESULT** error code.

## Remarks

The sink object sends status messages to the application by calling the application's [IWMStatusCallback::OnStatus](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmstatuscallback-onstatus) method.

When the application has finished using the sink object, use the **Unadvise** method to break the connection with the sink object.

## See also

[IWMRegisterCallback Interface](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nn-wmsdkidl-iwmregistercallback)

[IWMRegisterCallback::Unadvise](https://learn.microsoft.com/windows/desktop/api/wmsdkidl/nf-wmsdkidl-iwmregistercallback-unadvise)