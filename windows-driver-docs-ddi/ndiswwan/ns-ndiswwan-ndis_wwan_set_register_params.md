## Description

The **NDIS_WWAN_SET_REGISTER_PARAMS** structure represents data for [**OID_WWAN_REGISTER_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set requests.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_SET_REGISTER_PARAMS** structure. The MB Service sets the header with the values that are shown in the following table when it sends the data structure to the miniport driver for set operations.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_SET_REGISTER_PARAMS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_SET_REGISTER_PARAMS) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `SetRegisterParams`

A formatted [**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info) structure that describes the parameters.

## See also

[**OID_WWAN_REGISTER_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info)