# CompareStorageDuids function

## Description

The **CompareStorageDuids** routine compares two device unique identifiers (DUIDs) and reports whether they match or not.

## Parameters

### `Duid1` [in]

A pointer to a DUID to compare with the DUID that *Duid2* points to.

### `Duid2` [in]

A pointer to a DUID to compare with the DUID that *Duid1* points to.

## Return value

**CompareStorageDuids** returns a [DUID_MATCH_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ne-storduid-_duid_match_status) value that indicates whether the two DUIDs matched or not, if the operation succeeds. Otherwise, this routine returns a DUID_MATCH_STATUS value that indicates the error status.

## See also

[DUID_MATCH_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/storduid/ne-storduid-_duid_match_status)