# IKEEXT_COMMON_STATISTICS1 structure

## Description

The **IKEEXT_COMMON_STATISTICS1** structure contains various statistics common to IKE, Authip, and IKEv2.
[IKEEXT_COMMON_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_common_statistics0) is available.

## Members

### `v4Statistics`

IPv4 common statistics.

See [IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_ip_version_specific_common_statistics1) for more information.

### `v6Statistics`

IPv6 common statistics.

See [IKEEXT_IP_VERSION_SPECIFIC_COMMON_STATISTICS1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_ip_version_specific_common_statistics1) for more information.

### `totalPacketsReceived`

Total number of packets received.

### `totalInvalidPacketsReceived`

Total number of invalid packets received.

### `currentQueuedWorkitems`

Current number of work items that are queued and waiting to be processed.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)