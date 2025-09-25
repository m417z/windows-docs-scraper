# WTS_SESSION_ADDRESS structure

## Description

Contains the virtual IP address assigned to a session. This structure is returned by the [WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa) function when you specify "WTSSessionAddressV4" for the *WTSInfoClass* parameter.

## Members

### `AddressFamily`

A null-terminated string that contains the address family. Always set this member to "AF_INET".

### `Address`

The virtual IP address assigned to the session. The format of this address is identical to that used in the [WTS_CLIENT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_address) structure.

## See also

[WTSQuerySessionInformation](https://learn.microsoft.com/windows/desktop/api/wtsapi32/nf-wtsapi32-wtsquerysessioninformationa)

[WTS_CLIENT_ADDRESS](https://learn.microsoft.com/windows/desktop/api/wtsapi32/ns-wtsapi32-wts_client_address)