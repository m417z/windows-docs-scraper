# SDCMD_DESCRIPTOR structure

## Description

The **SDCMD_DESCRIPTOR** structure defines a Secure Digital (SD) card command.

## Members

### `Cmd`

Contains a value of type SD_COMMAND_CODE that specifies the SD command. **Cmd** can be one of the following values.

| Value | Meaning |
| ----- | ------- |
| SDCMD_IO_RW_DIRECT | Indicates a read or write operation of a single byte. |
| SDCMD_IO_RW_EXTENDED | Indicates a read or write operation on a buffer in memory. |

### `CmdClass`

Contains an enumeration value of type [**SD_COMMAND_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_command_class) that specifies the class of the SD command.

### `TransferDirection`

Contains an enumeration value of type [**SD_TRANSFER_DIRECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_transfer_direction) that indicates the direction of the data transfer.

### `TransferType`

Contains an enumeration value of type [**SD_TRANSFER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_transfer_type) that indicates the type of the data transfer.

### `ResponseType`

Contains an enumeration value of type [**SD_RESPONSE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_response_type) that indicates the type of response that the card sends in response to the command indicated in the **Cmd** member.

## Remarks

To send a command to an SD device, a device driver must complete the following steps:

1. Set the **RequestFunction** member of SDBUS_REQUEST_PACKET to an [**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) enumeration value of SDRF_DEVICE_COMMAND.

2. Initialize the **CmdDesc** member of SDBUS_REQUEST_PACKET to define the command.

3. Send the request to the bus driver by passing the initialized SDBUS_REQUEST_PACKET structure to either [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) or [**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync).

If a driver submits a command request without properly initializing the **TransferDirection**, **TransferType**, and **ResponseType** members of the command descriptor, the request will fail. These members cannot be 0.

## See also

[**SD_COMMAND_CLASS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_command_class)

[**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function)

[**SD_RESPONSE_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_response_type)

[**SD_TRANSFER_DIRECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_transfer_direction)

[**SD_TRANSFER_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/sddef/ne-sddef-sd_transfer_type)

[**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)

[**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync)