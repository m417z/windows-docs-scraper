# SdpQueryUuid structure

## Description

The **SdpQueryUuid** structure facilitates searching for UUIDs.

## Members

### `u`

Union containing the UUID on which to search.

### `uuidType`

Type of UUID being searched. Must be one of the three valid values from the SDP_SPECIFICTYPE enumeration:

* SDP_ST_UUID16 - indicates u.uuid16 will be used in the search.
* SDP_ST_UUID32 - indicates u.uuid32 will be used in the search.
* SDP_ST_UUID128 - indicates u.uuid128 will be used in the search.

## See also

[BTH_QUERY_SERVICE](https://learn.microsoft.com/windows/desktop/api/ws2bth/ns-ws2bth-bth_query_service)