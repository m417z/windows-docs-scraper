# _WWAN_UICC_RESPONSE structure

## Description

The **WWAN_UICC_RESPONSE** structure describes a UICC response to a file read or write operation.

## Members

### `Version`

The version number of the structure that follows. In Windows 10, version 1903, this version must be set to **1**.

### `StatusWord1`

A return parameter specific to the UICC command.

### `StatusWord2`

A return parameter specific to the UICC command.

### `ResponseDataSize`

The size of the response data, in bytes.

### `ResponseData`

Used only in Query (read) requests. The buffer containing the response data.

## Remarks

This structure is used in the [**NDIS_WWAN_UICC_RESPONSE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_response) structure.

## See also

[MB UICC application and file system access](https://learn.microsoft.com/windows-hardware/drivers/network/mb-uicc-application-and-file-system-access)

[OID_WWAN_UICC_ACCESS_BINARY](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-binary)

[OID_WWAN_UICC_ACCESS_RECORD](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-uicc-access-record)

[**NDIS_WWAN_UICC_RESPONSE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndiswwan/ns-ndiswwan-_ndis_wwan_uicc_response)