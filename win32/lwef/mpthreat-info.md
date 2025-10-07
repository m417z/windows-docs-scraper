# MPTHREAT\_INFO structure

Contains information about a threat.

## Members

**ThreatID**

Type: **MPTHREAT\_ID**

Threat identifier. Upper bit is set to identify antivirus-related threats.

**DetectionID**

Type: **GUID**

Detection ID.

**Name**

Type: **MP\_MIDL\_STRING LPWSTR**

Threat name.

**ThreatType**

Type: **[**MPTHREAT\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-type)**

Threat type. Used to differentiate among different threat types such as known bad, unknown, or known good. See [**MPTHREAT\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-type).

**ThreatCriticality**

Type: **[**MPTHREAT\_SEVERITY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-severity)**

Threat criticality. See [**MPTHREAT\_SEVERITY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-severity).

**ThreatCategory**

Type: **[**MPTHREAT\_CATEGORY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-category)**

Threat category, such as a trojan or a keylogger. See [**MPTHREAT\_CATEGORY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-category).

**ThreatShortDescriptionID**

Type: **DWORD**

Threat short description ID.

**ThreatAdviseDescriptionID**

Type: **DWORD**

Threat advise description ID.

**ThreatStatus**

Type: **[**MPTHREAT\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-status)**

Threat status such as detected, cleaned, or quarantined. See [**MPTHREAT\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-status).

**SuggestedActionCount**

Type: **DWORD**

Count of suggested actions in **SuggestedActionArray**.

**SuggestedActionArray**

Type: **[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)\[MP\_MAX\_SUGGESTIONS\]**

Array of suggested actions. See [**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action).

**ResourceCount**

Type: **DWORD**

Count of resources in **ResourceList**.

**ResourceList**

Type: **PMPRESOURCE\_INFO\***

List of resources identified with the threat. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

**ThreatStatusTime**

Type: **ULARGE\_INTEGER**

Time when threat status last changed.

**ThreatStatusCode**

Type: **HRESULT**

Status code associated with the threat status.

**ThreatDetection**

Type: **[**MPTHREAT\_DETECTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-detection)**

Threat detection type, such as concrete, suspicious, or generic. See [**MPTHREAT\_DETECTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-detection).

**QuarantineGuid**

Type: **GUID**

Quarantine guid.

**ExecutionStatus**

Type: **[**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status)**

Execution status of the threat, such as not known, blocked, or active. See [**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status).

**Data**

Extra information. The pointer to the appropriate structure depends on the value of **ThreatType**.

**pKnownBad**

Type: **PMPTHREAT\_INFOEX\_UNUSED**

When **ThreatType** == **MPTHREAT\_TYPE\_KNOWNBAD**. See [**MPTHREAT\_INFOEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-unused).

**pBehavior**

Type: **PMPTHREAT\_INFOEX\_BEHAVIOR**

When **ThreatType** == **MPTHREAT\_TYPE\_BEHAVIOR**. See [**MPTHREAT\_INFOEX\_BEHAVIOR**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-behavior).

**pUnknown**

Type: **PMPTHREAT\_INFOEX\_UNUSED**

When **ThreatType** == **MPTHREAT\_TYPE\_UNKNOWN**. See [**MPTHREAT\_INFOEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-unused).

**pKnownGood**

Type: **PMPTHREAT\_INFOEX\_UNUSED**

When **ThreatType** == MPTHREAT\_TYPE\_KNOWNGOOD. See [**MPTHREAT\_INFOEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-unused).

**pNis**

Type: **PMPTHREAT\_INFOEX\_NIS**

When **ThreatType** == **MPTHREAT\_TYPE\_NIS**. See [**MPTHREAT\_INFOEX\_NIS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-nis).

**State**

Type: **[**MPDETECTION\_STATE**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-state)**

The current state of the detection. See [**MPDETECTION\_STATE**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-state).

**DetectionUser**

