## Description

The **VIDEO_PORT_CACHE_TYPE** enumeration specifies the type of caching that the system should use.

## Constants

### `VpNonCached`

The system should not cache the range of addresses.

### `VpWriteCombined`

The system should use write-combined (WC) caching. For information about WC caching, see the [Write-Combining Memory in Video Miniport Drivers](https://learn.microsoft.com/previous-versions/windows/hardware/design/dn642116(v=vs.85)).

### `VpCached`

The system should use oridinary caching.

## See also

[**AgpReservePhysical**](https://learn.microsoft.com/windows-hardware/drivers/ddi/videoagp/nc-videoagp-pagp_reserve_physical)