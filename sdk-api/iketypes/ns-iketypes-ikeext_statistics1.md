## Description

The [IKEEXT_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_statistics0) structure stores various IKE, AuthIP, and IKEv2 statistics.
[IKEEXT_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_statistics0) is the specific implementation of IKEEXT_STATISTICS used in Windows 7 and later. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information. For Windows Vista, **IKEEXT_STATISTICS0** is available.

## Members

### `ikeStatistics`

Statistics specific to IKE.

See [IKEEXT_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_keymodule_statistics1) for more information.

### `authipStatistics`

Statistics specific to AuthIP.

See [IKEEXT_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_keymodule_statistics1) for more information.

### `ikeV2Statistics`

Statistics specific to IKEv2.

See [IKEEXT_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_keymodule_statistics1) for more information.

### `commonStatistics`

Statistics common to IKE, AuthIP, and IKEv2.

See [IKEEXT_COMMON_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_common_statistics1) for more information.

## See also

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)