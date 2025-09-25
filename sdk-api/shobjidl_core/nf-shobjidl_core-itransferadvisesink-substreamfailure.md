# ITransferAdviseSink::SubStreamFailure

## Description

Called when there is a failure that involves secondary streams and user interaction is needed.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that caused the failure.

### `pszStreamName` [in]

Type: **LPCWSTR**

The name of the data that will be lost in the operation.

### `hrError` [in]

Type: **HRESULT**

The error code that was generated. It must be handled by the copy engine.

## Return value

Type: **HRESULT**

Any other **HRESULT** should be passed up. If the failure is not handled, the return value should be *hrError*.

| Return code | Description |
| --- | --- |
| **COPYENGINE_S_USERRETRY** | The handler should retry the file operation. |
| **COPYENGINE_S_USERRETRYWITHNEWNAME** | The handler should retry the file operation using the name returned in the *pszRename* buffer. |
| **COPYENGINE_S_OVERWRITE** | The user has indicated that the handler should overwrite the existing file. |
| **COPYENGINE_S_RETRYWITHOUTSECURITY** | The user has indicated that the handler should try the operation again without the security descriptor. |
| **COPYENGINE_E_USERCANCELLED** | The user clicked **Cancel**. The entire copy job is being terminated. The handler should return this code back to the copy engine. |