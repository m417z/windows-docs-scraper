# UcmInitializeDevice function

## Description

Initializes the USB connector manager framework extension (UcmCx).

## Parameters

### `WdfDevice` [in]

A handle to a framework device object that the client driver received in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `Config` [in]

A pointer to a caller-supplied [UCM_MANAGER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_manager_config) structure that is initialized by calling [UCM_MANAGER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_manager_config_init).

## Return value

**UcmInitializeDevice** returns STATUS_SUCCESS if the operation succeeds. Otherwise, this method can return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) value.

## Remarks

This method initializes UcmCx and allocates resources required, registers for PnP events, and sets up I/O targets. The client driver must call this method in the driver's [EVT_WDF_DRIVER_DEVICE_ADD](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) implementation.

## See also

[UCM_MANAGER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/ns-ucmmanager-_ucm_manager_config)

[UCM_MANAGER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ucmmanager/nf-ucmmanager-ucm_manager_config_init)