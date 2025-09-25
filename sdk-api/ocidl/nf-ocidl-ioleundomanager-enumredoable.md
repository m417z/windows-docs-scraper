# IOleUndoManager::EnumRedoable

## Description

Creates an enumerator object that the caller can use to iterate through a series of top-level undo units from the redo stack.

## Parameters

### `ppEnum` [out]

Address of [IEnumOleUndoUnits](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumoleundounits) pointer variable that receives the interface pointer to the enumerator object.

## Return value

This method returns S_OK on success. Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **E_UNEXPECTED** | The undo manager is disabled. |

## Remarks

A new enumerator object is created each time this method is called. If the series of enumerated items changes over time, the results of enumeration operations can vary from one call to the next.

This method calls [IUnknown::AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the new enumerator object to increment its reference count. The caller is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the enumerator object when it is no longer needed.

## See also

[IEnumOleUndoUnits](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ienumoleundounits)

[IOleUndoManager](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleundomanager)