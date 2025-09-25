# IRichEditOle::InsertObject

## Description

Inserts an object into a rich edit control.

## Parameters

### `lpreobject`

Type: **[REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject)***

The object information and interfaces. The rich edit control automatically increments the reference count for the interfaces if it holds onto them, so the caller can safely release the interfaces if they are not needed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns S_OK on success, or a failure code otherwise. E_OUTOFMEMORY is returned if memory could not be allocated to insert the object.

## Remarks

If the **cp** member of the [REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject) structure is REO_CP_SELECTION, the selection is replaced with the specified object.

## See also

[IRichEditOle](https://learn.microsoft.com/windows/desktop/api/richole/nn-richole-iricheditole)

[REOBJECT](https://learn.microsoft.com/windows/desktop/api/richole/ns-richole-reobject)

**Reference**