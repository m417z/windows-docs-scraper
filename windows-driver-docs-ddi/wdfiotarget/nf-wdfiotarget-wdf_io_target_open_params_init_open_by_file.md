# WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE function

## Description

[Applies to UMDF only]

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE** function initializes a driver's [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure so the driver can open an I/O target by specifying a filename.

## Parameters

### `Params` [out]

A pointer to a driver-allocated [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure, which the function initializes.

### `FileName` [in, optional]

A value for the **FileName** member of the [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure. Most drivers specify **NULL** here unless the lower target supports [Device Namespace Access](https://learn.microsoft.com/windows-hardware/drivers/kernel/controlling-device-namespace-access).

## Remarks

The **WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE** function zeros the specified [WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params) structure and sets its **Size** member. It also sets the structure's **Type** member to **WdfIoTargetOpenLocalTargetByFile** and sets the **FileName** member if the driver supplies a filename.

A driver can explicitly close the I/O target by calling [WdfIoTargetClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/nf-wdfiotarget-wdfiotargetclose). If the driver does not explicitly close the target, the framework closes the target automatically when the device is removed (an I/O target is by default parented to the device).

#### Examples

The following code example shows how a UMDF driver can open a local target with a file object as described in [WDF_IO_TARGET_OPEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type):

```cpp
WDF_OBJECT_ATTRIBUTES  ioTargetAttrib;
WDFIOTARGET  ioTarget;
WDF_IO_TARGET_OPEN_PARAMS  openParams;

//
// Create target
//
WDF_OBJECT_ATTRIBUTES_INIT_CONTEXT_TYPE(&ioTargetAttrib, TARGET_DEVICE_INFO);
status = WdfIoTargetCreate(device, &ioTargetAttrib, &ioTarget);
if (!NT_SUCCESS(status)) {
    return status;
}

//
// Open target
//
WDF_IO_TARGET_OPEN_PARAMS_INIT_OPEN_BY_FILE(&openParams, NULL);
status = WdfIoTargetOpen(ioTarget, &openParams);
if (!NT_SUCCESS(status)) {
    WdfObjectDelete(ioTarget);
    return status;
}

//
// create a request
//

//
// Format the request for the above target
//

//
// Send request to above target
//

```

## See also

[WDF_IO_TARGET_OPEN_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ns-wdfiotarget-_wdf_io_target_open_params)

[WDF_IO_TARGET_OPEN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfiotarget/ne-wdfiotarget-_wdf_io_target_open_type)