Type: **MP\_MIDL\_STRING LPWSTR**

The user associated with the detection, in the format "domain/user".

**DetectionSource**

Type: **[**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource)**

The source of the detection. See [**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource).

**ProcessName**

Type: **MP\_MIDL\_STRING LPWSTR**

Process name associated with the detection.

**DetectionOrigin**

Type: **[**MPDETECTION\_ORIGIN**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-origin)**

The origin of the detection, such as local or network. See [**MPDETECTION\_ORIGIN**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-origin).

**reserved1**

Type: **DWORD**

Reserved metadata about the detection.

**DetectionTime**

Type: **ULARGE\_INTEGER**

The time of the initial detection.

**PreExecutionStatus**

Type: **[**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status)**

Execution status right before remediation. See [**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status).

**RemediationTime**

Type: **ULARGE\_INTEGER**

The time remediation occured.

**PostExecutionStatus**

Type: **[**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status)**

Execution status after remediation. See [**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status).

**CriticalFailure**

Type: **BOOL**

True if the remediation failure was critical.

**NonCriticalReason**

Type: **DWORD**

The reason the remediation failure is not critical. This is not guaranteed to be supported in the future.

**RemediationUser**

Type: **MP\_MIDL\_STRING LPWSTR**

User that requested the remediation, in the format "domain/user".

**RemediationResourceCount**

Type: **DWORD**

Count of resources in **RemediationResourceList**.

**RemediationResourceList**

Type: **PMPRESOURCE\_INFO\[RemediationResourceCount\]**

List of resources that failed during remediation. See [**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info).

**FailureResolved**

Type: **BOOL**

True if remediation failure been resolved. This will move the bucket to either complete or an additional action.

**ResolvedReason**

Type: **[**MPRESOLVED\_REASON**](https://learn.microsoft.com/windows/win32/lwef/mpresolved-reason)**

Reason for remediation failure being resolved. This is the reason the detection moved from failed to additional action or finished. See [**MPRESOLVED\_REASON**](https://learn.microsoft.com/windows/win32/lwef/mpresolved-reason).

**AdditionalActions**

Type: **DWORD**

Are additional actions required.

**ResolvedActions**

Type: **DWORD**

Any additional actions that have been performed.

**dwThreatStatusFlag**

Type: **DWORD**

Additonal information about the threat detection.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 \[desktop apps only\]<br> |
| Header<br> | MpClient.h |

## See also

[**MpFreeMemory**](https://learn.microsoft.com/windows/win32/lwef/mpfreememory)

[**MpThreatEnumerate**](https://learn.microsoft.com/windows/win32/lwef/mpthreatenumerate)

[**MpThreatQuery**](https://learn.microsoft.com/windows/win32/lwef/mpthreatquery)

[**MPDETECTION\_ORIGIN**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-origin)

[**MPDETECTION\_STATE**](https://learn.microsoft.com/windows/win32/lwef/mpdetection-state)

[**MPEXECUTION\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpexecution-status)

[**MPRESOLVED\_REASON**](https://learn.microsoft.com/windows/win32/lwef/mpresolved-reason)

[**MPRESOURCE\_INFO**](https://learn.microsoft.com/windows/win32/lwef/mpresource-info)

[**MPSOURCE**](https://learn.microsoft.com/windows/win32/lwef/mpsource)

[**MPTHREAT\_ACTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-action)

[**MPTHREAT\_CATEGORY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-category)

[**MPTHREAT\_DETECTION**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-detection)

[**MPTHREAT\_INFOEX\_BEHAVIOR**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-behavior)

[**MPTHREAT\_INFOEX\_NIS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-nis)

[**MPTHREAT\_INFOEX\_UNUSED**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-infoex-unused)

[**MPTHREAT\_SEVERITY**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-severity)

[**MPTHREAT\_STATUS**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-status)

[**MPTHREAT\_TYPE**](https://learn.microsoft.com/windows/win32/lwef/mpthreat-type)

