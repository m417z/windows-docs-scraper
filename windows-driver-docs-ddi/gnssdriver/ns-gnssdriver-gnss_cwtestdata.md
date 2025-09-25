## Description

This structure defines specific data elements associated with carrier wave test results returned from the driver.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `TestResultStatus`

NTSTATUS value indicating whether this fix contains a valid data, or if the GNSS engine or driver encountered any errors in getting the measurements for the carrier wave test.

- Success - carrier wave test successfully started.

- Failed - with error code: test not implemented, carrier wave test already in progress, fix session in progress, or other failure.

### `SignalToNoiseRatio`

Signal to noise ratio in the carrier wave in dB-Hz.

### `Frequency`

Frequency of the carrier wave detected in the measurement band.

This frequency is provided as a difference to GPS frequency (1575.42 MHz) in kHz.

### `Unused`

Padding buffer reserved for future use.