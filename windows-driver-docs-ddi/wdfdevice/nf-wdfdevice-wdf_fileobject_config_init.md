# WDF_FILEOBJECT_CONFIG_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_FILEOBJECT_CONFIG_INIT** function initializes a driver's [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.

## Parameters

### `FileEventCallbacks` [out]

A pointer to a driver-allocated [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure.

### `EvtDeviceFileCreate` [in, optional]

A pointer to the driver's [EvtDeviceFileCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_file_create) event callback function.

### `EvtFileClose` [in, optional]

A pointer to the driver's [EvtFileClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_close) event callback function.

### `EvtFileCleanup` [in, optional]

A pointer to the driver's [EvtFileCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_file_cleanup) event callback function.

## Remarks

The **WDF_FILEOBJECT_CONFIG_INIT** function sets the specified [WDF_FILEOBJECT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_fileobject_config) structure's **Size** member, stores the specified callback function pointers, sets the **FileObjectClass** member to **WdfFileObjectWdfCannotUseFsContexts**, and sets the **AutoForwardCleanupClose** member to **WdfUseDefault**.

#### Examples

For a code example that uses **WDF_FILEOBJECT_CONFIG_INIT**, see [WdfDeviceInitSetFileObjectConfig](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetfileobjectconfig).