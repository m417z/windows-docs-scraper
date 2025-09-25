# IChangeUnitException::GetClockVector

## Description

Gets the clock vector that is associated with this exception.

## Parameters

### `riid` [in]

The IID of the object to retrieve. Must be **IID_IEnumClockVector**.

### `ppUnk` [out]

Returns an object that implements *riid* and that represents the clock vector that is associated with this exception.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |

## See also

[IChangeUnitException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ichangeunitexception)

[IEnumClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-ienumclockvector)