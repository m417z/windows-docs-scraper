# _WWAN_UICC_APP_INFO structure

## Description

The **WWAN_UICC_APP_INFO** structure describes information about a UICC application.

## Members

### `AppType`

A [**WWAN_UICC_APP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_app_type) value that specifies the type of the UICC application.

### `AppIdSize`

The size of the application ID in bytes, as defined in Section 8.3 of the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). This field is set to zero (0) for the **WwanUiccAppTypeMf**, **WwanUiccAppTypeMfSIM**, or **WwanUiccAppTypeMfRUIM** app types.

### `AppId`

The application ID. Only the first **AppIdSize** bytes are meaningful. If the application ID is longer than **WWAN_UICC_APP_ID_MAX_LEN** bytes, then **AppIdSize** specifies the actual length but only the first **WWAN_UICC_APP_ID_MAX_LEN** bytes are in this field. This field is valid only when **AppType** is not **WwanUiccAppTypeMf**, **WwanUiccAppTypeMfSIM**, or **WwanUiccAppTypeMfRUIM**.

### `AppNameLength`

The length, in characters, of the application name.

### `AppName`

A UTF-8 string specifying the name of the application. The length of this field is specified by **AppNameLength**. If the length is greater than or equal to **WWAN_UICC_APP_NAME_MAX_LEN** bytes, this field contains the first **WWAN_UICC_APP_NAME_MAX_LEN - 1** bytes of the name. The string is always null-terminated.

### `NumPins`

The number of application PIN references. In other words, the number of elements of **PinRef** that are valid. Applications on a virtual R-UIM have no PIN references.

### `PinRef`

A byte array specifying the application PIN references for this application (keys for PIN1 and possibly UPIN), as defined in Section 9.4.2 of the [ETSI TS 102 221 technical specification](https://go.microsoft.com/fwlink/p/?linkid=864594). In the case of a single-verification card, or an MBB driver and/or modem that does not support different application keys for different applications, this field must be **0x01**.

## Remarks

This structure is used in the [**WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_list) structure.

The following constants are defined in the Wwan.h header for this structure.

`#define WWAN_UICC_APP_ID_MAX_LEN 32`
`#define WWAN_UICC_APP_NAME_MAX_LEN 256`
`#define WWAN_UICC_PINREF_MAX 8`

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-app-list)

[**WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_list)

[**WWAN_UICC_APP_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-_wwan_uicc_app_type)