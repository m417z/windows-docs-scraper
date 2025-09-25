# IBindCtx::GetObjectParam

## Description

Retrieves an interface pointer to the object associated with the specified key in the bind context's string-keyed table of pointers.

## Parameters

### `pszKey` [in]

The [bind context string key](https://learn.microsoft.com/windows/desktop/shell/str-constants) to be searched for. Key string comparison is case-sensitive.

### `ppunk` [out]

The address of an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)* pointer variable that receives the interface pointer to the object associated with *pszKey*. When successful, the implementation calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on **ppunk*. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs, the implementation sets **ppunk* to **NULL**.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, it is E_FAIL.

## Remarks

A bind context maintains a table of interface pointers, each associated with a string key. This enables communication between a moniker implementation and the caller that initiated the binding operation. One party can store an interface pointer under a string known to both parties so that the other party can later retrieve it from the bind context.

The pointer this method retrieves must have previously been inserted into the table using the [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam) method.

### Notes to Callers

Objects using monikers to locate other objects can call this method when a binding operation fails to get specific information about the error that occurred. Depending on the error, it may be possible to correct the situation and retry the binding operation. See [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam) for more information.

Moniker implementations can call this method to handle situations where a caller initiates a binding operation and requests specific information. By convention, the implementer should use key names that begin with the string form of the CLSID of a moniker class. (See the [StringFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromclsid) function.)

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)