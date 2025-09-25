## Description

The **BLUETOOTH_OOB_DATA_INFO** structure contains data used to authenticate prior to establishing an Out-of-Band device pairing.

## Members

### `C`

A 128-bit cryptographic key used for two-way authentication.

### `R`

A randomly generated number used for one-way authentication. If this number is not provided by the device initiating the OOB session, this value is 0.

## Remarks

For more details regarding the creation of keys for OOB authentication, see the [Bluetooth Core Specification](https://www.bluetooth.com/specifications/specs/core-specification-5-3/).