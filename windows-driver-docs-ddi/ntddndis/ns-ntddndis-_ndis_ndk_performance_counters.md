# _NDIS_NDK_PERFORMANCE_COUNTERS structure

## Description

The **NDIS_NDK_PERFORMANCE_COUNTERS** structure contains the NDK performance counters.

## Members

### `Connect`

The number of outbound connections established. In a bitmask of counters (for example, **MissingCounterMask** member of the [NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities) structure), this is counter 0.

### `Accept`

The number of inbound *RDMA* connections established. In a bitmask of counters (for example, **MissingCounterMask** member of the [NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities) structure), this is counter 1.

### `ConnectFailure`

The number of inbound and outbound *RDMA* connect attempts that failed. In a bitmask of counters, this is counter 2.

### `ConnectionError`

The number of established connections with an error before a consumer disconnected the connection. In a bitmask of counters, this is counter 3.

### `ActiveConnection`

The number of active *RDMA* connections. In a bitmask of counters, this is counter 4.

### `Reserved01`

Reserved.

### `Reserved02`

Reserved.

### `Reserved03`

Reserved.

### `Reserved04`

Reserved.

### `Reserved05`

Reserved.

### `Reserved06`

Reserved.

### `Reserved07`

Reserved.

### `Reserved08`

Reserved.

### `Reserved09`

Reserved.

### `Reserved10`

Reserved.

### `Reserved11`

Reserved.

### `Reserved12`

Reserved.

### `Reserved13`

Reserved.

### `Reserved14`

Reserved.

### `Reserved15`

Reserved.

### `Reserved16`

Reserved.

### `Reserved17`

Reserved.

### `Reserved18`

Reserved.

### `Reserved19`

Reserved.

### `Reserved20`

Reserved.

### `CQError`

The number of *RDMA* completion queue (CQs) that went into an error state. In a bitmask of counters, this is counter 25.

### `RDMAInOctets`

The number of bytes for all incoming *RDMA* traffic. This should include additional layer two protocol overhead. In a bitmask of counters, this is counter 26.

### `RDMAOutOctets`

The number of bytes for all outgoing *RDMA* traffic. This should include additional layer two protocol overhead. In a bitmask of counters, this is counter 27.

### `RDMAInFrames`

The number, in frames, of layer two frames that carry incoming *RDMA* traffic. In a bitmask of counters, this is counter 28.

### `RDMAOutFrames`

The number, in frames, of layer two frames that carry outgoing *RDMA* traffic. In a bitmask of counters, this is counter 29.

## Remarks

The **NDIS_NDK_PERFORMANCE_COUNTERS** structure is used in the **CounterSet** member of the [NDIS_NDK_STATISTICS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_statistics_info) structure.

NDK providers are required to support all the performance counters that are included
in the **NDIS_NDK_PERFORMANCE_COUNTERS** structure. However, in the rare case that
a provider cannot support a counter due to extreme implementation difficulties,
the provider must indicate any unsupported counters with the mask value for the
counter which it cannot support. The **MissingCounterMask** parameter of the [NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities) structure specifies a bitmask that identifies counters that an NDK provider does not support.

All **ReservedXX** counters must be set to zero by providers and are ignored by NDIS. The term *RDMA* refers to all NDKPI and NDSPI activity as well as activity through any other RDMA programming interface that might be exposed by the provider. All providers must report the NDKPI and NDSPI activity with these counters, but reporting activity for other RDMA programming interfaces is not a strict requirement. The term *RDMA traffic* for the RDMA in, out, byte, and frame counters refers to all RDMA activity originating from NDKPI, NDSPI, and other RDMA programming interfaces (if any). This includes reads and writes (that is, direct data placement) as well as sends and receives. This also should also include all of the associated layer two protocol overhead. That is, *RDMA traffic* on an NDK-capable adapter includes all traffic through the adapter except for traffic that is delivered through the standard NDIS send and receive interface and TCP chimney by NDIS protocol drivers.

## See also

[NDIS_NDK_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_capabilities)

[NDIS_NDK_STATISTICS_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddndis/ns-ntddndis-_ndis_ndk_statistics_info)