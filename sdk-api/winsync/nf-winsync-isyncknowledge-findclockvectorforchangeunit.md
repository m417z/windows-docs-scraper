# ISyncKnowledge::FindClockVectorForChangeUnit

## Description

Gets the clock vector that is associated with the specified change unit ID.

## Parameters

### `pbItemId` [in]

The ID of the item that contains the change unit that is associated with the clock vector to retrieve.

### `pbChangeUnitId` [in]

The ID of the change unit that is associated with the clock vector to retrieve.

### `riid` [in]

The IID of the object to retrieve. Must be **IID_IEnumClockVector**.

### `ppUnk` [out]

Returns an object that implements *riid* and that can enumerate the list of [IClockVector](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iclockvector) objects that is associated with *pbChangeUnitId*.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_NOINTERFACE** |  |
| **E_OUTOFMEMORY** |  |

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)