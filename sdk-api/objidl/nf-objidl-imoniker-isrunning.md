# IMoniker::IsRunning

## Description

Determines whether the object identified by this moniker is currently loaded and running.

## Parameters

### `pbc` [in]

A pointer to the [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) interface on the bind context to be used in this binding operation. The bind context caches objects bound during the binding process, contains parameters that apply to all operations using the bind context, and provides the means by which the moniker implementation should retrieve information about its environment.

### `pmkToLeft` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker to the left of this moniker if this moniker is part of a composite. This parameter is used primarily by moniker implementers to enable cooperation between the various components of a composite moniker; moniker clients can usually pass **NULL**.

### `pmkNewlyRunning` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker most recently added to the running object table (ROT). This can be **NULL**. If non-**NULL**, the implementation can return the results of calling [IMoniker::IsEqual](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isequal) on the *pmkNewlyRunning* parameter, passing the current moniker. This parameter is intended to enable **IsRunning** implementations that are more efficient than just searching the ROT, but the implementation can choose to ignore *pmkNewlyRunning* without causing any harm.

## Return value

This method can return the standard return values E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The moniker is running. |
| **S_FALSE** | The moniker is not running. |

## Remarks

### Notes to Callers

If speed is important when you're requesting services from the object identified by the moniker, you may want those services only if the object is already running (because loading an object into the running state may be time-consuming). In such a situation, you should call **IsRunning** to determine whether the object is running.

For the monikers stored within linked objects, **IsRunning** is primarily called by the default handler's implementation of [IOleLink::BindIfRunning](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindifrunning).

### Notes to Implementers

To get a pointer to the ROT, your implementation should call [IBindCtx::GetRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-ibindctx-getrunningobjecttable) on the *pbc* parameter. Your implementation can then call [IRunningObjectTable::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-isrunning) to determine whether the object identified by the moniker is running. The object identified by the moniker must have registered itself with the ROT when it first began running.

### Implementation-specific Notes

| Implementation | Notes |
| --- | --- |
| Anti-moniker | This method checks the ROT to see whether the object is running. |
| Class moniker | This method returns E_NOTIMPL. |
| File moniker | If *pmkNewlyRunning* is non-**NULL**, this method returns **TRUE** if that moniker is equal to this moniker. Otherwise, the method asks the ROT whether this moniker is running. The method ignores *pmkToLeft*. |
| Generic composite moniker | If *pmkToLeft* is non-**NULL**, this method composes *pmkToLeft* with this moniker and calls **IsRunning** on the result.<br><br>If *pmkToLeft* is **NULL**, this method returns **TRUE** if pmkNewlyRunning is non-**NULL** and is equal to this moniker.<br><br>If *pmkToLeft* and *pmkNewlyRunning* are both **NULL**, this method checks the ROT to see whether the moniker is running. If so, the method returns S_OK; otherwise, it recursively calls **IsRunning** on the rightmost component of the composite, passing the remainder of the composite as the *pmkToLeft* parameter for that call. This handles the case where the moniker identifies a pseudo-object that is not registered as running; see the item moniker implementation for more details. |
| Item moniker | If pmkToLeft is **NULL**, this method returns **TRUE** if *pmkNewlyRunning* is non-**NULL** and is equal to this moniker. Otherwise, the method checks the ROT to see whether this moniker is running.<br><br>If pmkToLeft is non-**NULL**, the method calls [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) on the *pmkToLeft* parameter, requesting an [IOleItemContainer](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-ioleitemcontainer) interface pointer. The method then calls [IOleItemContainer::IsRunning](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleitemcontainer-isrunning), passing the string contained within this moniker. |
| OBJREF moniker | Because OBJREF monikers represent a running object instance, this method returns **TRUE** unless the object is known to be no longer running because a recent call failed. The method ignores *pmkToLeft*. |
| Pointer moniker | This method always returns S_OK, because the object identified by a pointer moniker must always be running. |
| URL moniker | Returns S_OK if this moniker is currently running. Otherwise, it returns S_FALSE. The URL moniker determines whether it is running by first checking whether it is equal to the newly running moniker, by making the following call: pmkNewlyRunning->IsEqual. Typically, this call is an inexpensive operation. If this does not succeed, the moniker next checks to see whether it is registered with the ROT of the passed-in bind context. |

## See also

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IOleLink::BindIfRunning](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolelink-bindifrunning)

[IRunningObjectTable::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-isrunning)