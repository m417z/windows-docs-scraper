# IBindCtx::RegisterObjectParam

## Description

Associates an object with a string key in the bind context's string-keyed table of pointers.

## Parameters

### `pszKey` [in]

The [bind context string key](https://learn.microsoft.com/windows/desktop/shell/str-constants) under which the object is being registered. Key string comparison is case-sensitive.

### `punk` [in]

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface on the object that is to be registered.

The method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer.

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

A bind context maintains a table of interface pointers, each associated with a string key. This enables communication between a moniker implementation and the caller that initiated the binding operation. One party can store an interface pointer under a string known to both parties so that the other party can later retrieve it from the bind context.

Binding operations subsequent to the use of this method can use [IBindCtx::GetObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getobjectparam) to retrieve the stored pointer.

### Notes to Callers

**RegisterObjectParam** is useful to those implementing a new moniker class (through an implementation of [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)) and to moniker clients (those who use monikers to bind to objects).

In implementing a new moniker class, you call this method when an error occurs during moniker binding to inform the caller of the cause of the error. The key that you would obtain with a call to this method would depend on the error condition. Following is a list of common moniker binding errors, describing for each the keys that would be appropriate:

* MK_E_EXCEEDEDDEADLINE: If a binding operation exceeds its deadline because a given object is not running, you should register the object's moniker using the first unused key from the list: "ExceededDeadline", "ExceededDeadline1", "ExceededDeadline2", and so on. If the caller later finds the moniker in the running object table, the caller can retry the binding operation.
* MK_E_CONNECTMANUALLY: The "ConnectManually" key indicates a moniker whose binding requires assistance from the end user. To request that the end user manually connect to the object, the caller can retry the binding operation after showing the moniker's display name. Common reasons for this error are that a password is needed or that a floppy needs to be mounted.
* E_CLASSNOTFOUND: The "ClassNotFound" key indicates a moniker whose class could not be found. (The server for the object identified by this moniker could not be located.) If this key is used for an OLE compound-document object, the caller can use [IMoniker::BindToStorage](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtostorage) to bind to the object and then try to carry out a **Treat As...** or **Convert To...** operation to associate the object with a different server. If this is successful, the caller can retry the binding operation.

A moniker client with detailed knowledge of the implementation of the moniker can also call this method to pass private information to that implementation.

You can define new strings as keys for storing pointers. By convention, you should use key names that begin with the string form of the CLSID of the moniker class. (See the [StringFromCLSID](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-stringfromclsid) function.)

If the *pszKey* parameter matches the name of an existing key in the bind context's table, the new object replaces the existing object in the table.

When you register an object using this method, the object is not released until one of the following occurs:

* It is replaced in the table by another object with the same key.
* It is removed from the table by a call to [IBindCtx::RevokeObjectParam](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-revokeobjectparam).
* The bind context is released. All registered objects are released when the bind context is released.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)