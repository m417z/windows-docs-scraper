# _NDIS_WWAN_PREFERRED_MULTICARRIER_PROVIDERS structure

## Description

The NDIS_WWAN_PREFERRED_MULTICARRIER_PROVIDERS structure represents a list of preferred multi-carrier providers and the number of providers in the list.

## Members

### `Header`

The header with type, revision, and size information about the NDIS_WWAN_PREFERRED_MULTICARRIER_PROVIDERS
structure. The MB Service sets the header with the values that are shown in the following table when it
sends the data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_PREFERRED_MULTICARRIER_PROVIDERS_REVISION_1 |
| Size | sizeof(NDIS_WWAN_PREFERRED_MULTICARRIER_PROVIDERS) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `uStatus`

Miniport drivers must set this member to WWAN_STATUS_SUCCESS for unsolicited events. WWAN_STATUS_SUCCESS is also specified for successful execution of OID_WWAN_PREFERRED_MULTICARRIER_PROVIDERS *set* requests. The following table shows other possible error status codes (other members need not be updated by miniport driver):

|  |  |
| --- | --- |
| **Value** | **Meaning** |
| WWAN_STATUS_READ_FAILURE | Reading information from the device failed |
| WWAN_STATUS_NO_DEVICE_SUPPORT | A *set* request is not supported |

### `PreferredListHeader`

 A formatted WWAN_LIST_HEADER object that represents a list of preferred multi-carrier providers, including the number of providers in the list.

These point to the list of the WWAN_PROVIDER2 by using the WWAN_LIST_HEADER structure. **WwanDataClass** flags describe the preference of the specific data access technology and can be set to any combination within its own cellular class.
Response to [OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers)*set*  requests must contain zero elements in the **PreferredListHeader**.

## See also

[OID_WWAN_PREFERRED_PROVIDERS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-preferred-providers)

[WWAN_LIST_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_list_header)