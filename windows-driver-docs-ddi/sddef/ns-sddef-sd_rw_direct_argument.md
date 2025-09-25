## Description

The SD_RW_DIRECT_ARGUMENT structure is used in conjunction with the [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) routine or the [**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync) routine to send a Secure Digital (SD) read or write request to the bus driver.

## Members

### `u`

Name of union.

### `u.bits`

Structure that contains the following members.

### `u.bits.Data`

Contains eight bits of data to read or write.

### `u.bits.Reserved1`

Reserved.

### `u.bits.Address`

Indicates the address of the function space accessed by the operation.

### `u.bits.Reserved2`

Reserved.

### `u.bits.ReadAfterWrite`

Indicates that the operation should read the data at the specified location after writing to that location. The primary use of this option is to write to a control register and then read status information at the same address immediately afterwards. The caller must set **WriteToDevice** to 1 or this member will have no effect.

### `u.bits.Function`

Contains the number of the function on the I/O card whose data space is accessed by the operation. A value of 0 indicates that the operation should address the common I/O area, rather than the I/O space of a particular card function.

To retrieve a function number for an SD device, a device driver must do the following:

1. Set the **RequestFunction** member of [**SDBUS_REQUEST_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/device-stage/drivers/ff537931(v=vs.85)) to an [**SD_REQUEST_FUNCTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/ne-ntddsd-sd_request_function) enumerator value of SDRF_GET_PROPERTY.

1. Set the **Property** member of [**SDBUS_REQUEST_PACKET**](https://learn.microsoft.com/previous-versions/windows/hardware/device-stage/drivers/ff537931(v=vs.85)) to SDP_FUNCTION_NUMBER.

1. Send the request to the bus driver by passing the initialized SDBUS_REQUEST_PACKET structure to either [**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest) or [**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync).

### `u.bits.WriteToDevice`

Indicates a write operation when set to 1, and a read operation when set to 0.

### `u.AsULONG`

Contains all 32 bits of the data stored in the preceding members, represented as a ULONG.

## See also

[**SdBusSubmitRequest**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequest)

[**SdBusSubmitRequestAsync**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddsd/nf-ntddsd-sdbussubmitrequestasync)