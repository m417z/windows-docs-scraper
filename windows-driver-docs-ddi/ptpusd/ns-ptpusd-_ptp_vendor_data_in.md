# _PTP_VENDOR_DATA_IN structure

## Description

The PTP_VENDOR_DATA_IN structure contains information about an arbitrary command that an application issues to the device.

## Members

### `OpCode`

Specifies the command opcode. For more information, see [ISO 15740:2013 *Photography − Electronic still picture imaging − Picture Transfer Protocol (PTP) for Digital Still Photography Devices*](https://www.imaging.org/site/IST/IST/Standards/PTP_Standards.aspx).

### `SessionId`

Specifies the session ID. This member is not currently used by the PTP driver and should be set to 0.

### `TransactionId`

Specifies the transaction ID. This member is not currently used by the PTP driver and should be set to 0.

### `Params`

Is an array consisting of PTP_MAX_PARAMS (defined in *Ptpusd.h*) elements, representing the parameters of the command.

### `NumParams`

Specifies the actual number of elements in the **Params** array.

### `NextPhase`

Indicates whether to read data from the device, write data to the device, or neither. This member can be set to one of the following values:

| Value | Meaning |
| --- | --- |
| PTP_NEXTPHASE_NO_DATA | No data is to be read from or written to the device. |
| PTP_NEXTPHASE_READ_DATA | Read data from the device. |
| PTP_NEXTPHASE_WRITE_DATA | Write data to the device. |

### `VendorWriteData`

Is an array containing an (optional) first byte to write to the device.

## Remarks

See [Vendor-Extended Commands](https://learn.microsoft.com/windows-hardware/drivers/image/vendor-extended-commands) for more information and example code that uses this structure.

For more information about the opcodes used in the **OpCode** member, see [ISO 15740:2013 *Photography − Electronic still picture imaging − Picture Transfer Protocol (PTP) for Digital Still Photography Devices*](https://www.imaging.org/site/IST/IST/Standards/PTP_Standards.aspx).

## See also

[PTP_VENDOR_DATA_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/ptpusd/ns-ptpusd-_ptp_vendor_data_out)