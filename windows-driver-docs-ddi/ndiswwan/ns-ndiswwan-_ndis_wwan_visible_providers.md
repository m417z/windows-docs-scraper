# _NDIS_WWAN_VISIBLE_PROVIDERS structure

## Description

The NDIS_WWAN_VISIBLE_PROVIDERS structure represents a list of visible providers and the number of
providers in the list.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_VISIBLE_PROVIDERS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_VISIBLE_PROVIDERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_VISIBLE_PROVIDERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

A miniport driver must set this to WWAN_STATUS_SUCCESS for successful execution of query to the
OID_WWAN_VISIBLE_PROVIDER.

The following table shows the other possible error status codes (other members need not be updated by
miniport driver).

| Value | Meaning |
| --- | --- |
| WWAN_STATUS_PIN_REQUIRED | Device requires PIN value input. |
| WWAN_STATUS_FAILURE | Unable to get visible list. |
| WWAN_STATUS_SIM_NOT_INSERTED | A SIM card is not inserted in the device. |
| WWAN_STATUS_PROVIDERS_NOT_FOUND | No providers are found. Device seems to be in no network coverage. |
| WWAN_STATUS_BUSY | The device is busy and unable to scan. This can happen if the device does a destructive scan (for example, a scan may result in current registered state or PDP activation to be changed to deregister or PDP deactivation). |
| WWAN_STATUS_RADIO_POWER_OFF | Unable to scan. Radio is switched off. |
| WWAN_STATUS_SERVICE_NOT_ACTIVATED | Service activation has failed. Subscription has expired. Device does not allow scanning. |

### `VisibleListHeader`

A formatted
[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header) object that represents a
list of visible providers and the number of providers in the list.

This member points to the list of [WWAN_PROVIDER2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_provider2) structures that use the WWAN_LIST_HEADER structure. **WwanDataClass** flags describe the presence of the specific data access technology and can be set to any combination according to the availability of the data-classes

## See also

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)