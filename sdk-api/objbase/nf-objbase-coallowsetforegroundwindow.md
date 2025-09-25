# CoAllowSetForegroundWindow function

## Description

This function passes the foreground privilege (the privilege to set the foreground window) from one process to another. The process that has the foreground privilege can call this function to pass that privilege on to a local COM server process. Note that calling **CoAllowSetForegroundWindow** only confers the privilege; it does not set the foreground window itself. Foreground and focus are only taken away from the client application when the target COM server calls either [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) or another API that does so indirectly.

## Parameters

### `pUnk` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the proxy of the
target COM server.

### `lpvReserved` [in]

This parameter is reserved and must be **NULL**.

## Return value

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | The *lpvReserved* parameter is not **NULL**. |
| **E_NOINTERFACE** | The *pUnk* parameter does not support foreground window control. |
| **E_ACCESSDENIED** | The calling process does not currently possess the foreground privilege. |

## Remarks

The system restricts which processes can call the
[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow) and
[AllowSetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-allowsetforegroundwindow) functions to
set the foreground window. As a result, an application is blocked from stealing the focus from another application
even when the user is interacting with it. Use **CoAllowSetForegroundWindow** to pass on the foreground privilege from a process that has it to a process that does not yet have it. This can be done transitively: passing the privilege from one process to another, and then to another, and so on.

**CoAllowSetForegroundWindow** enables a user
that has a custom interface to get the same behavior that happens for OLE interfaces where a change of window is
expected (primarily associated with linking and embedding).

Behind the scenes, the [IForegroundTransfer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iforegroundtransfer) interface is used to yield the foreground window between processes. A standard COM-provided proxy already implements **IForegroundTransfer**, so you don't have to do any extra work if you're using a standard proxy. Just call **CoAllowSetForegroundWindow** to transfer the foreground privilege to any out-of-process COM object.

#### Examples

The following example demonstrates how a client process can create a local COM server, call **CoAllowSetForegroundWindow** to transfer the foreground privilege, and then call a function on the COM server that in turn directly or indirectly calls [SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow).

```cpp
Microsoft::WRL::ComPtr<IExampleInterface> exampleLocalServer;

ThrowIfFailed(::CoCreateInstance(CLSID_ExampleLocalServer,
	nullptr, CLSCTX_LOCAL_SERVER, IID_PPV_ARGS(&exampleLocalServer)));

// You can adapt to success or failure, but don't automatically throw. Don’t make the
// opening of a window dependent on successfully passing privilege (and taking foreground),
// because the window will signal to the user that it is ready to take focus.
HRESULT hr = ::CoAllowSetForegroundWindow(exampleLocalServer.Get(), nullptr);

// Call an example method that itself calls ::SetForegroundWindow(HWND).
hr = exampleLocalServer->FunctionThatSetsForegroundWindow();
```

## See also

[IForegroundTransfer](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iforegroundtransfer)