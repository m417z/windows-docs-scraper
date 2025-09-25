## Description

The **WWAN_REGISTRATION_PARAMS_INFO** structure represents parameters that an MB device uses during 5G registration requests. A host typically sends an [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set request with a **WWAN_REGISTRATION_PARAMS_INFO** structure to configure a device with the desired registration parameters.

## Members

### `MicoMode`

A value from the [**WWAN_MICO_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_mico_mode) enumeration that represents the Mobile Initiated Connection (MICO) mode requested by the host.

### `DRXParam`

A value from the [**WWAN_DRX_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_drx_params) enumeration that represents the configuration of Discontinuous Reception (DRX) settings requested by the host.

### `LADNInfo`

A value from the [**WWAN_LADN_IND_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_ladn_ind_request) enumeration that represents the Local Area Data Networks (LADN) information requested by the host.

### `DefaultPDUSessionHint`

A value from the [**WWAN_DEFAULT_PDU_SESSION_HINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_default_pdu_session_hint) enumeration that represents a hint that the host will possibly establish the default protocol data unit (PDU) session immediately after the registration is complete. Since this depends on several policies, it may not happen.

### `ReRegisterIfNeeded`

This is a forced re-registration indicator.

When this structure is used with [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set requests:

* If the value is **1** and the device is currently registered or in the middle of registration, the modem shall evaluate whether any of the registration parameters contained in this set request are different than those used in the previous registration request toward the network. If the parameters are different, the modem shall de-register from the network and re-register using the current registration parameters. All normal procedures related to de-registration and registration, including sending appropriate events at appropriate times, shall be performed.

* A value of **0** indicates that forced re-registration is not requested.

* This is a one-time indicator. The modem shall use this only once upon receiving this set request.

All other values are reserved.

### `PreConfiguredNSSAIListHeader`

A [**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a pre-configured Single Network Slice Selection Assistance Information (S-NSSAI). The host will send exactly one S-NSSAI if the modem has zero pre-configured default S-NSSAIs.

### `OSId`

A GUID that represents the OS Id. A value of **0** means MBIM_TLV_TYPE_OSID is not contained in the MBIM_CID_MS_REGISTRATION_PARAMS payload.

## Remarks

The **WWAN_REGISTRATION_PARAMS_INFO** structure is used in [OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params) set and query requests and [NDIS_STATUS_WWAN_REGISTER_PARAMS_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-register-params-state) notifications.

## See also

[OID_WWAN_REGISTER_PARAMS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-register-params)

[NDIS_STATUS_WWAN_REGISTER_PARAMS_STATE](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-register-params-state)

[**WWAN_MICO_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_mico_mode)

[**WWAN_DRX_PARAMS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_drx_params)

[**WWAN_LADN_IND_REQUEST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_ladn_ind_request)

[**WWAN_DEFAULT_PDU_SESSION_HINT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ne-wwan-wwan_default_pdu_session_hint)

[**WWAN_LIST_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)