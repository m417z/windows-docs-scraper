# ISyncKnowledge::GetRangeExceptions

## Description

Gets an object that can enumerate the **IRangeException** objects that are stored in the knowledge.

## Parameters

### `riid` [in]

The IID of the object to retrieve. Must be **IID_IEnumRangeExceptions**.

### `ppUnk` [out]

Returns an object that implements *riid* and that can enumerate the list of **IRangeException** objects that is contained in the knowledge.

## Return value

The possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_INVALIDARG** |  |
| **E_NOINTERFACE** |  |
| **E_OUTOFMEMORY** |  |

## Remarks

Be aware that there is no single representation of knowledge. Equivalent knowledge might be represented in different forms and return different values from **GetRangeExceptions**.

## See also

[IRangeException Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-irangeexception)

[ISyncKnowledge Interface](https://learn.microsoft.com/previous-versions/windows/desktop/api/winsync/nn-winsync-isyncknowledge)