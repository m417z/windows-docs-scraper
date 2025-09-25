# IPSEC_TRAFFIC_STATISTICS1 structure

## Description

The **IPSEC_TRAFFIC_STATISTICS1** structure stores IPsec traffic statistics.
[IPSEC_TRAFFIC_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/ipsectypes/ns-ipsectypes-ipsec_traffic_statistics0) is available.

## Members

### `encryptedByteCount`

Specifies encrypted byte count.

### `authenticatedAHByteCount`

Specifies authenticated AH byte count.

### `authenticatedESPByteCount`

Specifies authenticated ESP byte count.

### `transportByteCount`

Specifies transport byte count.

### `tunnelByteCount`

Specifies tunnel byte count.

### `offloadByteCount`

Specifies offload byte count.

### `totalSuccessfulPackets`

The total number of packets that were successfully transmitted.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)