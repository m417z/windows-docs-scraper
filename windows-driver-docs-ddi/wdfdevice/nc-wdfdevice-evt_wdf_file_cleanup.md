# EVT_WDF_FILE_CLEANUP callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtFileCleanup* callback function handles operations that must be performed when an application is closing all accesses to a device.

## Parameters

### `FileObject` [in]

A handle to a framework file object, which was previously received by the driver's [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function.

## Remarks

The framework calls a driver's *EvtFileCleanup* callback function when the last handle to the specified file object has been closed. (Because of outstanding I/O requests, this handle might not have been released.)

After the framework calls a driver's *EvtFileCleanup* callback function, it calls the driver's [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) callback function.

The *EvtFileCleanup* callback function is called synchronously, in the context of the thread that closed the last file object handle.

To register an *EvtFileCleanup* callback function, the driver must call the [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig) method.

For more information about framework file objects and the *EvtFileCleanup* callback function, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

## See also

[WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config)