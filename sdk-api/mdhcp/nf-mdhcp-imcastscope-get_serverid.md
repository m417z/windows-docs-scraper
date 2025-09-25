# IMcastScope::get_ServerID

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_ServerID** method obtains the server ID associated with this scope. The scope ID and server ID are needed to select this scope in subsequent calls to
[IMcastAddressAllocation::RequestAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-requestaddress),
[IMcastAddressAllocation::RenewAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-renewaddress), or
[IMcastAddressAllocation::ReleaseAddress](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastaddressallocation-releaseaddress).

## Parameters

### `pID` [out]

Pointer to a **LONG** that will receive the server ID of this scope, which is the ID that was assigned to the multicast address allocation server that published this scope at the time that the server was configured.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The caller passed in an invalid pointer argument. |

## See also

[IMcastScope](https://learn.microsoft.com/windows/desktop/api/mdhcp/nn-mdhcp-imcastscope)

[IMcastScope::get_ScopeID](https://learn.microsoft.com/windows/desktop/api/mdhcp/nf-mdhcp-imcastscope-get_scopeid)