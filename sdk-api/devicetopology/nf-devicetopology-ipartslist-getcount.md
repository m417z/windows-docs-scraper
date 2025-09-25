# IPartsList::GetCount

## Description

The **GetCount** method gets the number of parts in the parts list.

## Parameters

### `pCount` [out]

Pointer to a **UINT** variable into which the method writes the parts count (the number of parts in the parts list).

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_POINTER** | Pointer *pCount* is **NULL**. |

## See also

[IPartsList Interface](https://learn.microsoft.com/windows/desktop/api/devicetopology/nn-devicetopology-ipartslist)