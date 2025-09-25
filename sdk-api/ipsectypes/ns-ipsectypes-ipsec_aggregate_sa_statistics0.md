# IPSEC_AGGREGATE_SA_STATISTICS0 structure

## Description

The **IPSEC_AGGREGATE_SA_STATISTICS0** structure stores aggregate IPsec kernel security association (SA) statistics.

## Members

### `activeSas`

Number of active SAs.

### `pendingSaNegotiations`

Number of pending SA negotiations.

### `totalSasAdded`

Total number of SAs added.

### `totalSasDeleted`

Total number of SAs deleted.

### `successfulRekeys`

Number of successful re-keys.

### `activeTunnels`

Number of active tunnels.

### `offloadedSas`

Number of offloaded SAs.

## Remarks

**IPSEC_AGGREGATE_SA_STATISTICS0** is a specific implementation of IPSEC_AGGREGATE_SA_STATISTICS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)