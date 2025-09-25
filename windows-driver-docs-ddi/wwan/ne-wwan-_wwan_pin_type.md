# _WWAN_PIN_TYPE enumeration

## Description

The **WWAN_PIN_TYPE** enumeration specifies the PIN type for a UICC application.

## Constants

### `WwanPinTypeNone`

No PIN is pending to be entered.

### `WwanPinTypeCustom`

The PIN type is a custom type and is none of the other PIN types listed in this enumeration.

### `WwanPinTypePin1`

The PIN1 key.

### `WwanPinTypePin2`

The PIN2 key.

### `WwanPinTypeDeviceSimPin`

The device to SIM key.

### `WwanPinTypeDeviceFirstSimPin`

The device to very first SIM key.

### `WwanPinTypeNetworkPin`

The network personalization key.

### `WwanPinTypeNetworkSubsetPin`

The network subset personalization key.

### `WwanPinTypeSvcProviderPin`

The service provider (SP) personalization key.

### `WwanPinTypeCorporatePin`

The corporate personalization key.

### `WwanPinTypeSubsidyLock`

The subsidy unlock key.

### `WwanPinTypePuk1`

The Personal Identification Number 1 Unlock Key (PUK1).

### `WwanPinTypePuk2`

The Personal Identification Number 2 Unlock Key (PUK2).

### `WwanPinTypeDeviceFirstSimPuk`

The device to very first SIM PIN unlock key.

### `WwanPinTypeNetworkPuk`

The network personalization unlock key.

### `WwanPinTypeNetworkSubsetPuk`

The network subset personalization unlock key.

### `WwanPinTypeSvcProviderPuk`

The service provider (SP) personalization unlock key.

### `WwanPinTypeCorporatePuk`

The corporate personalization unlock key.

### `WwanPinTypeNev`

The NEV key.

### `WwanPinTypeAdm`

The administrative key.

### `WwanPinTypeMax`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the following structures:

- [**WWAN_PIN_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_info)
- [**WWAN_PIN_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action)
- [**WWAN_PIN_ACTION_EX2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action_ex2)

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_PIN_EX2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pin-ex2)

[**WWAN_PIN_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_info)

[**WWAN_PIN_ACTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action)

[**WWAN_PIN_ACTION_EX2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pin_action_ex2)