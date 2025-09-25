# UFX_DEVICE_CALLBACKS_INIT function

## Description

The **UFX_DEVICE_CALLBACKS_INIT** macro initializes the [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) structure.

## Parameters

### `Callbacks` [out]

A pointer to the [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) structure.

## Remarks

The **UFX_DEVICE_CALLBACKS_INIT** macro will set all fields of the [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) structure to zero and set the **Size** field appropriately.

The client driver uses the **UFX_DEVICE_CALLBACKS_INIT** macro the initialize the [UFX_DEVICE_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/ns-ufxclient-_ufx_device_callbacks) structure prior to calling [UfxDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicecreate).