# IKEEXT_KEYMODULE_STATISTICS1 structure

## Description

The **IKEEXT_KEYMODULE_STATISTICS1** structure contains various statistics specific to the keying module.
[IKEEXT_KEYMODULE_STATISTICS0](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_keymodule_statistics0) is available.

## Members

### `v4Statistics`

IPv4 common statistics.

See [IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_ip_version_specific_keymodule_statistics1) for more information.

### `v6Statistics`

IPv6 common statistics.

See [IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/win32/api/iketypes/ns-iketypes-ikeext_ip_version_specific_keymodule_statistics1) for more information.

### `errorFrequencyTable`

Table containing the frequencies of various IKE Win32 error codes encountered during negotiations. The error codes range from ERROR_IPSEC_IKE_NEG_STATUS_BEGIN to ERROR_IPSEC_IKE_NEG_STATUS_END.

The table size, IKEEXT_ERROR_CODE_COUNT, is 84 (ERROR_IPSEC_IKE_NEG_STATUS_END - ERROR_IPSEC_IKE_NEG_STATUS_BEGIN).

### `mainModeNegotiationTime`

Current Main Mode negotiation time.

### `quickModeNegotiationTime`

Current Quick Mode negotiation time.

### `extendedModeNegotiationTime`

Current Extended Mode negotiation time. This member is applicable for AuthIp only.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)