# IHandlerActivationHost::BeforeCreateProcess

## Description

Notifies a client of [ShellExecuteEx](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-shellexecuteexw) that a process is about to created, giving that client the opportunity to display UI confirming that or reject it by returning a specific error code.

## Parameters

### `applicationPath` [in]

The fully qualified path to the process executable, or in some cases a DLL path.

### `commandLine` [in]

The full command line that will be passed to **CreateProcess** including the arguments that the handler requested via its registration.

### `handlerInfo` [in]

Provides access to information about the handler that will be invoked. This object also supports **IHandlerInfo2** on versions of windows that support that interface. This object also implements [IObjectWithSelection](https://learn.microsoft.com/windows/win32/api/shobjidl_core/nn-shobjidl_core-iobjectwithselection). This can be used to get the Shell item, or items in some cases, that are being launched.

## Return value

If this method succeeds, it returns **S_OK**.
Otherwise, it returns an **HRESULT** error code, **HRESULT_FROM_WIN32(ERROR_CANCELLED)** indicates that the ShellExecute call should be canceled.

## See also

[IHandlerActivationHost](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ihandleractivationhost)