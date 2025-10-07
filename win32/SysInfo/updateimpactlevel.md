# UpdateImpactLevel enumeration

Indicates a high, medium, or low impact of a device running an out-of-date OS. This enumeration is generally used by [**UpdateAssessment**](https://learn.microsoft.com/windows/win32/api/waasapitypes/ns-waasapitypes-updateassessment) structures, which is in turn nested inside the returned [**OSUpdateAssessment**](https://learn.microsoft.com/windows/win32/api/waasapitypes/ns-waasapitypes-osupdateassessment) from [**GetOSUpdateAssessment**](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment).

## Constants

**UpdateImpactLevel\_None**

There is no foreseeable impact to your device. This can be because the device is up-to-date, or is not up-to-date because the device is honoring its Windows Update for Business deferral periods, or is out-of-date but has not yet reached the **daysOutOfDate** threshold to reach a higher impact level.

**UpdateImpactLevel\_Low**

The device is not running the latest OS, but has a recent update.

**UpdateImpactLevel\_Medium**

The device is running the latest OS, but has a moderately recent update.

**UpdateImpactLevel\_High**

The device has been out-of-date for a long time. This device may have security vulnerabilities and may be missing important fixes that make Windows run better. When a device is running a version of Windows that is no longer supported, **UpdateImpactLevel\_High** is always returned.

## Remarks

When [**GetOSUpdateAssessment**](https://learn.microsoft.com/windows/desktop/api/waasapi/nf-waasapi-iwaasassessor-getosupdateassessment) is called, an [**OSUpdateAssessment**](https://learn.microsoft.com/windows/win32/api/waasapitypes/ns-waasapitypes-osupdateassessment) structure is returned. Within the structure there is an **assessmentForCurrent** and **assessmentForUpToDate**. Both of these are [**UpdateAssessment**](https://learn.microsoft.com/windows/win32/api/waasapitypes/ns-waasapitypes-updateassessment) structures. Both members have an **UpdateImpactLevel** enumeration, which indicates a high, medium, low or no impact for a device running an out-of-date OS. These levels are determined by the value of **daysOutOfDate**.

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 10, version 1703 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2016 \[desktop apps only\]<br> |
| IDL<br> | WaaSAPI.idl |

