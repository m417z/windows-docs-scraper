# ITocEntryList::AddEntryByIndex

## Description

The **AddEntryByIndex** method adds an individual entry to the list and associates a caller-supplied index with the entry.

## Parameters

### `dwEntryIndex` [in]

The index of the entry to be added.

### `pEntry` [in]

Pointer to an [ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry) interface that represents the entry to be added.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[GetEntryByIndex](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentrylist-getentrybyindex)

[ITocEntryList](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentrylist)