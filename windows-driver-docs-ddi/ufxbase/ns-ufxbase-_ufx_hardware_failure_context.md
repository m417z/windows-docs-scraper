# _UFX_HARDWARE_FAILURE_CONTEXT structure

## Description

The **UFX_HARDWARE_FAILURE_CONTEXT** structure is used to define controller-specific hardware failure properties.

## Members

### `Size`

The size of the **UFX_HARDWARE_FAILURE_CONTEXT** structure.

### `ExceptionCode`

The controller-specific hardware failure code.

### `Data`

A variable-length array of data associated with the hardware failure.

## Remarks

In cases where the function controller has experienced a fatal error, the client driver may allocate a variable-length **UFX_HARDWARE_FAILURE_CONTEXT** structure, set the **Size** field to the allocated size, set the **ExceptionCode** field to a value indicating the type of hardware error (as defined by the client driver) and fill in any associated information in the **Data** array. It may then pass this structure to the [UfxDeviceNotifyHardwareFailure](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nf-ufxclient-ufxdevicenotifyhardwarefailure) UFX function. UFX will in turn pass this structure to the client driver’s [EVT_UFX_DEVICE_CONTROLLER_RESET](https://learn.microsoft.com/windows-hardware/drivers/ddi/ufxclient/nc-ufxclient-evt_ufx_device_controller_reset) event callback function (if it exists).