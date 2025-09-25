# PNRP_CLOUD_FLAGS enumeration

## Description

The **PNRP_CLOUD_FLAGS** enumeration specifies the validity of a cloud name.

## Constants

### `PNRP_CLOUD_NO_FLAGS:0`

The cloud name is valid on the network.

### `PNRP_CLOUD_NAME_LOCAL:1`

The cloud name is not valid on other computers.

### `PNRP_CLOUD_RESOLVE_ONLY:2`

The cloud is configured to be resolve only. Names cannot be published to the cloud from this computer.

### `PNRP_CLOUD_FULL_PARTICIPANT:4`

This machine is a full participant in the cloud, and can publish and resolve names.

## See also

[PNRP and WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsalookupservicenext)

[PNRPCLOUDINFO](https://learn.microsoft.com/windows/desktop/api/pnrpns/ns-pnrpns-pnrpcloudinfo)