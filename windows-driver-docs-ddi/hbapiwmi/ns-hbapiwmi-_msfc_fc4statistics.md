# _MSFC_FC4STATISTICS structure

## Description

The MSFC_FC4STATISTICS structure is used in conjunction with the [GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics) WMI method to report traffic statistics on a port of type Nx_Port for the indicated FC-4 protocol.

## Members

### `InputRequests`

Indicates the number of input requests.

### `OutputRequests`

Indicates the number of output requests.

### `ControlRequests`

Indicates the number of control requests.

### `InputMegabytes`

Indicates the number of megabytes of data that has been input.

### `OutputMegabytes`

Indicates the number of megabytes of data that has been output.

## Remarks

The statistics counters whose values are reported in the members of this structure are 64-bit signed integers that wrap to zero on exceeding 2**63-1. The statistics counters are not reset during normal operation, so traffic rates may be determined by the difference of counter values derived from two successive calls, with appropriate adjustments to for counter wrap.

If an HBA does not support a specific statistic, it shall return the value of -1 for corresponding counter.

## See also

[GetFC4Statistics](https://learn.microsoft.com/windows-hardware/drivers/storage/getfc4statistics)

[GetFC4Statistics_IN](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_in)

[GetFC4Statistics_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/hbapiwmi/ns-hbapiwmi-_getfc4statistics_out)