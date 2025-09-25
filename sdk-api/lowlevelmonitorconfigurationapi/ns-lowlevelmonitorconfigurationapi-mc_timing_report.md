# MC_TIMING_REPORT structure

## Description

Contains information from a monitor's timing report.

## Members

### `dwHorizontalFrequencyInHZ`

The monitor's horizontal synchronization frequency in Hz.

### `dwVerticalFrequencyInHZ`

The monitor's vertical synchronization frequency in Hz.

### `bTimingStatusByte`

Timing status byte. For more information about this value, see the Display Data Channel Command Interface (DDC/CI) standard.

## See also

[GetTimingReport](https://learn.microsoft.com/windows/desktop/api/lowlevelmonitorconfigurationapi/nf-lowlevelmonitorconfigurationapi-gettimingreport)

[Monitor Configuration Structures](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-structures)