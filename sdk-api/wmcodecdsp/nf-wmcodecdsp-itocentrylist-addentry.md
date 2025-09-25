# ITocEntryList::AddEntry

## Description

The **AddEntry** method adds an individual entry to the list and assigns an index to the entry.

## Parameters

### `pEntry` [in]

Pointer to an [ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry) interface that represents the entry to be added.

### `pdwEntryIndex` [out]

Pointer to a **DWORD** that receives the index of the added entry.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[GetEntryByIndex](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentrylist-getentrybyindex)

[ITocEntryList](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentrylist)