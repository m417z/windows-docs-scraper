# IBindCtx::GetRunningObjectTable

## Description

Retrieves an interface pointer to the running object table (ROT) for the computer on which this bind context is running.

## Parameters

### `pprot` [out]

The address of a [IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)* pointer variable that receives the interface pointer to the running object table. If an error occurs, **pprot* is set to **NULL**. If **pprot* is non-**NULL**, the implementation calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the running table object; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release).

## Return value

This method can return the standard return values E_OUTOFMEMORY, E_UNEXPECTED, and S_OK.

## Remarks

The running object table is a globally accessible table on each computer. It keeps track of all the objects that are currently running on the computer.

### Notes to Callers

Typically, those implementing a new moniker class (through an implementation of [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface) call **GetRunningObjectTable**. It is useful to call this method in an implementation of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) or [IMoniker::IsRunning](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-isrunning) to check whether an object is currently running. You can also call this method in the implementation of [IMoniker::GetTimeOfLastChange](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-gettimeoflastchange) to learn when a running object was last modified.

Moniker implementations should call this method instead of using the **GetRunningObjectTable** function. This makes it possible for future implementations of [IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx) to modify binding behavior.

## See also

[IBindCtx](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ibindctx)

[IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)