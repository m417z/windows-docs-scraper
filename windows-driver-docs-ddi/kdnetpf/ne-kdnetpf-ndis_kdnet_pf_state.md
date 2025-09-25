## Description

The **NDIS_KDNET_PF_STATE** enumeration defines the PF state.

## Constants

### `NdisKdNetPfStatePrimary`

This is a primary PF and it's usually used only by the miniport driver.

### `NdisKdnetPfStateEnabled`

This is an added secondary PF, that is used by KDNET.

### `NdisKdnetPfStateConfigured`

This is an added PF, but it is only added/configured and is not used.

## Remarks

## See also

[kdnetpf.h](https://learn.microsoft.com/windows-hardware/drivers/ddi/kdnetpf/)

[Debugger 2PF KDNET Support](https://learn.microsoft.com/windows-hardware/drivers/network/debugger-2pf-kdnet-support)