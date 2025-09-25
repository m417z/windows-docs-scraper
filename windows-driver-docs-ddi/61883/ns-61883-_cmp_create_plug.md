# _CMP_CREATE_PLUG structure

## Description

This structure is used to create a plug. The request creates an input or output plug control register (iPCR or oPCR) on the local host. A driver is responsible for deleting all of the plugs it has created before the system unloads the driver.

## Members

### `PlugType`

On input, the type of plug to create. Can be one of the following:

#### CMP_PlugOut

An output plug, which transmits data from the device to the bus.

#### CMP_PlugIn

An input plug, which receives data sent by the bus to the device.

### `Pcr`

On input, an [AV_PCR](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_pcr) structure that contains values used by the protocol driver to initialize the plug.

### `pfnNotify`

On input, a pointer to a caller-supplied function to be called by the protocol driver when the plug is created.

### `Context`

On input, a pointer to an optional caller-supplied context for the function at **pfnNotify**.

### `PlugNum`

On output, the plug number.

### `hPlug`

On output, the handle of the created plug

## -PlugNum

The plug number of the newly created plug. If the plug could not be created, **PlugNum** is zero (0).

## -hPlug

A handle to the newly created plug. If the plug could not be created, **hPlug** is null.

## Remarks

If successful, the IEC-61883 protocol driver sets **Irp->IoStatus.Status** to STATUS_SUCCESS.

If an incorrect parameter is passed in, the protocol driver sets **Irp->IoStatus.Status** to STATUS_INVALID_PARAMETER.

If the protocol driver is unable to allocate resources, it sets **Irp->IoStatus.Status** to STATUS_INSUFFICIENT_RESOURCES.

## See also

[AV_61883_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/61883/ns-61883-_av_61883_request)