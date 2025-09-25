# PEERDIST_CLIENT_BASIC_INFO structure

## Description

The **PEERDIST_CLIENT_BASIC_INFO** structure indicates whether or not there are many clients simultaneously downloading the same content.

## Members

### `fFlashCrowd`

Indicates that a "flash crowd" situation has been detected, where many clients in the branch office are simultaneously downloading the same content.

## Remarks

Thie **PEERDIST_CLIENT_BASIC_INFO** structure is retrieved from the [PeerDistClientGetInformationHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientgetinformationbyhandle) function with PeerDistClientBasicInfo value specified for the *PeerDistClientInfoClass* parameter.

If true, content that cannot be retrieved from the Peer Distribution APIs may soon be available for retrieval.

## See also

[PeerDistClientGetInformationHandle](https://learn.microsoft.com/windows/desktop/api/peerdist/nf-peerdist-peerdistclientgetinformationbyhandle)