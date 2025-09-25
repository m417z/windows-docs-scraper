## Description

The **NDIS_WWAN_REGISTER_PARAMS_INFO** structure represents data for [**NDIS_STATUS_WWAN_REGISTER_PARAMS_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-register-params-state) notifications.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_REGISTER_PARAMS_INFO** structure.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_REGISTER_PARAMS_INFO_REVISION_1 |
| Size | sizeof(NDIS_WWAN_REGISTER_PARAMS_INFO) |

For more information about these members, see [**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The operation succeeded. |
| WWAN_STATUS_BUSY | The operation failed because the device was busy. In the absence of any explicit information from the function to clear this condition, the host can use subsequent actions by the function (e.g. notifications or command completions) as a hint to retry the failed operation. |
| WWAN_STATUS_FAILURE | The operation failed. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The operation failed because the device does not support this OID. |

### `RegisterParamsInfo`

A formatted [**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info) structure that describes the parameters.

## See also

[**NDIS_STATUS_WWAN_REGISTER_PARAMS_STATE**](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-register-params-state)

[**NDIS_OBJECT_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[**WWAN_REGISTRATION_PARAMS_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-wwan_registration_params_info)