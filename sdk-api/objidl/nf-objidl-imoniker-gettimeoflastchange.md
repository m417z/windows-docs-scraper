# IMoniker::GetTimeOfLastChange

## Description

Retrieves the time at which the object identified by this moniker was last changed.

## Parameters

### `pbc` [in]

A pointer to the bind context to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment. For more information, see [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx).

### `pmkToLeft` [in]

If the moniker is part of a composite moniker, pointer to the moniker to the left of this moniker. This parameter is primarily used by moniker implementers to enable cooperation between the various components of a composite moniker. Moniker clients should pass **NULL**.

### `pFileTime` [out]

A pointer to the [FILETIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-filetime) structure that receives the time of last change. A value of {0xFFFFFFFF,0x7FFFFFFF} indicates an error (for example, exceeded time limit, information not available).

## Return value

This method can return the standard return values E_OUTOFMEMORY, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **MK_E_EXCEEDEDDEADLINE** | The binding operation could not be completed within the time limit specified by the bind context's [BIND_OPTS](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-bind_opts) structure. |
| **MK_E_CONNECTMANUALLY** | The operation was unable to connect to the storage for this object, possibly because a network device could not be connected to. For more information, see [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject). |
| **MK_E_UNAVAILABLE** | The time of the change is unavailable and will not be available regardless of the deadline that is used. |

## Remarks

To be precise, the time returned is the earliest time COM can identify after which no change has occurred, so this time may be later than the time of the last change to the object.

### Notes to Callers

If you're caching information returned by the object identified by the moniker, you may want to ensure that your information is up-to-date. To do so, you would call **GetTimeOfLastChange** and compare the time returned with the time you last retrieved information from the object.

For the monikers stored within linked objects, **GetTimeOfLastChange** is primarily called by the default handler's implementation of [IOleObject::IsUpToDate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleobject-isuptodate). Container applications call **IOleObject::IsUpToDate** to determine if a linked object (or an embedded object containing linked objects) is up-to-date without actually binding to the object. This enables an application to determine quickly which linked objects require updating when the end user opens a document. The application can then bind only those linked objects that need updating (after prompting the end user to determine whether they should be updated) instead of binding every linked object in the document.

### Notes to Implementers

It is important to perform this operation quickly because, for linked objects, this method is called when a user first opens a compound document. Consequently, your **GetTimeOfLastChange** implementation should not bind to any objects. In addition, your implementation should check the deadline parameter in the bind context and return MK_E_EXCEEDEDDEADLINE if the operation cannot be completed by the specified time.

Following are some strategies you can use in your implementations:

* For many types of monikers, the pmkToLeft parameter identifies the container of the object identified by this moniker. If this is true of your moniker class, you can simply call **GetTimeOfLastChange** on the *pmkToLeft* parameter, because an object cannot have changed at a date later than its container.
* You can get a pointer to the running object table (ROT) by calling [IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable) on the *pbc* parameter and then calling [IRunningObjectTable::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-gettimeoflastchange), because the ROT generally records the time of last change.
* You can get the storage associated with this moniker (or the *pmkToLeft* moniker) and return the storage's last modification time with a call to [IStorage::Stat](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-stat).

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method returns E_NOTIMPL. |
| Class moniker | This method returns MK_E_UNAVAILABLE. |
| File moniker | If this moniker is in the ROT, this method returns the last change time registered there; otherwise, it returns the last write time for the file. If the file cannot be found, this method returns MK_E_NOOBJECT. |
| Generic composite moniker | This method creates a composite of *pmkToLeft* (if non-**NULL**) and this moniker and uses the ROT to retrieve the time of last change. If the object is not in the ROT, the method recursively calls **GetTimeOfLastChange** on the rightmost component of the composite, passing the remainder of the composite as the *pmkToLeft* parameter for that call. |
| Item moniker | If *pmkToLeft* is **NULL**, this method returns MK_E_NOTBINDABLE. Otherwise, the method creates a composite of *pmkToLeft* and this moniker and uses the ROT to access the time of last change. If the object is not in the ROT, the method calls **GetTimeOfLastChange** on the *pmkToLeft* parameter. |
| OBJREF moniker | This method returns E_NOTIMPL. |
| Pointer moniker | This method returns E_NOTIMPL. |
| URL moniker | This method returns the time of last change of an object that is registered in the ROT. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IRunningObjectTable::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-gettimeoflastchange)