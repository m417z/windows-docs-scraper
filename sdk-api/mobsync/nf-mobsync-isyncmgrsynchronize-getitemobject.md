# ISyncMgrSynchronize::GetItemObject

## Description

Obtains an interface on a specified item that a registered application handles.

## Parameters

### `ItemID` [in]

Type: **REFGUID**

An identifier for a requested item.

### `riid` [in]

Type: **REFIID**

An identifier for a requested interface.

### `ppv` [out]

Type: **void****

An address of a variable that receives a pointer to a requested interface.

## Return value

Type: **HRESULT**

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **E_NOTIMPL** | The requested interface is not found. |

## Remarks

This method exists only for forward compatibility. Currently, there are no interfaces defined on an item. Application implementers must return E_NOTIMPL from this method.

## See also

[ISyncMgrSynchronize](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrsynchronize)