# IEnumDirectoryObject::Skip

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**Skip** method skips over the next specified number of elements in the enumeration sequence.

## Parameters

### `celt` [in]

Number of elements to skip.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Number of elements skipped was *celt*. |
| **S_FALSE** | Number of elements skipped was not *celt*. |

## See also

[IEnumDirectoryObject](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-ienumdirectoryobject)