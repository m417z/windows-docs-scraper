# IToc::AddEntryListByIndex

## Description

The **AddEntryListByIndex** method adds an entry list to the table of contents and associates a caller-supplied index with the entry list.

## Parameters

### `wEntryListIndex` [in]

The index, specified by the caller, to be associated with the entry list.

### `pEntryList` [in]

Pointer to an [ITocEntryList](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentrylist) interface that represents the entry list to be added.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[IToc](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itoc)