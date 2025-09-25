# KeyCredentialManagerOperationErrorStates enumeration

## Description

Enumeration of Error states returned by the function [KeyCredentialManagerGetOperationErrorStates](https://learn.microsoft.com/windows/win32/api/keycredmgr/nf-keycredmgr-keycredentialmanagergetoperationerrorstates) as flags.

## Constants

### `KeyCredentialManagerOperationErrorStateNone:0x0`

No Error. Equivalent to **ERROR_SUCCESS**.

### `KeyCredentialManagerOperationErrorStateDeviceJoinFailure:0x01`

WHFB enrollment will successfully complete because the device is not properly joined to Azure or the Enterprise.

### `KeyCredentialManagerOperationErrorStateTokenFailure:0x02`

WHFB enrollment will not successfully complete because the user could not get a token from Azure or the Enterprise.

### `KeyCredentialManagerOperationErrorStateCertificateFailure:0x04`

WHFB enrollment will not successfully complete because the certificate authority and/or certificate template could not be found.

### `KeyCredentialManagerOperationErrorStateRemoteSessionFailure:0x08`

WHFB enrollment will not successfully complete because the current session is a remote session.

### `KeyCredentialManagerOperationErrorStatePolicyFailure:0x10`

WHFB enrollment will not successfully complete because there was an error reading MDM or Group Policy.

### `KeyCredentialManagerOperationErrorStateHardwareFailure:0x20`

WHFB enrollment will not successful complete because the device does not have the required hardware.

### `KeyCredentialManagerOperationErrorStatePinExistsFailure:0x40`

WHFB is already enrolled on this device.