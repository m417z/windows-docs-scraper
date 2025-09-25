# ISyncMgrEnumItems::Clone

## Description

Creates another items enumerator with the same state as the current enumerator to iterate over the same list. This method makes it possible to record a point in the enumeration sequence in order to return to that point at a later time.

## Parameters

### `ppenum` [out]

Type: **ppenum****

The address of a variable that receives the [ISyncMgrEnumItems](https://learn.microsoft.com/windows/desktop/api/mobsync/nn-mobsync-isyncmgrenumitems) interface pointer.

## Return value

Type: **HRESULT**

Return S_OK if the method succeeds.

## Remarks

The calling application must release the new enumerator separately from the first enumerator.