# ISyncKnowledge::GetScopeVector

## Description

Gets the clock vector that defines the changes that are contained in the knowledge.

## Parameters

### `riid` [in]

The IID of the object to retrieve. Must be **IID_IClockVector**.

### `ppUnk` [out]

Returns an object that implements *riid* and that represents the clock vector that defines the changes that are contained in the knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_NOINTERFACE** |  |
| **E_OUTOFMEMORY** |  |

## Remarks

Be aware that there is no single representation of knowledge. Equivalent knowledge might be represented in different forms and return different values from **GetScopeVector**.

## See also

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)