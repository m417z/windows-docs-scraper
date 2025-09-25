# IRunningObjectTable::GetTimeOfLastChange

## Description

Retrieves the time that an object was last modified.

## Parameters

### `pmkObjectName` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker.

### `pfiletime` [out]

A pointer to a [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the object's last change time.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **S_FALSE** | There is no entry for *pmkObjectName* in the ROT, or that the object it identifies is no longer running (in which case, the entry is revoked). |

## Remarks

This method returns the change time that was last reported for this object by a call to [IRunningObjectTable::NoteChangeTime](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-notechangetime). If **NoteChangeTime** has not been called previously, the method returns the time that was recorded when the object was registered.

This method is provided to enable checking whether a connection between two objects (represented by one object holding a moniker that identifies the other) is up-to-date. For example, if one object is holding cached information about the other object, this method can be used to check whether the object has been modified since the cache was last updated. See [IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange).

### Notes to Callers

Generally, you call **GetTimeOfLastChange** only if you are writing your own moniker class (that is, implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface). You typically call this method from your implementation of [IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange). However, you should do so only if the *pmkToLeft* parameter of **IMoniker::GetTimeOfLastChange** is **NULL**. Otherwise, you should call **IMoniker::GetTimeOfLastChange** on your *pmkToLeft* parameter instead.

## See also

[IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)