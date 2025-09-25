# CreateBindCtx function

## Description

Returns a pointer to an implementation of [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) (a bind context object). This object stores information about a particular moniker-binding operation.

## Parameters

### `reserved` [in]

This parameter is reserved and must be 0.

### `ppbc` [out]

Address of an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)* pointer variable that receives the interface pointer to the new bind context object. When the function is successful, the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the bind context. A **NULL** value for the bind context indicates that an error occurred.

## Return value

This function can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

**CreateBindCtx** is most commonly used in the process of binding a moniker (locating and getting a pointer to an interface by identifying it through a moniker), as in the following steps:

1. Get a pointer to a bind context by calling the **CreateBindCtx** function.
2. Call the [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) method on the moniker, retrieving an interface pointer to the object to which the moniker refers.
3. Release the bind context.
4. Use the interface pointer.
5. Release the interface pointer.

The following code fragment illustrates these steps.

``` syntax
// pMnk is an IMoniker * that points to a previously acquired moniker
IInterface *pInterface;
IBindCtx *pbc;

CreateBindCtx( 0, &pbc );
pMnk->BindToObject( pbc, NULL, IID_IInterface, &pInterface );
pbc->Release();

// pInterface now points to the object; safe to use pInterface
pInterface->Release();
```

Bind contexts are also used in other methods of the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface besides [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) and in the [MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname) function.

A bind context retains references to the objects that are bound during the binding operation, causing the bound objects to remain active (keeping the object's server running) until the bind context is released. Reusing a bind context when subsequent operations bind to the same object can improve performance. You should, however, release the bind context as soon as possible, because you could be keeping the objects activated unnecessarily.

A bind context contains a [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure, which contains parameters that apply to all steps in a binding operation. When you create a bind context using **CreateBindCtx**, the fields of the **BIND_OPTS** structure are initialized as follows.

``` syntax
cbStruct = sizeof(BIND_OPTS)
grfFlags = 0
grfMode = STGM_READWRITE
dwTickCountDeadline = 0
```

You can call the [IBindCtx::SetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-setbindoptions) method to modify these default values.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[MkParseDisplayName](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-mkparsedisplayname)