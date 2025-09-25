# DsMergeForestTrustInformationW function

## Description

The **DsMergeForestTrustInformationW** function merges the changes from a new forest trust data structure with an old forest trust data structure.

## Parameters

### `DomainName` [in]

Pointer to a null-terminated Unicode string that specifies the trusted domain to update.

### `NewForestTrustInfo` [in]

Pointer to an **LSA_FOREST_TRUST_INFORMATION** structure that contains the new forest trust data to be merged.
The **Flags** and **Time** members of the entries are ignored.

### `OldForestTrustInfo` [in, optional]

Pointer to an **LSA_FOREST_TRUST_INFORMATION** structure that contains the old forest trust data to be merged.
This parameter may be **NULL** if no records exist.

### `MergedForestTrustInfo` [out]

Pointer to an **LSA_FOREST_TRUST_INFORMATION** structure pointer that receives the merged forest trust data.

The caller must free this structure when it is no longer required by calling [NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree).

## Return value

Returns **NO_ERROR** if successful or a Windows error code otherwise.

## See also

[Directory Service Functions](https://learn.microsoft.com/windows/desktop/AD/directory-service-functions)

[NetApiBufferFree](https://learn.microsoft.com/windows/desktop/api/lmapibuf/nf-lmapibuf-netapibufferfree)