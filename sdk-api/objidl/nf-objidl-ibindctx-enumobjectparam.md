# IBindCtx::EnumObjectParam

## Description

Retrieves a pointer to an interface that can be used to enumerate the keys of the bind context's string-keyed table of pointers.

## Parameters

### `ppenum` [out]

The address of an [IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)* pointer variable that receives the interface pointer to the enumerator. If an error occurs, **ppenum* is set to **NULL**. If **ppenum* is non-**NULL**, the implementation calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on **ppenum*; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

The keys returned by the enumerator are the ones previously specified in calls to [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam).

### Notes to Callers

A bind context maintains a table of interface pointers, each associated with a string key. This enables communication between a moniker implementation and the caller that initiated the binding operation. One party can store an interface pointer under a string known to both parties so that the other party can later retrieve it from the bind context.

In the system implementation of the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface, this method is not implemented. Therefore, calling this method results in a return value of E_NOTIMPL.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IEnumString](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienumstring)