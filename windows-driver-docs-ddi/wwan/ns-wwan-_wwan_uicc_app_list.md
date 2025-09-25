# _WWAN_UICC_APP_LIST structure

## Description

The **WWAN_UICC_APP_LIST** structure describes a list of applications in a UICC and information about them.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `AppCount`

The number of UICC application [**WWAN_UICC_APP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_info) structures being returned in this response.

### `ActiveAppIndex`

The index of the application selected by the modem for registration with the mobile network. This field must be between **0** and **AppCount - 1**. It indexes into the array of applications returned by this response. If no application is selected for registration, this field contains **0xFFFFFFFF**.

### `AppListSize`

The size of the app list data, in bytes.

### `Response`

An array of [**WWAN_UICC_APP_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_uicc_app_info) structures that represent the UICC application list response. Cast this member to **WWAN_UICC_APP_INFO** when retrieving information about an application.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_app_list) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_APP_LIST](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-app-list)

[**NDIS_WWAN_UICC_APP_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_app_list)