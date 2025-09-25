# IRunningObjectTable::Revoke

## Description

Removes an entry from the running object table (ROT) that was previously registered by a call to [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register).

## Parameters

### `dwRegister` [in]

The identifier of the ROT entry to be revoked.

## Return value

This method can return the standard return values E_INVALIDARG and S_OK.

## Remarks

This method undoes the effect of a call to [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register), removing both the moniker and the pointer to the object identified by that moniker.

### Notes to Callers

A moniker provider (hands out monikers identifying its objects to make them accessible to others) must call the **Revoke** method to revoke the registration of its objects when it stops running. It must have previously called [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register) and stored the identifier returned by that method; it uses that identifier when calling **Revoke**.

The most common type of moniker provider is a compound-document link source. This includes server applications that support linking to their documents (or portions of a document) and container applications that support linking to embeddings within their documents. Server applications that do not support linking can also use the ROT to cooperate with container applications that support linking to embeddings.

If you are writing a container application, you must revoke a document's registration when the document is closed. You must also revoke a document's registration before re-registering it when it is renamed.

If you are writing a server application, you must revoke an object's registration when the object is closed. You must also revoke an object's registration before re-registering it when its container document is renamed (see [IOleObject::SetMoniker](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-setmoniker)).

## See also

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)