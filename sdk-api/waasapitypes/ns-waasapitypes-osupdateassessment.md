# OSUpdateAssessment structure

## Description

The **OSUpdateAssessment** structure defines how up-to-date the OS on a targeted device is. This structure is used primarily as a return value by [GetOSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment), in order to retrieve an OS assessment in a single structure.

## Members

### `isEndOfSupport`

**true** if the OS on the device is no longer supported by Microsoft and will no longer receive servicing updates; otherwise, **false**.

### `assessmentForCurrent`

An [UpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-updateassessment) structure containing an assessment against the latest update Microsoft has released.

### `assessmentForUpToDate`

An [UpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-updateassessment) structure containing an assessment against the latest applicable quality update for the device.

### `securityStatus`

An [UpdateAssessmentStatus](https://learn.microsoft.com/windows/desktop/SysInfo/updateassessmentstatus) enumeration that details whether the device is on the latest applicable security update.

### `assessmentTime`

Timestamp when the assessment was done.

### `releaseInfoTime`

Timestamp when the release information was updated.

### `currentOSBuild`

The latest OS build that Microsoft has released. This value is used to determine whether a device is current.

### `currentOSReleaseTime`

The published timestamp of the release date for current OS build.

### `upToDateOSBuild`

The latest applicable OS build in the device's servicing train. This value is used to determine whether a device is up-to-date.

### `upToDateOSReleaseTime`

The published timestamp of the release date for the up-to-date OS build.