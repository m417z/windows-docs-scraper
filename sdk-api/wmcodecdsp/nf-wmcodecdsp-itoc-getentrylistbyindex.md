# IToc::GetEntryListByIndex

## Description

The **GetEntryListByIndex** method retrieves an entry list, specified by an index, from the table of contents.

## Parameters

### `wEntryListIndex` [in]

The index of the entry list to retrieve.

### `ppEntryList` [out]

Pointer to a variable that receives a pointer to an [ITocEntryList](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentrylist) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)