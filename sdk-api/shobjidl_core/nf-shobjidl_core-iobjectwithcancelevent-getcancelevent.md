# IObjectWithCancelEvent::GetCancelEvent

## Description

Retrieves an event that will be sent when an operation is canceled.

## Parameters

### `phEvent` [out]

Type: **HANDLE***

Pointer to a handle that, when this method successfully returns, is the handle to the cancel event. The caller is responsible for closing this handle when it is no longer needed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Call this function to retrieve an event that will be signaled when the called object cancels the operation it is performing. The caller is responsible for closing the returned handle.

## See also

[IObjectWithCancelEvent](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iobjectwithcancelevent)