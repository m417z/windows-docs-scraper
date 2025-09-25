# IShellFolder::BindToObject

## Description

Retrieves a handler, typically the Shell folder object that implements [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) for a particular item. Optional parameters that control the construction of the handler are passed in the bind context.

## Parameters

### `pidl` [in]

Type: **PCUIDLIST_RELATIVE**

The address of an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist) structure (PIDL) that identifies the subfolder. This value can refer to an item at any level below the parent folder in the namespace hierarchy. The structure contains one or more [SHITEMID](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-shitemid) structures, followed by a terminating **NULL**.

### `pbc` [in]

Type: **[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)***

A pointer to an [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on a bind context object that can be used to pass parameters to the construction of the handler. If this parameter is not used, set it to **NULL**. Because support for this parameter is optional for folder object implementations, some folders may not support the use of bind contexts.

Information that can be provided in the bind context includes a [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure that includes a **grfMode** member that indicates the access mode when binding to a stream handler. Other parameters can be set and discovered using [IBindCtx::RegisterObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-registerobjectparam) and [IBindCtx::GetObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getobjectparam).

### `riid` [in]

Type: **REFIID**

The identifier of the interface to return. This may be **IID_IShellFolder**, **IID_IStream**, or any other interface that identifies a particular handler.

### `ppv` [out]

Type: **void****

When this method returns, contains the address of a pointer to the requested interface. If an error occurs, a **NULL** pointer is returned at this address.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Applications use **IShellFolder::BindToObject****(..., IID_IShellFolder, ...)** to obtain the Shell folder object for a subitem. Clients should pass the canonical interface IID that is used to identify a specific handler. For example, **IID_IShellFolder** identifies the folder handler and **IID_IStream** identifies the stream handler. Implementations can support binding to handlers using derived interfaces as well, such as **IID_IShellFolder2**. A Shell namespace extension can implement this function by creating the Shell folder object for the specified subitem and then calling [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) to communicate with the object through its interface pointer.

Implementations of **BindToObject** can optimize any call to it by quickly failing for IID values that it does not support. For example, if the Shell folder object of the subitem does not support [IRemoteComputer](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iremotecomputer), the implementation should return **E_NOINTERFACE** immediately instead of needlessly creating the Shell folder object for the subitem and then finding that **IRemoteComputer** was not supported after all.

## See also

[IPersistFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder)

[IPersistFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ipersistfolder2)

[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)

[IShellFolder2](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder2)

[SHGetDesktopFolder](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetdesktopfolder)