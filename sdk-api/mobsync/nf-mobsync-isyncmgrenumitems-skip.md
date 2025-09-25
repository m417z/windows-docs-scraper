# ISyncMgrEnumItems::Skip

## Description

Instructs the enumerator to skip the next *celt* elements in the enumeration so that the next call to [ISyncMgrEnumItems::Next](https://learn.microsoft.com/windows/desktop/api/mobsync/nf-mobsync-isyncmgrenumitems-next) does not return those elements.

## Parameters

### `celt` [in]

Type: **ULONG**

The number of items to skip.

## Return value

Type: **HRESULT**

Return S_OK if the method succeeds.