# PRJ_CANCEL_COMMAND_CB callback function

## Description

Notifies the provider that an operation by an earlier invocation of a callback should be canceled.

## Parameters

### `callbackData` [in]

Information about the operation. The following *callbackData* members are necessary to implement this callback:

**CommandId** Identifies the operation to be cancelled.

## Remarks

Every invocation of a provider callback has a *callbackData* parameter with a **CommandId** field. If a provider supplies an implementation of this callback, it should keep track of the **CommandId** values of callbacks that it processes asynchronously, i.e. callbacks from which it has returned **HRESULT_FROM_WIN32(ERROR_IO_PENDING)** but not yet completed by calling [PrjCompleteCommand](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjcompletecommand). If the provider receives this callback, it indicates that the I/O that caused the earlier callback to be invoked was canceled, either explicitly or because the thread it was issued on terminated. The provider should cancel processing the callback invocation identified by **CommandId** as soon as possible.

Calling [PrjCompleteCommand](https://learn.microsoft.com/windows/desktop/api/projectedfslib/nf-projectedfslib-prjcompletecommand) for the **CommandId** in this callback's callbackData is not an error, however it is a no-op because the I/O that caused the callback invocation identified by **CommandId** has already ended.

ProjFS will invoke *PRJ_CANCEL_COMMAND_CB* for a given **CommandId** only after the callback to be canceled is invoked. However if the provider is configured to allow more than one concurrently running worker thread, the cancellation and original invocation may run concurrently. The provider must be able to handle this situation.

This callback is optional. If the provider does not supply an implementation of this callback, none of the other callbacks will be cancellable. The provider will process all callbacks synchronously.