# IRunningObjectTable::NoteChangeTime

## Description

Records the time that a running object was last modified. The object must have previously been registered with the running object table (ROT). This method stores the time of last change in the ROT.

## Parameters

### `dwRegister` [in]

The identifier of the ROT entry of the changed object. This value was previously returned by [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register).

### `pfiletime` [in]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure containing the object's last change time.

## Return value

This method can return the standard return values E_INVALIDARG and S_OK.

## Remarks

The time recorded by this method can be retrieved by calling [IRunningObjectTable::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-gettimeoflastchange).

### Notes to Callers

A moniker provider (hands out monikers identifying its objects to make them accessible to others) must call the **NoteChangeTime** method whenever its objects are modified. It must have previously called [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register) and stored the identifier returned by that method; it uses that identifier when calling **NoteChangeTime**.

The most common type of moniker provider is a compound-document link source. This includes server applications that support linking to their documents (or portions of a document) and container applications that support linking to embeddings within their documents. Server applications that do not support linking can also use the ROT to cooperate with container applications that support linking to embeddings.

When an object is first registered in the ROT, the ROT records its last change time as the value returned by calling [IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange) on the moniker being registered.

## See also

[IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)