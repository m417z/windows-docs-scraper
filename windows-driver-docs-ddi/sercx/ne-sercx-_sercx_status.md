# _SERCX_STATUS enumeration

## Description

The **SERCX_STATUS** enumeration indicates the status of a serial receive or transmit operation.

## Constants

### `SerCxStatusSuccess`

The operation is proceeding successfully.

### `SerCxStatusCancelled`

The operation was canceled.

### `SerCxStatusTimeout`

The operation timed out. This enumeration value applies only to read interval time-outs for receive operations. For more information, see the description of the **ReadIntervalTimeout** member in [SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts).

## Remarks

The [SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive) and [SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit) methods have parameters that are **SERCX_STATUS** enumeration values.

## See also

[SERIAL_TIMEOUTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddser/ns-ntddser-_serial_timeouts)

[SerCxProgressReceive](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogressreceive)

[SerCxProgressTransmit](https://learn.microsoft.com/windows-hardware/drivers/ddi/sercx/nf-sercx-sercxprogresstransmit)