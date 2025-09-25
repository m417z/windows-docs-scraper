# _NDIS_WWAN_USSD_EVENT structure

## Description

The NDIS_WWAN_USSD_EVENT structure represents an Unstructured Supplementary Service Data (USSD) NDIS event.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_USSD_EVENT structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_USSD_EVENT_REVISION_1 |
| Size | sizeof(NDIS_WWAN_USSD_EVENT) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

A miniport driver must set this to WWAN_STATUS_SUCCESS for successful OID_WWAN_USSD query execution.

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

### `UssdEvent`

A formatted
[WWAN_USSD_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_event) object that represents a
USSD event.

## See also

[WWAN_USSD_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_ussd_event)