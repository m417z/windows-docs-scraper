# ITocEntry::GetSubEntries

## Description

The **GetSubEntries** method gets an array of subentry indices that were set by a previous call to [SetSubEntries](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setsubentries).

## Parameters

### `pdwNumSubEntries` [in, out]

If *pwSubEntryIndices* is **NULL**, this is an output parameter that receives the number of subentries associated with this entry. If *pwSubEntryIndices* is not **NULL**, this is an input parameter that specifies the number of **DWORD**s in the caller-allocated array pointed to by *pwSubEntryIndices*.

### `pwSubEntryIndices` [out]

**NULL**, or a pointer to a caller-allocated array of **DWORD**s that receives the subentry indices.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **MF_E_BUFFERTOOSMALL** | The method returns this error code if *pwSubEntryIndices* is not **NULL** and the number of subentries is larger than the number specified by *pdwNumSubEntries*. In that case, *pdwNumSubEntries* serves as an output parameter and receives the number of available subentry indices. |

## See also

[ITocEntry](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nn-wmcodecdsp-itocentry)

[SetSubEntries](https://learn.microsoft.com/windows/desktop/api/wmcodecdsp/nf-wmcodecdsp-itocentry-setsubentries)