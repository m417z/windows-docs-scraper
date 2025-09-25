# UpdateAssessmentStatus enumeration

## Description

Describes how up-to-date the OS on a device is. **UpdateAssessmentStatus** is used by the [UpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-updateassessment) and [OSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-osupdateassessment) structures, in the **assessmentForCurrent**, **assessmentForUpToDate**, and **securityStatus** members. Exactly one constant is returned.

## Constants

### `UpdateAssessmentStatus_Latest:0`

This result within **assessmentForCurrent** implies that the device is on the latest feature update and quality update available for that device. Within **assessmentForUpToDate**, this result implies that the device is on the latest quality update for the release of Windows it is running.

### `UpdateAssessmentStatus_NotLatestSoftRestriction`

The latest feature update has not been installed due to a soft restriction. When a soft restriction has been placed on an update, the update will not be automatically installed; a user must self-initiate the download within the Update UX. This status only applies to **assessmentForCurrent**.

### `UpdateAssessmentStatus_NotLatestHardRestriction`

The latest feature update has not been installed due to a hard restriction. When a hard restriction has been placed on an update, the update is not applicable to the device. This status only applies to **assessmentForCurrent**.

### `UpdateAssessmentStatus_NotLatestEndOfSupport`

The device is not on the latest update because the device's feature update is no longer supported by Microsoft. When Microsoft stops supporting a feature release, this status will be returned for both **assessmentForCurrent** and **assessmentForUpToDate**.

**Note** When **UpdateAssessmentStatus_NotLatestEndOfSupport** is returned, the assessment's **UpdateImpactLevel** is always **UpdateImpactLevel_High**.

### `UpdateAssessmentStatus_NotLatestServicingTrain`

The device is not on the latest feature update because the device's servicing train limits the device from updating to the latest feature update. For example: if a device is on Current Branch for Business (CBB) and a new feature update has been released for Current Branch (CB), this will be returned. This status only applies to **assessmentForCurrent**.

### `UpdateAssessmentStatus_NotLatestDeferredFeature`

The latest feature update has not been installed due to the device's Windows Update for Business Feature Update Deferral policy. Determining **daysOutOfDate** takes into account deferral policies; **daysOutOfDate** will not begin incrementing until the deferral period has expired. This status only applies to **assessmentForCurrent**.

### `UpdateAssessmentStatus_NotLatestDeferredQuality`

The device is not on the latest quality update due to the device's Windows Update for Business Quality Update Deferral policy. Determining **daysOutOfDate** takes into account deferral policies; **daysOutOfDate** will not begin incrementing until the deferral period has expired.

### `UpdateAssessmentStatus_NotLatestPausedFeature`

The device is not on the latest feature update due to the device having paused Feature Updates. Whether a device is paused is not factored into the calculation of **daysOutOfDate**. This status only applies to **assessmentForCurrent**.

### `UpdateAssessmentStatus_NotLatestPausedQuality`

The device is not on the latest quality update due to the device having paused Quality Updates. Whether a device is paused is not factored into the calculation of **daysOutOfDate**. **daysOutOfDate** does not factor whether a device is paused into its calculation.

### `UpdateAssessmentStatus_NotLatestManaged`

The device is not on the latest update because the approval of updates is not done through Windows Update.

### `UpdateAssessmentStatus_NotLatestUnknown`

The device is not on the latest update due to a reason that cannot be determined by the assessment.

### `UpdateAssessmentStatus_NotLatestTargetedVersion`

The device is not on the latest feature update due to the device's Windows Update for Business Target Version policy. This policy is keeping the device on the targeted feature release version.

## Remarks

This enumeration is used most often with the [UpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-updateassessment) and [OSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-osupdateassessment) structures, which are in turn used with the [GetOSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment) method for [IWaaSAssessor](https://learn.microsoft.com/windows/desktop/api/waasapi/nn-waasapi-iwaasassessor).