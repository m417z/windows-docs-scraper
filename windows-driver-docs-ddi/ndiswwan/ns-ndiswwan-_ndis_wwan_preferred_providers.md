# _NDIS_WWAN_PREFERRED_PROVIDERS structure

## Description

The NDIS_WWAN_PREFERRED_PROVIDERS structure represents a list of preferred providers including the
number of providers in the list.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PREFERRED_PROVIDERS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PREFERRED_PROVIDERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PREFERRED_PROVIDERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

Miniport driver must set this to WWAN_STATUS_SUCCESS for unsolicited events
(NDIS_STATUS_INDICATION::RequestId = 0). WWAN_STATUS_SUCCESS is also set for successful execution of the
NDIS_WWAN_SET_PREFERRED_PROVIDERS.

The following table shows other possible error status codes (other members need not be updated by
miniport driver).

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_PIN_REQUIRED | Device requires PIN value input. |
| WWAN_STATUS_READ_FAILURE | Reading information from device or SIM card, or both, failed. For example, the SIM card does not have preferred providers information provisioned. |
| WWAN_STATUS_BAD_SIM | Bad SIM detected. |
| WWAN_STATUS_SIM_NOT_INSERTED | SIM not inserted in the device. |
| WWAN_STATUS_NO_DEVICE_SUPPORT | A *set* request is not supported. |

### `PreferredListHeader`

A formatted
[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a
list of preferred providers, including the number of providers in the list.

These point to the list of [WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2) by using the WWAN_LIST_HEADER structure.
**WwanDataClass** flags describe the preference of the specific data access technology and can be set
to any combination within its own cellular class.

Response to
*set* OID_WWAN_PREFERRED_PROVIDERS requests must contain zero elements in the
**PreferenceListHeader**.

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)