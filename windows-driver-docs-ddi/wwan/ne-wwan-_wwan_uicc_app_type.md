# _WWAN_UICC_APP_TYPE enumeration

## Description

The **WWAN_UICC_APP_TYPE** enumeration specifies the type for a UICC application.

## Constants

### `WwanUiccAppTypeUnknown`

Unknown type.

### `WwanUiccAppTypeMf`

Legacy SIM directories rooted at the MF.

### `WwanUiccAppTypeMfSIM`

Legacy SIM directories rooted at the DF_GSM.

### `WwanUiccAppTypeMfRUIM`

Legacy SIM directories rooted at the DF_CDMA.

### `WwanUiccAppTypeUSIM`

A USIM application.

### `WwanUiccAppTypeCSIM`

A CSIM application.

### `WwanUiccAppTypeISIM`

An ISIM application.

### `WwanUiccAppTypeMax`

The maximum value for this enumeration.

## Remarks

This enumeration is used in the [**WWAN_UICC_APP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_info) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-app-list)

[**WWAN_UICC_APP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_info)