# _POS_CX_ATTRIBUTES structure

## Description

The POS_CX_ATTRIBUTES structure contains pointers to event callback functions implemented by the client driver.

Use [POS_CX_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-pos_cx_attributes_init) to initialize this structure.

## Members

### `EvtDeviceOwnershipChange`

A pointer to an [EVT_POS_CX_DEVICE_OWNERSHIP_CHANGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_ownership_change) callback function.

### `EvtDeviceRemoteClaim`

A pointer to an [EVT_POS_CX_DEVICE_REMOTE_CLAIM](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_remote_claim) callback function.

### `EvtDeviceRemoteRelease`

A pointer to an [EVT_POS_CX_DEVICE_REMOTE_RELEASE](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_remote_release) callback function.

### `EvtDeviceRemoteRetain`

A pointer to an [EVT_POS_CX_DEVICE_REMOTE_RETAIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nc-poscx-evt_pos_cx_device_remote_retain) callback function.

## See also

[POS_CX_ATTRIBUTES_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-pos_cx_attributes_init)

[PosCxInit](https://learn.microsoft.com/windows-hardware/drivers/ddi/poscx/nf-poscx-poscxinit)