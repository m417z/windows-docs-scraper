# MBB_DEVICE_CONFIG_INIT function

## Description

The **MBB_DEVICE_CONFIG_INIT** method initializes the [**MBB_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_config) structure.

## Parameters

### `Config`

A pointer to the client driver-allocated [**MBB_DEVICE_CONFIG**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/ns-mbbcx-_mbb_device_config) structure.

### `SendMbimFragment`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_SEND_MBIM_FRAGMENT*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function.

### `ReceiveMbimFragment`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_RECEIVE_MBIM_FRAGMENT*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function.

### `SendDeviceServiceSessionData`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_SEND_SERVICE_SESSION_DATA*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_device_service_session_data) callback function.

### `CreateAdapter`

A pointer to the client driver's implementation of the [*EVT_MBB_DEVICE_CREATE_ADAPTER*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_create_adapter) callback function.

## Remarks

The client driver calls this method from its [*EVT_WDF_DRIVER_DEVICE_ADD*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) event callback function in preparation for calling [**MbbDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdeviceinitialize).

## See also

[Mobile Broadband (MBB) WDF class extension (MBBCx)](https://learn.microsoft.com/windows-hardware/drivers/netcx/mobile-broadband-mbb-wdf-class-extension-mbbcx)