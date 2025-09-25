## Description

The **WWAN_DRX_PARAMS** enumeration lists Discontinuous Reception (DRX) settings.

## Constants

### `WwanDRXUnspecified`

The DRX cycle is not specified. In [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set requests, **WwanDRXUnspecified** indicates that the host does not request that the modem use a specific DRX cycle. In set or query responses, **WwanDRXUnspecified** indicates that the device does not know the DRX cycle.

### `WwanDRXNotSupported`

The modem does not support setting a DRX cycle.

### `WwanDRXCycle32`

DRX cycle T=32

### `WwanDRXCycle64`

DRX cycle T=64

### `WwanDRXCycle128`

DRX cycle T=128

### `WwanDRXCycle256`

DRX cycle T=256

### `WwanDRXCycleMax`

Indicates an out-of-bound value for this enumeration. All values less than **WwanDRXCycleMax** are valid. All values larger than or equal to **WwanDRXCycleMax** are invalid.

## Remarks

## See also

[**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info)

[OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params)