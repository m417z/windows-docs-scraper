# NVME_POWER_STATE_DESC structure

## Description

Contains fields that describe the attributes of each power state.

An array of **NVME_POWER_STATE_DESC** structures are used in the **PDS** field of the [Controller Capabilities](https://learn.microsoft.com/windows/win32/api/nvme/ns-nvme-nvme_controller_capabilities) structure.

## Members

### `MP`

Indicates the maximum power consumed by the NVM subsystem in this power state.

The power in Watts is equal to the value in this field multiplied by the scale specified in the Max Power Scale (**MPS**) field.

### `Reserved0`

Bits 16:23 are reserved.

### `MPS`

Indicates the scale for the Maximum Power field (**MP**).

When this field is cleared to `0`, the scale of the **MP** field is in 0.01 Watts. When this field is set to `1`, the scale of the **MP** field is in 0.0001 Watts.

### `NOPS`

Indicates whether the controller processes I/O commands in this power state.

When this field is cleared to `0`, the controller processes I/O commands in this power state. When this field is set to `1`, the controller does not process I/O commands in this power state.

### `Reserved1`

Bits 26:31 are reserved.

### `ENLAT`

Indicates the maximum entry latency in microseconds associated with entering this power state.

### `EXLAT`

Indicates the maximum exit latency in microseconds associated with exiting this power state.

### `RRT`

Indicates the relative read throughput associated with this power state.

The value in this field should be less than the number of supported power states. For example, if the controller supports 16 power states, then the valid values for this field are 0 through 15. A lower value indicates a higher read throughput.

### `Reserved2`

Bits 101:103 are reserved.

### `RRL`

Indicates the relative read latency associated with this power state.

The value in this field should be less than the number of supported power states. For example, if the controller supports 16 power states, then the valid values for this field are 0 through 15. A lower value indicates a lower read latency.

### `Reserved3`

Bits 109:111 are reserved.

### `RWT`

Indicates the relative write throughput associated with this power state.

The value in this field should be less than the number of supported power states. For example, if the controller supports 16 power states, then the valid values for this field are 0 through 15. A lower value indicates a higher write throughput.

### `Reserved4`

Bits 117:119 are reserved.

### `RWL`

Indicates the relative write latency associated with this power state.

The value in this field should be less than the number of supported power states. For example, if the controller supports 16 power states, then the valid values for this field are 0 through 15. A lower value indicates a lower write latency.

### `Reserved5`

Bits 125:127 are reserved.

### `IDLP`

Indicates the typical power consumed by the NVM subsystem over 30 seconds in this power state when idle (for instance, there are no pending commands, register
accesses, or background processes).

The measurement starts after the NVM subsystem has been idle for 10 seconds. The power in Watts is equal to the value in this field multiplied by the scale indicated in the Idle Power Scale (**IPS**) field. A value of `0000h` indicates Idle Power is not reported.

### `Reserved6`

Bits 144:149 are reserved.

### `IPS`

This field indicates the scale for the Idle Power (**IDLP**) field.

The **IPS** field uses the following values:

| Value | Definition |
|-------|------------------------------------|
| 00b | Not reported for this power state. |
| 01b | 0.0001 W |
| 10b | 0.01 W |
| 11b | Reserved |

### `Reserved7`

Bits 152:159 are reserved.

### `ACTP`

Indicates the largest average power consumed by the NVM subsystem over a 10 second period in this power state with the workload indicated in the Active
Power Workload (**APW**) field.

The power in Watts is equal to the value in this field multiplied by the scale indicated in the Active Power Scale (**APS**) field. A value of `0000h` indicates Active Power is not reported.

### `APW`

Indicates the workload used to calculate maximum power for this power state.

The **APW** field uses the following values:

| Value | Definition |
|-------|--------------------------------------------------------------------------------------------------------|
| 00b | No Workload. The workload is unknown or not provided. |
| 01b | Workload #1. Extended Idle Period with a Burst of Random Writes. Workload #1 consists of five (5) minutes of idle followed by thirty-two (32) random write commands of size 1MB submitted to a single controller while all other controllers in the NVM subsystem are idle, and then thirty (30) seconds of idle. |
| 10b | Workload #2: Heavy Sequential Writes. Workload #2 consists of 80,000 sequential write commands of size 128KB submitted to a single controller while all other controllers in the NVM subsystem are idle. The submission queue(s) should be sufficiently large allowing the host to ensure there are multiple commands pending at all times during the workload. |
| 11b | Reserved |

This field will not have a value of **No Workload** unless **ACTP** is `0000h`.

### `Reserved8`

Bits 179:181 are reserved.

### `APS`

Indicates the scale for the Active Power (**ACTP**) field. If an Active Power Workload (**APW**) is reported for a power state, then the Active Power Scale (**APS**) will also be reported for that power state.

The **APS** field uses the following values:

| Value | Definition |
|-------|------------------------------------|
| 00b | Not reported for this power state. |
| 01b | 0.0001 W |
| 10b | 0.01 W |
| 11b | Reserved |

### `Reserved9`

Bits 184:255 are reserved.

## Remarks

## See also