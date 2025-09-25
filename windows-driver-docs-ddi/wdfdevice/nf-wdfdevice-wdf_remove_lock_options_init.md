# WDF_REMOVE_LOCK_OPTIONS_INIT function

## Description

[Applies to KMDF only]

 The
**WDF_REMOVE_LOCK_OPTIONS_INIT** function initializes a [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure.

## Parameters

### `RemoveLockOptions` [out]

A pointer to a [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure.

### `Flags` [in]

[WDF_REMOVE_LOCK_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_remove_lock_options_flags)-typed flags.

## Remarks

The **WDF_REMOVE_LOCK_OPTIONS_INIT** function zeros the [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure that the *RemoveLockOptions* parameter specifies and sets its **Size** member. This function also sets the structure's **Flags** member to the value provided in the *Flags* parameter.

Before a driver calls [WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions), it must call **WDF_REMOVE_LOCK_OPTIONS_INIT** to initialize a [WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options) structure.

For a code example that uses **WDF_REMOVE_LOCK_OPTIONS_INIT**, see [WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions).

## See also

[WDF_REMOVE_LOCK_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_remove_lock_options)

[WDF_REMOVE_LOCK_OPTIONS_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_remove_lock_options_flags)

[WdfDeviceInitSetRemoveLockOptions](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetremovelockoptions)