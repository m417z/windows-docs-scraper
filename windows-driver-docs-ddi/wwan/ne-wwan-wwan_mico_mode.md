## Description

The **WWAN_MICO_MODE** enumeration lists Mobile Initiated Connection modes.

## Constants

### `WwanMicoModeDisabled`

MICO mode is disabled on the device.

### `WwanMicoModeEnabled`

MICO mode is enabled on the device.

### `WwanMicoModeUnsupported`

Used in [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set or query responses only. Indicates that the device does not support MICO mode.

### `WwanMBIMMicoModeDefault`

Used in [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set requests only. Indicates that the default MICO mode in the device (including no MICO mode support) should be used by the device in 5G registration.

### `WwanMicoModeMax`

Indicates an out-of-bound value for this enumeration. All values less than **WwanMicoModeMax** are valid. All values larger than or equal to **WwanMicoModeMax** are invalid.

## Remarks

## See also

[**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info)

[OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params)