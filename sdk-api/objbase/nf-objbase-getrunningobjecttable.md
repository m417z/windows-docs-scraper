# GetRunningObjectTable function

## Description

Returns a pointer to the [IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable) interface on the local running object table (ROT).

## Parameters

### `reserved` [in]

This parameter is reserved and must be 0.

### `pprot` [out]

The address of an [IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)* pointer variable that receives the interface pointer to the local ROT. When the function is successful, the caller is responsible for calling [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the interface pointer. If an error occurs, **pprot* is undefined.

## Return value

This function can return the standard return values E_UNEXPECTED and S_OK.

## Remarks

Each workstation has a local ROT that maintains a table of the objects that have been registered as running on that computer. This function returns an [IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable) interface pointer, which provides access to that table.

Moniker providers, which hand out monikers that identify objects so they are accessible to others, should call **GetRunningObjectTable**. Use the interface pointer returned by this function to register your objects when they begin running, to record the times that those objects are modified, and to revoke their registrations when they stop running. See the [IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable) interface for more information.

Compound-document link sources are the most common example of moniker providers. These include server applications that support linking to their documents (or portions of a document) and container applications that support linking to embeddings within their documents. Server applications that do not support linking can also use the ROT to cooperate with container applications that support linking to embeddings.

If you are implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface to write a new moniker class, and you need an interface pointer to the ROT, call [IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable) rather than the **GetRunningObjectTable** function. This allows future implementations of the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface to modify binding behavior.

## See also

[IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)