# ITocEntry::SetSubEntries

## Description

The **SetSubEntries** identifies a set of entries as being subentries of this entry.

## Parameters

### `dwNumSubEntries` [in]

The number of indices in the array pointed to by *pwSubEntryIndices*.

### `pwSubEntryIndices` [in]

Pointer to an array of **WORD**s. Each **WORD** in the array specifies the index of an entry that is to be considered a subentry of this entry.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## See also

[GetSubEntries](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-getsubentries)

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)