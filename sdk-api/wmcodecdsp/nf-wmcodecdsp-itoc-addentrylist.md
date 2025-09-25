# IToc::AddEntryList

## Description

The **AddEntryList** method adds an entry list to the table of contents and assigns an index to the entry list.

## Parameters

### `pEntryList` [in]

Pointer to an [ITocEntryList](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentrylist) interface that represents the entry list to be added.

### `pwEntryListIndex` [out]

Receives the index of the added entry list.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)

[RemoveEntryListByIndex](https://learn.microsoft.com/previous-versions/ee264287(v=vs.85))