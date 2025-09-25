# IClockVector::GetClockVectorElements

## Description

Returns an enumerator that iterates through the clock vector elements.

## Parameters

### `riid` [in]

The IID of the enumeration interface that is requested. Must be either **IID_IEnumClockVector** or **IID_IEnumFeedClockVector**.

### `ppiEnumClockVector` [out]

Returns an object that implements *riid* and that can enumerate the clock vector elements.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | Invalid pointer. |
| **E_OUTOFMEMORY** |  |
| **E_NOINTERFACE** | *riid* is not **IID_IEnumClockVector** or **IID_IEnumFeedClockVector**. |

## See also

[IClockVector Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-iclockvector)