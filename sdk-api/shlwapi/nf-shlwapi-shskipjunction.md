# SHSkipJunction function

## Description

Checks a bind context to see if it is safe to bind to a particular component object.

## Parameters

### `pbc` [in, optional]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface that specifies the bind context you want to check. This value can be **NULL**.

### `pclsid` [in]

Type: **const CLSID***

A pointer to a variable that specifies the **CLSID** of the object being tested to see if it must be skipped. Typically, this is the CLSID of the object that [IShellFolder::BindToObject](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellfolder-bindtoobject) is about to create.

## Return value

Type: **BOOL**

Returns **TRUE** if the object specified by *pclsid* must be skipped, or **FALSE** otherwise.

## Remarks

This function can be used to avoid infinite cycles in namespace binding. For example, a folder shortcut that refers to a folder above it in the namespace tree can produce an infinitely recursive loop.