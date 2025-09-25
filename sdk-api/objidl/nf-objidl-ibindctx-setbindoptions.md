# IBindCtx::SetBindOptions

## Description

Sets new values for the binding parameters stored in the bind context.

## Parameters

### `pbindopts` [in]

A pointer to a [BIND_OPTS3](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts3-r1) structure containing the binding parameters.

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

A bind context contains a block of parameters that are common to most [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) operations. These parameters do not change as the operation moves from piece to piece of a composite moniker.

Subsequent binding operations can call [IBindCtx::GetBindOptions](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getbindoptions) to retrieve these parameters.

### Notes to Callers

This method can be called by moniker clients (those who use monikers to acquire interface pointers to objects).

When you first create a bind context by using the [CreateBindCtx](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-createbindctx) function, the fields of the [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure are initialized to the following values:

``` syntax
    cbStruct = sizeof(BIND_OPTS);
    grfFlags = 0;
    grfMode = STGM_READWRITE;
    dwTickCountDeadline = 0;

```

You can use the **IBindCtx::SetBindOptions** method to modify these values before using the bind context, if you want values other than the defaults.

**SetBindOptions** copies the members of the specified structure, but not the [COSERVERINFO](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-coserverinfo) structure and the pointers it contains. Callers may not free these pointers until the bind context is released.

## See also

[BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts)

[BIND_OPTS2](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts2-r1)

[BIND_OPTS3](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts3-r1)

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)