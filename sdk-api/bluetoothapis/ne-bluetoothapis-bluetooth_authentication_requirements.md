## Description

The **BLUETOOTH_AUTHENTICATION_REQUIREMENTS** enumeration specifies the 'Man in the Middle' protection required for authentication.

**Note** This enumeration is supported in Windows Vista SP2 and Windows 7.

## Constants

### `BLUETOOTH_MITM_ProtectionNotRequired:0`

Protection against a "Man in the Middle" attack is not required for authentication.

### `BLUETOOTH_MITM_ProtectionRequired:0x1`

Protection against a "Man in the Middle" attack is required for authentication.

### `BLUETOOTH_MITM_ProtectionNotRequiredBonding:0x2`

Protection against a "Man in the Middle" attack is not required for bonding.

### `BLUETOOTH_MITM_ProtectionRequiredBonding:0x3`

Protection against a "Man in the Middle" attack is required for bonding.

### `BLUETOOTH_MITM_ProtectionNotRequiredGeneralBonding:0x4`

Protection against a "Man in the Middle" attack is not required for General Bonding.

### `BLUETOOTH_MITM_ProtectionRequiredGeneralBonding:0x5`

Protection against a "Man in the Middle" attack is required for General Bonding.

### `BLUETOOTH_MITM_ProtectionNotDefined:0xff`

Protection against "Man in the Middle" attack is not defined.

## Remarks

The header file associated with this API is available at Microsoft Connect via the Windows Vista Feature Pack for Wireless Developers Supplement download. Access to this resource requires registration with the Microsoft Connect website. The header is also included in the comprehensive developer resource packages available via the Windows Driver Kit (WDK), Windows Logo Kit (WLK) and Windows Driver Framework (WDF) Connections at Microsoft Connect.

## See also

[BluetoothAuthenticateDeviceEx](https://learn.microsoft.com/windows/desktop/api/bluetoothapis/nf-bluetoothapis-bluetoothauthenticatedeviceex)