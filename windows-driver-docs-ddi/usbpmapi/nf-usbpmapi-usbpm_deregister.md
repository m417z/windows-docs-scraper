# UsbPm_Deregister function

## Description

Unregisters the client driver with the Policy Manager.

## Parameters

### `ClientHandle` [In]

The handle that the client driver received in a previous call to **[UsbPm_Register](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)**.

## Return value

Returns STATUS_SUCCESS if the operation succeeds. Otherwise, returns an appropriate **[NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values)** value.

## Remarks

**UsbPm_Deregister** does not return until all outstanding calls to the client driver's callback functions are returned. After **UsbPm_Deregister** returns, Policy Manager no longer invokes callback functions on the same handle.

The driver typically calls **[UsbPm_Register](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)** in the driver's **[EVT_WDF_DEVICE_SELF_MANAGED_IO_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_init)** and unregisters in **[EVT_WDF_DEVICE_SELF_MANAGED_IO_CLEANUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_self_managed_io_cleanup)** by calling **UsbPm_Deregister**.

## See also

- **[UsbPm_Register](https://learn.microsoft.com/windows-hardware/drivers/ddi/usbpmapi/nf-usbpmapi-usbpm_register)**