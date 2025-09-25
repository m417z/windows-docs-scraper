# _NDIS_WWAN_PCO_STATUS structure

## Description

The **NDIS_WWAN_PCO_STATUS** structure represents the Protocol Configuration Option (PCO) status of the modem.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_PCO_STATUS** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PCO_STATUS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PCO_STATUS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

The status of system capability. The following table shows the possible values for
this member.

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_SUCCESS | The PCO value operation succeeded. |
| WWAN_STATUS_CONTEXT_NOT_ACTIVATED | The PCO value is not available because the PDP context is not activated. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | The PCO operation is not supported by the modem. |
| WWAN_STATUS_NOT_REGISTERED | The PCO value is not available because the modem is not registered. |
| WWAN_STATUS_PACKET_SVC_DETACHED | The PCO value is not available because no packet service is attached. |
| WWAN_STATUS_RADIO_POWER_OFF | The PCO value not available because the radio is in the OFF state. |
| WWAN_STATUS_BUSY | PCO value is not available because the modem is busy. |
| WWAN_STATUS_NOT_INITIALIZED | The PCO value is not available because the device is initializing. Retry after the ready-state has changed to **WwanReadyStateInitialized.** |
| WWAN_STATUS_NOT_ACTIVATED | The PCO value is not available because the service is not activated. |
| WWAN_STATUS_READ_FAILURE | The PCO value failed due to a read failure. |

### `PcoValue`

A formatted [WWAN_PCO_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pco_value) structure, which contains the PCO information payload from the network as defined in the 3GPP TS24.008 spec.

## See also

[MB Protocol Configuration Options (PCO) operations](https://learn.microsoft.com/windows-hardware/drivers/network/mb-protocol-configuration-options-pco-operations)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_STATUS_WWAN_PCO_STATUS](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-status-wwan-pco-status)

[OID_WWAN_PCO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-pco)

[WWAN_PCO_VALUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_pco_value)