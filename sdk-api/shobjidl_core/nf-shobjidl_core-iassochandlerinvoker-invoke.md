# IAssocHandlerInvoker::Invoke

## Description

Invokes an associated application handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

There is no guarantee that a given association handler will support a particular selection, especially if multiple items are selected. Before attempting to invoke the selection via this method, it is recommended to call [IAssocHandlerInvoker::SupportsSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandlerinvoker-supportsselection).