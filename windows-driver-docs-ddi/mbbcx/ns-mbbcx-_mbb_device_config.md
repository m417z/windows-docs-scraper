# _MBB_DEVICE_CONFIG structure

## Description

The **MBB_DEVICE_CONFIG** structure contains pointers to a client driver's MBBCx-specific callback functions. The client driver must supply an initialized **MBB_DEVICE_CONFIG** structure as an input parameter to [**MbbDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdeviceinitialize).

## Members

### `Size`

The size of this **MBB_DEVICE_CONFIG** structure, in bytes.

### `SendMbimFragment`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_SEND_MBIM_FRAGMENT*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function.

### `ReceiveMbimFragment`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_RECEIVE_MBIM_FRAGMENT*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function.

### `SendDeviceServiceSessionData`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_SEND_SERVICE_SESSION_DATA*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_device_service_session_data) callback function.

### `CreateAdapter`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_create_adapter) callback function.

## Remarks

Call [**MBB_DEVICE_CONFIG_INIT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbb_device_config_init) to initialize this structure.

## See also