## Description

The **SDBUS_REQUEST_PACKET** structure specifies the parameters for the individual requests and commands that the [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) routine sends to the bus driver.

## Members

### `RequestFunction`

Contains an enumeration value of type [**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) that specifies the parameters for the operation and how they are interpreted.

### `UserContext[3]`

Contains a buffer area for optional use by the caller. The bus driver does not use this member.

### `Information`

Contains the status of the request on output.

### `ResponseData`

Defines the **ResponseData** union.

### `ResponseData.AsUCHAR[16]`

Contains a maximum of 16 bytes of response data on output. For more information about the response data, see the *Secure Digital (SD)* specification.

### `ResponseData.AsULONG[4]`

Contains a maximum of 16 bytes of response data on output. For more information about the response data, see the *Secure Digital (SD)* specification.

### `ResponseData.Type3`

Defines the **SDRESP_TYPE3** member **Type3**.

### `ResponseLength`

Indicates the length, in bytes, of the response data.

### `Reserved`

Reserved, set to 0.

### `Flags`

Flags field for the SDRP.

### `Parameters`

Parameters to the individual functions.

### `Parameters.GetSetProperty`

The property functions allow the caller to control aspects of bus driver operation.

### `Parameters.GetSetProperty.Property`

Contains an enumeration value of type [**SDBUS_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sdbus_property) that specifies the property to read or change.

### `Parameters.GetSetProperty.Buffer`

Contains the property data to write in operations that set a property. Contains the data read from the property in operations that retrieve the data associated with a property.

### `Parameters.GetSetProperty.Length`

Indicates the length, in bytes, of the response data.

### `Parameters.DeviceCommand`

**DeviceCommand** is the 'pipe' that allows SD device codes and arguments to be executed. These codes are either defined in the *Secure Digital (SD)* specification, can be based per device class, or can also be proprietary.

### `Parameters.DeviceCommand.CmdDesc`

Contains a structure of type [**SDCMD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor) that defines an SD card command.

### `Parameters.DeviceCommand.Argument`

Contains 4 bytes of argument information that accompanies the command.

### `Parameters.DeviceCommand.Mdl`

Pointer to an MDL that holds the command data.

### `Parameters.DeviceCommand.Length`

Indicates the length, in bytes, of the response data.

### `Parameters.EraseCommand`

**EraseCommand** allows MMC devices to send Erase commands to the given device in an atomic sequence, as three device commands need to be sent to Erase a given LBA range or group.

### `Parameters.EraseCommand.EraseType`

Defines the **SDBUS_ERASE_TYPE** member **EraseType**.

### `Parameters.EraseCommand.StartBlock`

Defines the **ULONG** member **StartBlock**.

### `Parameters.EraseCommand.EndBlock`

Defines the **ULONG** member **EndBlock**.

### `Parameters.MmcSoftReset`

**MmcSoftReset** allows eMMC devices to be soft reset for a SanDisk proprietary firmware update that resets the device to its manufactured state.

### `Parameters.MmcSoftReset.Frequency`

Defines the **ULONG** member **Frequency**.

### `Parameters.MmcHpi`

**MmcHpi** allows an HPI to be sent to the eMMC device which will cause sdbus to stop the currently executing SDRP with STATUS_SDBUS_IO_INTERRUPTED. The information field of the stopped SDRP will be filled out with the progress of the halted operation, so it may be resumed later at the correct offset.

### `Parameters.MmcHpi.IrpToHpi`

This is the IRP to HPI. This is checked by SDBUS to ensure it is going to HPI the right IRP.

## Remarks

If the request reads or sets a property on an SD device, a device driver must complete the following steps:

1. Set the **RequestFunction** member of **SDBUS_REQUEST_PACKET** to an [**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) enumeration value of either SDRF_GET_PROPERTY or SDRF_SET_PROPERTY.

1. Set the **Property** member of **SDBUS_REQUEST_PACKET** to the **SDBUS_PROPERTY** enumeration value that specifies the property to read or change.

1. Send the request to the bus driver by passing the initialized **SDBUS_REQUEST_PACKET** structure to either [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) or [**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync).

If the request sends a command to an SD device, a device driver must complete the following steps:

1. Set the **RequestFunction** member of **SDBUS_REQUEST_PACKET** to an [**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) enumeration value of SDRF_DEVICE_COMMAND.

1. Initialize the **CmdDesc** member of **SDBUS_REQUEST_PACKET** to define the command.

1. Send the request to the bus driver by passing the initialized **SDBUS_REQUEST_PACKET** structure to either [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) or [**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync).

To do property operations, the driver must initialize the **GetSetProperty.Property**, **GetSetProperty.Buffer**, and **GetSetProperty.Length** members of the **SDBUS_REQUEST_PACKET** structure before submitting the request.

To send a command, the driver must initialize the **DeviceCommand.CmdDesc**, **DeviceCommand.Argument**, **DeviceCommand.Mdl**, and **DeviceCommand.Length** members of the **SDBUS_REQUEST_PACKET** structure before submitting the request.

## See also

[**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function)

[**SDBUS_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sdbus_property)

[**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)

[**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync)

[**SDCMD_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ns-sddef-_sdcmd_descriptor)