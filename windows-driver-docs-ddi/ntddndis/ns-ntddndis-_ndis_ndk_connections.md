# _NDIS_NDK_CONNECTIONS structure

## Description

The **NDIS_NDK_CONNECTIONS** structure describes the NDK connections that are active on a miniport adapter.

## Members

### `Header`

An [NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header) structure that describes this **NDIS_NDK_CONNECTIONS** structure. Set the members of the **NDIS_OBJECT_HEADER** structure as follows:

* Set the **Type** member to **NDIS_OBJECT_TYPE_DEFAULT**.
* Set the **Revision** member to **NDIS_NDK_CONNECTIONS_REVISION_1**.
* Set the **Size** member to (USHORT)min(MAXUSHORT, NDIS_SIZEOF_NDK_CONNECTIONS_REVISION_1(n)).

### `Flags`

### `Count`

The number of elements in the connection array that is passed in the **Connections** member. Each element in the array is an [NDIS_NDK_CONNECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_connection_entry) structure.

### `NDConnectionsMappedtoTCPConnections`

A BOOLEAN value that specifies how the connections are mapped. If the RDMA technology for the NDK provider requires the provider to map ND connections to TCP connections, the NDK provider must set the **NDConnectionsMappedtoTCPConnections** member to TRUE. Otherwise, **NDConnectionsMappedtoTCPConnections** is FALSE.

### `Connections`

A variable-sized array of [NDIS_NDK_CONNECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_connection_entry) structures where the size of the array is determined by the number of connections being returned. The **Count** member specifies the number of elements in the connection array.

## Remarks

The **NDIS_NDK_CONNECTIONS** structure is returned with the [OID_NDK_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-connections) OID. The **InformationBuffer** member of the [NDIS_OID_REQUEST](https://learn.microsoft.com/windows-hardware/drivers/ddi/oidrequest/ns-oidrequest-ndis_oid_request) structure contains a pointer to this structure.

This structure is variable-sized and contains elements equal in number to the number of connections that are returned. The actual size of the connection array as an element count is indicated by the **Count** member.

If the RDMA technology for the NDK provider requires the provider to map ND connections to TCP connections, the NDK provider must also report the underlying TCP connection 4-tuple for each ND connection as follows:

* Set the **NDConnectionsMappedtoTCPConnections** member to TRUE.
* Use two consecutive entries for each ND connection. The first entry contains the ND addressing information (local and remote IP address, and ND port number) and the immediate next entry contains the corresponding TCP connection's addressing information (local and remote IP address, and TCP port number).
* Members other than addressing information (For example, **UserModeOwner** and **OwnerPid**) must be set only in the first entry and left untouched in the next entry. Therefore, entries at index 0, 2, 4, and so on, contain ND addressing information (plus properly filled-in other members) and entries at index 1, 3, 5 and so on, contain TCP addressing info (where other members are left untouched).

## See also

[NDIS_NDK_CONNECTION_ENTRY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_connection_entry)

[NDIS_OBJECT_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/objectheader/ns-objectheader-ndis_object_header)

[OID_NDK_CONNECTIONS](https://learn.microsoft.com/windows-hardware/drivers/network/oid-ndk-connections)