# BTH_QUERY_SERVICE structure

## Description

The
**BTH_QUERY_SERVICE** structure is used to query a Bluetooth service.

## Members

### `type`

Type of service to perform. Choose from the following:

* SDP_SERVICE_SEARCH_REQUEST
* SDP_SERVICE_ATTRIBUTE_REQUEST
* SDP_SERVICE_SEARCH_ATTRIBUTE_REQUEST

### `serviceHandle`

Service handle on which to query the attributes specified in the **pRange** member. Used only for attribute searches.

### `uuids`

UUIDs that a record must contain to match the search. Used for service and service attribute searches. When querying less than MAX_UUIDS_IN_QUERY UUIDs, set the **SdpQueryUuid** element immediately following the last valid UUID to all zeros. Used only for attribute and service attribute searches.

### `numRange`

Number of elements in **pRange**. Used only for attribute and service attribute searches.

### `pRange`

Attribute values to retrieve for any matching records, in the form of an array of
**SdpAttributeRange** structures. Attributes are defined in the Bluetooth specification. See Remarks.

## Remarks

The **pRange** member is an open-ended array specifying a sparse set of attributes to return from the query. It is an application's responsibility to provide a nonoverlapping array that is sorted in ascending order of attribute ID, without duplicates.

See
[www.bluetooth.com](https://www.bluetooth.com/) for more information about the Bluetooth specification.

## See also

[Bluetooth and WSALookupServiceBegin for Service
Discovery](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsalookupservicebegin-for-service-discovery)

[Bluetooth and WSAQUERYSET for Service Inquiry](https://learn.microsoft.com/windows/desktop/Bluetooth/bluetooth-and-wsaqueryset-for-service-inquiry)