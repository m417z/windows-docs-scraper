# _WDF_FILEOBJECT_CONFIG structure

## Description

[Applies to KMDF and UMDF]

The **WDF_FILEOBJECT_CONFIG** structure contains configuration information of a driver's framework file objects.

## Members

### `Size`

The size, in bytes, of this structure.

### `EvtDeviceFileCreate`

A pointer to the driver's [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function, or **NULL**.

### `EvtFileClose`

A pointer to the driver's [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback function, or **NULL**.

### `EvtFileCleanup`

A pointer to the driver's [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) callback function, or **NULL**.

### `AutoForwardCleanupClose`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed value. For more information about this member, see the following Comments section.

### `FileObjectClass`

A [WDF_FILEOBJECT_CLASS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_fileobject_class)-typed value that identifies whether the driver requires a framework file object to represent each file that an application or another driver creates or opens. Additionally, this value specifies where the framework can store the object's handle.

## Remarks

The **WDF_FILEOBJECT_CONFIG** structure is used as input to the [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig) method.

**WDF_FILEOBJECT_CONFIG** must be initialized by calling [WDF_FILEOBJECT_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_fileobject_config_init).

### Framework Behavior for **AutoForwardCleanupClose**

If **AutoForwardCleanupClose** is set to **WdfTrue**, the framework does the following:

* The framework forwards file creation requests to the next-lower driver if the driver does not provide an [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function and has not called [WdfDeviceConfigureRequestDispatching](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceconfigurerequestdispatching) to set an I/O queue to receive file creation requests. The framework does not forward file creation requests if the driver provides a callback function or a queue to handle the requests, so the driver must [forward](https://learn.microsoft.com/windows-hardware/drivers/wdf/forwarding-i-o-requests), [complete](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests), or [cancel](https://learn.microsoft.com/windows-hardware/drivers/wdf/canceling-i-o-requests) the requests.
* The framework sends file cleanup and close requests to the next-lower driver after calling the driver's [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) and [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback functions.

If **AutoForwardCleanupClose** is set to **WdfFalse**, the framework does not forward file creation, cleanup, or close requests. Instead, the framework completes the requests for the driver.

If **AutoForwardCleanupClose** is set to **WdfUseDefault**, the framework uses **WdfTrue** behavior for filter drivers and **WdfFalse** behavior for function drivers.

### Driver Behavior for **AutoForwardCleanupClose**

Your driver's local I/O target must always receive an equal number of I/O requests with request types of **WdfRequestTypeCreate**, **WdfRequestTypeCleanup**, and **WdfRequestTypeClose**. Therefore, if the driver provides either an [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function or an I/O queue that receives file creation requests, you must use the following rules:

* If your driver sets **AutoForwardCleanupClose** to **WdfTrue**, the driver must forward all file creation requests to the local I/O target. You must follow this rule because the framework will forward all cleanup and close requests to the local target, whether or not your driver provides [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) and [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback functions.
* If your driver sets **AutoForwardCleanupClose** to **WdfFalse**, the driver must *not* forward file creation requests to the local I/O target. You must follow this rule because the framework will *not* forward cleanup and close requests to the local target, whether or not your driver provides [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) and [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback functions.
* If your driver sets **AutoForwardCleanupClose** to **WdfDefault**, the driver must follow the rule for **WdfTrue** if it is a filter driver. The driver must follow the rule for **WdfFalse** if it is a function driver.