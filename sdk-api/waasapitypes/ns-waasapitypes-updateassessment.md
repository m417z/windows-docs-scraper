# UpdateAssessment structure

## Description

[UpdateAssessment](https://learn.microsoft.com/windows/desktop/SysInfo/updateassessmentstatus) contains information that assesses how up-to-date an installed OS is.

## Members

### `status`

An [UpdateAssessmentStatus](https://learn.microsoft.com/windows/desktop/SysInfo/updateassessmentstatus) enumeration detailing how up-to-date the device is, and for what reason.

### `impact`

An  [UpdateImpactLevel](https://learn.microsoft.com/windows/desktop/SysInfo/updateimpactlevel) enumeration detailing whether there is any impact on the device if it has an out-of-date OS.

### `daysOutOfDate`

Describes how much time has elapsed since the device has not installed an applicable update. **daysOutOfDate** is calculated by the current time minus the time since the next applicable update has been released, minus any deferral period. Thus, if an applicable update exists but hasn’t been applied due to deferral, this is accounted for in the calculation. **daysOutOfDate** is used to calculate the update impact level.

## Remarks

This structure is used most often with [OSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-osupdateassessment), which is in turn used with the [GetOSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment) method for [IWaaSAssessor](https://learn.microsoft.com/windows/desktop/api/waasapi/nn-waasapi-iwaasassessor).

When [GetOSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment) is called, an [OSUpdateAssessment](https://learn.microsoft.com/windows/desktop/api/waasapitypes/ns-waasapitypes-osupdateassessment) structure is returned. Within this structure there are two **UpdateAssessment** structures: **assessmentForCurrent** and **assessmentForUpToDate**. The **UpdateAssessment** structure summarizes the assessments to determine whether a device is current or whether it is up-to-date, respectively; this is defined with the [UpdateAssessmentStatus](https://learn.microsoft.com/windows/desktop/SysInfo/updateassessmentstatus) enumeration. The assessment informs how many days the device has been out-of-date with **daysOutofDate**. This date is used to determine if there is any potential impact (represented by the **impact** member in this structure) to the device.