# SdpQueryUuidUnion structure

## Description

The **SdpQueryUuidUnion** union contains the UUID on which to perform an SDP query. Used in conjunction with the **SdpQueryUuid** structure.

## Members

### `uuid128`

UUID in 128-bit format.

### `uuid128.case`

### `uuid128.case.SDP_ST_UUID128`

### `uuid32`

UUID in 32-bit format.

### `uuid32.case`

### `uuid32.case.SDP_ST_UUID32`

### `uuid16`

UUID in 16-bit format.

### `uuid16.case`

### `uuid16.case.SDP_ST_UUID16`

## See also

[BTH_QUERY_SERVICE](https://learn.microsoft.com/windows/desktop/api/ws2bth/ns-ws2bth-bth_query_service)

[SdpQueryUuid](https://learn.microsoft.com/windows/desktop/api/bthsdpdef/ns-bthsdpdef-sdpqueryuuid)