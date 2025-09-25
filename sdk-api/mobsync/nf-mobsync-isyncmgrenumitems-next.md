# ISyncMgrEnumItems::Next

## Description

Enumerates the next *celt* elements in the enumerator's list, returning them in *rgelt* along with the actual number of enumerated elements in *pceltFetched*.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of items in the array.

### `rgelt` [out]

Type: **[SYNCMGRITEM](https://learn.microsoft.com/windows/desktop/api/mobsync/ns-mobsync-syncmgritem)***

The address of array containing items.

### `pceltFetched` [out]

Type: **ULONG***

The address of variable containing actual number of items.

## Return value

Type: **HRESULT**

Return S_OK if the method succeeds.

## Remarks

E_NOTIMPL is not allowed as a return value. If an error value is returned, no entries in the *rgelt* array are valid on exit and require no release.