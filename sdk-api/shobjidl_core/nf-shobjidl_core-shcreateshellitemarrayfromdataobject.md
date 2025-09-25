# SHCreateShellItemArrayFromDataObject function

## Description

Creates a Shell item array object from a data object.

## Parameters

### `pdo` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) interface.

### `riid` [in]

Type: **REFIID**

A reference to the desired interface ID.

### `ppv` [out]

Type: **void****

When this method returns, contains the interface pointer requested in *riid*. This is typically [IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray).

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function is useful for Shell extensions that implement [IShellExtInit](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellextinit) and are passed a data object to the [IShellExtInit::Initialize](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ishellextinit-initialize) method; for example, context menu handlers.

This API lets you convert the data object into a Shell item that the handler can consume. It is recommend that handlers use a Shell item array rather than clipboard formats like **CF_HDROP** and **CFSTR_SHELLIDLIST** (also known as HIDA) as it leads to simpler code and allows some performance improvements.

The resulting shell item array holds a reference to the source data object. Therefore, that data object must remain valid for the lifetime of the shell item array. Notably, the data objects passed to [IDropTarget](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-idroptarget) methods are no longer valid after the drop operation completes.