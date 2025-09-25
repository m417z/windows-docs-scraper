# IBindCtx::ReleaseBoundObjects

## Description

Releases all pointers to all objects that were previously registered by calls to [RegisterObjectBound](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectbound).

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You rarely call this method directly. The system's [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) implementation calls this method when the pointer to the **IBindCtx** interface on the bind context is released (the bind context is released). If a bind context is not released, all of the registered objects remain active.

If the same object has been registered more than once, this method calls the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method on the object the number of times it was registered.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)