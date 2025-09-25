# _PTP_VENDOR_DATA_OUT structure

## Description

The PTP_VENDOR_DATA_OUT structure contains information that the device sends to an application, in response to a command the application issued to the device.

## Members

### `ResponseCode`

Specifies the response code. For more information, see [ISO 15740:2013 *Photography − Electronic still picture imaging − Picture Transfer Protocol (PTP) for Digital Still Photography Devices*](https://www.imaging.org/site/IST/IST/Standards/PTP_Standards.aspx).

### `SessionId`

Specifies the session ID. This member is not currently used by the PTP driver and should be set to 0.

### `TransactionId`

Specifies the transaction ID. This member is not currently used by the PTP driver and should be set to 0.

### `Params`

Is an array consisting of PTP_MAX_PARAMS (defined in *Ptpusd.h*) elements, representing the parameters of the response.

### `VendorReadData`

Is an array containing an (optional) first byte to read from the device.

## Remarks

See [Vendor-Extended Commands](https://learn.microsoft.com/windows-hardware/drivers/image/vendor-extended-commands) for more information and example code that uses this structure.

For more information about the opcodes used in the **OpCode** member, see [ISO 15740:2013 *Photography − Electronic still picture imaging − Picture Transfer Protocol (PTP) for Digital Still Photography Devices*](https://www.imaging.org/site/IST/IST/Standards/PTP_Standards.aspx).

## See also

[PTP_VENDOR_DATA_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ptpusd/ns-ptpusd-_ptp_vendor_data_in)