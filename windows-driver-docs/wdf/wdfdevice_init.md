# WDFDEVICE_INIT structure

\[Applies to KMDF and UMDF\]

The **WDFDEVICE_INIT** structure is an opaque structure that is defined and allocated by the framework.

## Members

Function and filter drivers receive a pointer to this structure as input to a [*EvtDriverDeviceAdd*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdriver/nc-wdfdriver-evt_wdf_driver_device_add) callback function or as a return value from [**WdfControlDeviceInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate).

Bus drivers receive a structure pointer as input to a [*EvtChildListCreateDevice*](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nc-wdfchildlist-evt_wdf_child_list_create_device) callback function or as the return value from [**WdfPdoInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate).

After a driver receives a **WDFDEVICE_INIT** structure, it passes the structure pointer to initialization functions.
These functions use the **WDFDEVICE_INIT** structure to store information that the framework uses to create a framework device object.

To find documentation for device initialization methods, see [wdfdevice.h header](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/).

After calling initialization functions, the driver must call [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create the framework device object.

If your driver received the **WDFDEVICE_INIT** structure from a call to [**WdfPdoInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nf-wdfpdo-wdfpdoinitallocate)
or [**WdfControlDeviceInitAllocate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfcontrol/nf-wdfcontrol-wdfcontroldeviceinitallocate),
and if the driver receives an error from calling an initialization function, the driver must call [**WdfDeviceInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree) instead of [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

Your driver must not call [**WdfDeviceInitFree**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitfree) after a successful call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

The **WDFDEVICE_INIT** structure is available in version 1.0 and later versions of KMDF.

## Requirements

|  |  |
| --- | --- |
| Header | Wdftypes.h (include Wdftypes.h) |