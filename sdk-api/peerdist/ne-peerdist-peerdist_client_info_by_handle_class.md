# PEERDIST_CLIENT_INFO_BY_HANDLE_CLASS enumeration

## Description

The **PEERDIST_CLIENT_INFO_BY_HANDLE_CLASS** enumeration defines the possible client information values.

## Constants

### `PeerDistClientBasicInfo:0`

 Indicates the information to retrieve is a [PEERDIST_CLIENT_BASIC_INFO](https://learn.microsoft.com/windows/desktop/api/peerdist/ns-peerdist-peerdist_client_basic_info) structure.

### `MaximumPeerDistClientInfoByHandlesClass`

The maximum value for the enumeration that is used for error checking. This value should not be sent to the [PeerDistClientGetInformationByHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientgetinformationbyhandle) function.

## Remarks

A value from this enumeration is passed to the[PeerDistClientGetInformationByHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientgetinformationbyhandle) function as the *PeerDistClientInfoClass* parameter.

## See also

[PeerDistClientGetInformationByHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientgetinformationbyhandle)