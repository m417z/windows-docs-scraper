# _NDIS_WWAN_BASE_STATIONS_INFO_REQ structure

## Description

The **NDIS_WWAN_BASE_STATIONS_INFO_REQ** structure is used in [OID_WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-base-stations-info) query requests to configure aspects of cellular base station information to be used in response.

## Members

### `Header`

The header with type, revision, and size information about the **NDIS_WWAN_BASE_STATIONS_INFO_REQ** structure.
The MB Service sets the header with the values that are shown in the following table when it sends the
data structure to the miniport driver for
*set* operations. Miniport drivers must set the header with the same values when they send the data
structure to the MB service.

| Header submember | Value |
| --- | --- |
| Type | NDIS_OBJECT_TYPE_DEFAULT |
| Revision | NDIS_WWAN_BASE_STATIONS_INFO_REQ_REVISION_1 |
| Size | sizeof(NDIS_WWAN_BASE_STATIONS_INFO_REQ) |

For more information about these members, see
[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header).

### `BaseStationsInfoRequest`

A formatted [WWAN_BASE_STATIONS_INFO_REQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info_req) structure that specifies the aspects of base stations information that are requested.

## See also

[MB base stations information query support](https://learn.microsoft.com/windows-hardware/drivers/network/mb-base-stations-information-query-support)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_WWAN_BASE_STATIONS_INFO](https://learn.microsoft.com/windows-hardware/drivers/network/oid-wwan-base-stations-info)

[WWAN_BASE_STATIONS_INFO_REQ](https://learn.microsoft.com/windows-hardware/drivers/ddi/wwan/ns-wwan-_wwan_base_stations_info_req)