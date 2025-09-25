# IHandlerActivationHost::BeforeCoCreateInstance

## Description

Notifies a client of [ShellExecuteEx](https://learn.microsoft.com/windows/win32/api/shellapi/nf-shellapi-shellexecuteexw) that a handler is about to be created, giving that client the opportunity to display UI confirming the use of that handler or reject it by returning a specific error code.

## Parameters

### `clsidHandler` [in]

Identifies the handler.

### `itemsBeingActivated` [in]

The Shell item objects that will be passed to the handler. Typically there is only one, but in some cases there can be more than one.

### `handlerInfo` [in]

Provides access to information about the handler that will be invoked. This object also supports **IHandlerInfo2** on versions of Windows that support that interface.

## Return value

If this method succeeds, it returns **S_OK**.
Otherwise, it returns an **HRESULT** error code, **HRESULT_FROM_WIN32(ERROR_CANCELLED)** indicates that the ShellExecute call should be canceled, **EXECUTE_E_LAUNCH_APPLICATION** indicates that this handler should not be used, but if there is another it should be used.

## See also

[IHandlerActivationHost](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ihandleractivationhost)