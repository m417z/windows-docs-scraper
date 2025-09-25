# PNRP_CLOUD_STATE enumeration

## Description

The **PNRP_CLOUD_STATE** enumeration specifies the different states a PNRP cloud can be in.

## Constants

### `PNRP_CLOUD_STATE_VIRTUAL:0`

The cloud is not yet initialized.

### `PNRP_CLOUD_STATE_SYNCHRONISING:1`

The cloud is in the process of being initialized.

### `PNRP_CLOUD_STATE_ACTIVE:2`

The cloud is active.

### `PNRP_CLOUD_STATE_DEAD:3`

The cloud is initialized, but has lost its connection to the network.

### `PNRP_CLOUD_STATE_DISABLED:4`

The cloud is disabled in the registry.

### `PNRP_CLOUD_STATE_NO_NET:5`

The cloud was active, but has lost access to the network. In this state the cloud can still be used for registration but it is not capable of resolving addresses.

### `PNRP_CLOUD_STATE_ALONE:6`

The local node bootstrapped, but found no other nodes in the cloud. This can also be the result of a network issue, like a firewall, preventing the local node from locating other nodes within the cloud. It is also important to note that a cloud in the **PNRP_CLOUD_STATE_ALONE** state may not have registered IP addresses.

**Note** It is possible for a local node to lose network connectivity while in this cloud state and not make the transition to the **PNRP_CLOUD_STATE_NO_NET** state.

## See also

[PNRP and WSALookupServiceNext](https://learn.microsoft.com/windows/desktop/P2PSdk/pnrp-and-wsalookupservicenext)

[PNRPCLOUDINFO](https://learn.microsoft.com/windows/desktop/api/pnrpns/ns-pnrpns-pnrpcloudinfo)