# _WWAN_PIN_ACTION_EX2 structure

## Description

The **WWAN_PIN_ACTION_EX2** structure specifies the PIN action to take for a UICC application.

## Members

### `PinType`

A [**WWAN_PIN_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_type) value that specifies the PIN type for the application.

### `PinOperation`

A [**WWAN_PIN_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_pin_operation) value that specifies the operation to perform on the PIN.

### `Pin`

A string representing the PIN value with which to perform the action, or the PIN value required to enable or disable PIN settings. This field applies for all values of **PinOperation**.

### `NewPin`

A string representing the new PIN value to set when **PinOperation** is **WwanPinOperationChange** or **WwanPinOperationEnter**, for a **PinType** of **WwanPinTypePuk1** or **WwanPinTypePuk2**.

### `AppIdLength`

The size of the application ID, in bytes, as defined in Section 8.3 of the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). For 2G cards, this field must be set to zero (0).

### `AppId`

The application ID. Only the first **AppIdLength** bytes are meaningful. If the application ID is longer than **WWAN_UICC_APP_ID_MAX_LEN** bytes, then **AppIdLength** specifies the actual length but only the first **WWAN_UICC_APP_ID_MAX_LEN** bytes are in this field.

## Remarks

This structure is used in the [**NDIS_WWAN_SET_PIN_EX2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_pin_ex2) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_PIN_EX2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pin-ex2)

[**NDIS_WWAN_SET_PIN_EX2**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_set_pin_ex2)