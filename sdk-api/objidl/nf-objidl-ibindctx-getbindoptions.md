# IBindCtx::GetBindOptions

## Description

Retrieves the binding options stored in this bind context.

## Parameters

### `pbindopts` [in, out]

A pointer to an initialized structure that receives the current binding parameters on return. See [BIND_OPTS3](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts3-r1).

## Return value

This method can return the standard return values E_UNEXPECTED and S_OK.

## Remarks

A bind context contains a block of parameters that are common to most [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) operations and that do not change as the operation moves from piece to piece of a composite moniker.

### Notes to Callers

You typically call this method if you are writing your own moniker class. (This requires that you implement the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface.) You call this method to retrieve the parameters specified by the moniker client.

You must initialize the structure that is filled in by this method. Before calling this method, you must initialize the **cbStruct** member to the size of the structure.

## See also

[BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts)

[BIND_OPTS2](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts2-r1)

[BIND_OPTS3](https://learn.microsoft.com/windows/win32/api/objidl/ns-objidl-bind_opts3-r1)

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)