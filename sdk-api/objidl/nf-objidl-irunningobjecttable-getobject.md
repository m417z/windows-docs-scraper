# IRunningObjectTable::GetObject

## Description

Determines whether the object identified by the specified moniker is running, and if it is, retrieves a pointer to that object.

## Parameters

### `pmkObjectName` [in]

A pointer to the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface on the moniker.

### `ppunkObject` [out]

A pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer variable that receives the interface pointer to the running object. When successful, the implementation calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the object; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If the object is not running or if an error occurs, the implementation sets **ppunkObject* to **NULL**.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | Indicates that *pmkObjectName* was found in the ROT and a pointer was retrieved. |
| **S_FALSE** | There is no entry for *pmkObjectName* in the ROT, or that the object it identifies is no longer running (in which case, the entry is revoked). |

## Remarks

This method checks the ROT for the moniker specified by *pmkObjectName*. If that moniker had previously been registered with a call to [IRunningObjectTable::Register](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-irunningobjecttable-register), this method returns the pointer that was registered at that time.

### Notes to Callers

Generally, you call the **IRunningObjectTable::GetObject** method only if you are writing your own moniker class (that is, implementing the [IMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-imoniker) interface). You typically call this method from your implementation of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject).

However, note that not all implementations of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject) need to call this method. If you expect your moniker to have a prefix (indicated by a non-**NULL***pmkToLeft* parameter to **IMoniker::BindToObject**), you should not check the ROT. The reason for this is that only complete monikers are registered with the ROT, and if your moniker has a prefix, your moniker is part of a composite and thus not complete. Instead, your moniker should request services from the object identified by the prefix (for example, the container of the object identified by your moniker).

## See also

[IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)