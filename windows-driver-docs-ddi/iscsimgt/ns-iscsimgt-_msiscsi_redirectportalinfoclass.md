# _MSiSCSI_RedirectPortalInfoClass structure

## Description

The MSiSCSI_RedirectPortalInfoClass structure contains information about a collection of sessions for an adapter ID. It also contains the portal redirection information for each of the sessions.

## Members

### `UniqueAdapterId`

A 64-bit integer that uniquely identifies an HBA initiator and a loaded instance of a storage miniport driver that manages the HBA. The initiator should use the address of the adapter extension or another address that the device driver owns to construct this identifier (ID).

### `SessionCount`

The number of sessions for which this structure contains information.

### `RedirectSessionList`

An array of structures that contains as many ISCSI_RedirectSessionInfo structures as specified in the connection count.

## Remarks

You must implement this class if the adapter supports target portal hopping. Otherwise, it is optional.