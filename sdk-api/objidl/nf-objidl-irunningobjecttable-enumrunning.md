# IRunningObjectTable::EnumRunning

## Description

Creates and returns a pointer to an enumerator that can list the monikers of all the objects currently registered in the running object table (ROT).

## Parameters

### `ppenumMoniker` [out]

A pointer to an [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) pointer variable that receives the interface pointer to the new enumerator for the ROT. When successful, the implementation calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the enumerator; it is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release). If an error occurs; the implementation sets **ppenumMoniker* to **NULL**.

## Return value

This method can return the standard return values E_OUTOFMEMORY and S_OK.

## Remarks

**IRunningObjectTable::EnumRunning** must create and return a pointer to an [IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker) interface on an enumerator object. The standard enumerator methods can then be called to enumerate the monikers currently registered in the registry. The enumerator cannot be used to enumerate monikers that are registered in the ROT after the enumerator has been created.

The **EnumRunning** method is intended primarily for the use by the system in implementing the alert object table. Note that OLE 2 does not include an implementation of the alert object table.

## See also

[IEnumMoniker](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ienummoniker)

[IRunningObjectTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-irunningobjecttable)