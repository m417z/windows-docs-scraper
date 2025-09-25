# _WWAN_PIN_APP structure

## Description

The **WWAN_PIN_APP** structure specifies the target application ID for a UICC application whose PIN is being queried.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `AppIdLength`

The size of the application ID, in bytes, as defined in Section 8.3 of the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). For 2G cards, this field must be set to zero (0).

### `AppId`

The application ID. Only the first **AppIdLength** bytes are meaningful. If the application ID is longer than **WWAN_UICC_APP_ID_MAX_LEN** bytes, then **AppIdLength** specifies the actual length but only the first **WWAN_UICC_APP_ID_MAX_LEN** bytes are in this field.

## Remarks

This structure is used in the [**NDIS_WWAN_PIN_APP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_pin_app) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_PIN_EX2](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pin-ex2)

[**NDIS_WWAN_PIN_APP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_pin_app)