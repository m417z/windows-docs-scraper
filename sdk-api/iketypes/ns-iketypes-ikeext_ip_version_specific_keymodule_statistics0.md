# IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0 structure

## Description

The **IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS0** structure contains various statistics specific to the keying module and IP version.
[IKEEXT_IP_VERSION_SPECIFIC_KEYMODULE_STATISTICS1](https://learn.microsoft.com/windows/desktop/api/iketypes/ns-iketypes-ikeext_ip_version_specific_keymodule_statistics1) is available.

## Members

### `currentActiveMainModes`

Current number of active Main Mode SAs.

### `totalMainModesStarted`

Total number of Main Mode negotiations.

### `totalSuccessfulMainModes`

Total number of successful Main Mode negotiations.

### `totalFailedMainModes`

Total number of failed Main Mode negotiations.

### `totalResponderMainModes`

Total number of Main Mode negotiations that were externally initiated by a peer.

### `currentNewResponderMainModes`

Current number of newly created responder Main Modes that are still in the initial state.

### `currentActiveQuickModes`

Current number of active Quick Mode SAs.

### `totalQuickModesStarted`

Total number of Quick Mode negotiations.

### `totalSuccessfulQuickModes`

Total number of successful Quick Mode negotiations.

### `totalFailedQuickModes`

Total number of failed Quick Mode negotiations.

### `totalAcquires`

Total number of acquires received from BFE.

### `totalReinitAcquires`

Total number of acquires that were internally reinitiated.

### `currentActiveExtendedModes`

Current number of active extended mode SAs.

### `totalExtendedModesStarted`

Total number of extended mode negotiations.

### `totalSuccessfulExtendedModes`

Total number of successful extended mode negotiations.

### `totalFailedExtendedModes`

Total number of failed extended mode negotiations.

### `totalImpersonationExtendedModes`

Total number of successful extended mode negotiations that used impersonation.

### `totalImpersonationMainModes`

Total number of successful Main Mode mode negotiations that used impersonation.