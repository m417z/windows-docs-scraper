# _NDIS_NDK_LOCAL_ENDPOINTS structure

## Description

The **NDIS_NDK_LOCAL_ENDPOINTS** structure describes the NDK local endpoints that are on a miniport adapter.

## Members

### `Header`

An [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_NDK_LOCAL_ENDPOINTS** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.
* Set the **Revision** member to **NDIS_NDK_LOCAL_ENDPOINTS_REVISION_1**.
* Set the **Size** member to (USHORT)min(MAXUSHORT, NDIS_SIZEOF_NDK_ENDPOINTS_REVISION_1(n)).

### `Flags`

### `Count`

The number of elements in the endpoints array that is passed in the **LocalEndpoints** member. Each element in the array is an [NDIS_NDK_LOCAL_ENDPOINT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_local_endpoint_entry) structure.

### `NDLocalEndpointsMappedtoTCPLocalEndpoints`

A **BOOLEAN** value that specifies how the endpoints are mapped. If the RDMA technology for the NDK provider requires the provider to map ND local endpoints to TCP local endpoints, the NDK provider must set the **NDLocalEndpointsMappedtoTCPLocalEndpoints** member to TRUE. Otherwise, **NDLocalEndpointsMappedtoTCPLocalEndpoints** is FALSE.

### `LocalEndpoints`

A variable-sized array of [NDIS_NDK_LOCAL_ENDPOINT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_local_endpoint_entry) structures where the size of the array is determined by the number of local endpoints being returned. The **Count** member specifies the number of elements in the local endpoint array.

## Remarks

The **NDIS_NDK_LOCAL_ENDPOINTS** structure is returned with the [OID_NDK_LOCAL_ENDPOINTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-local-endpoints) OID. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this structure.

This structure is variable-sized and contains elements equal in number to the number of local endpoints that are returned. The actual size of the local endpoint array as an element count is indicated by the **Count** member.

If the RDMA technology for the NDK provider requires the provider to map ND local endpoints to TCP local endpoints, the NDK provider must also report the underlying TCP local endpoint for each ND local endpoint as follows:

* Set the **NDLocalEndpointsMappedtoTCPLocalEndpoints** member to TRUE.
* Use two consecutive entries for each ND local endpoint. The first entry contains the ND addressing information (local IP address, and ND port number) and the immediate next entry contains the corresponding TCP local endpoint's addressing information (local IP address, and TCP port number).
* Members other than addressing information (For example, **UserModeOwner**, **Listener** and **OwnerPid**) must be set only in the first entry and left untouched in the next entry. Therefore, entries at index 0, 2, 4, and so on, contain ND addressing information (plus properly filled-in other members) and entries at index 1, 3, 5 and so on, contain TCP addressing info (where other members are left untouched).

## See also

[NDIS_NDK_LOCAL_ENDPOINT_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_local_endpoint_entry)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request)

[OID_NDK_LOCAL_ENDPOINTS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-local-endpoints)