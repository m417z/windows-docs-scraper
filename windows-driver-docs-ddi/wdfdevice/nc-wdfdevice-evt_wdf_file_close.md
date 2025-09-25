# EVT_WDF_FILE_CLOSE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtFileClose* callback function handles operations that must be performed when all of an application's accesses to a device have been closed.

## Parameters

### `FileObject` [in]

A handle to a framework file object, which was previously received by the driver's [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) callback function.

## Remarks

The framework calls a driver's *EvtFileClose* callback function when the last handle for a file object has been closed and released, and all outstanding I/O requests have been completed or canceled.

The device might not be in its working (D0) state.

Before the framework calls a driver's *EvtFileClose* callback function, it calls the driver's [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) callback function.

The *EvtFileClose* callback function is called synchronously, in an arbitrary thread context.

To register an *EvtFileClose* callback function, the driver must call the [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig) method.

For more information about framework file objects and the *EvtFileClose* callback function, see [Framework File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-file-objects).

## See also

[WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config)