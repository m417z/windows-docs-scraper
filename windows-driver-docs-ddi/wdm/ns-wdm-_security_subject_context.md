# SECURITY_SUBJECT_CONTEXT structure

## Description

The **SECURITY_SUBJECT_CONTEXT** structure is used to capture subject security context for access validation and auditing.

*Drivers must not modify or try to directly access any members of this structure to make security decisions. To create and manipulate this structure, use the support routines listed in the **See Also** section.*

## Members

### `ClientToken`

Reserved for system use.

### `ImpersonationLevel`

Reserved for system use.

### `PrimaryToken`

Reserved for system use.

### `ProcessAuditId`

Reserved for system use.

## Remarks

For more information about security and access control, see [Windows security model for driver developers](https://learn.microsoft.com/windows-hardware/drivers/driversecurity/windows-security-model) and the documentation on these topics in the Microsoft Windows SDK.

## See also

[**ACCESS_STATE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_access_state)

[**FsRtlNotifyFullChangeDirectory**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-_fsrtl_advanced_fcb_header-fsrtlnotifyfullchangedirectory)

[**SECURITY_IMPERSONATION_LEVEL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_security_impersonation_level)

[**SeAccessCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seaccesscheck)

[**SeAssignSecurity**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurity)

[**SeAssignSecurityEx**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-seassignsecurityex)

[**SeAuditingFileOrGlobalEvents**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seauditingfileorglobalevents)

[**SeCaptureSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secapturesubjectcontext)

[**SeCreateClientSecurityFromSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-secreateclientsecurityfromsubjectcontext)

[**SeFilterToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sefiltertoken)

[**SeLockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-selocksubjectcontext)

[**SePrivilegeCheck**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seprivilegecheck)

[**SeQuerySubjectContextToken**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sequerysubjectcontexttoken)

[**SeReleaseSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-sereleasesubjectcontext)

[**SeUnlockSubjectContext**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-seunlocksubjectcontext)