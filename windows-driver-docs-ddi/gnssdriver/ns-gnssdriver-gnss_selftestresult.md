## Description

This structure defines the specific data elements associated with a carrier wave test results returned from the driver.

## Members

### `Size`

Structure size.

### `Version`

Version number.

### `TestResultStatus`

NTSTATUS value indicating:

- Success (self-test passed).

- Failed (indicating the problem detected or indicating that the is test not implemented).

### `Result`

The final result of the self-test.

### `PinFailedBitMask`

The bit mask for adapter pins that failed the test.

### `Unused`

Padding buffer reserved for future use.

### `OutBufLen`

The length of the buffer for returning any additional information about the self-test.

### `OutBuffer`

The buffer that will contain the additional information about the self-test.