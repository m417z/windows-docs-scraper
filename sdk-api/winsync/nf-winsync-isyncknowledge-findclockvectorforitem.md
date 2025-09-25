# ISyncKnowledge::FindClockVectorForItem

## Description

Gets the clock vector that is associated with the specified item ID.

## Parameters

### `pbItemId` [in]

The ID of the item that is associated with the clock vector to find.

### `riid` [in]

The IID of the object to retrieve. Must be **IID_IFeedClockVector** or **IID_IClockVector**.

### `ppUnk` [out]

Returns an object that implements *riid* and that represents the clock vector associated with *pbItemId*.

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