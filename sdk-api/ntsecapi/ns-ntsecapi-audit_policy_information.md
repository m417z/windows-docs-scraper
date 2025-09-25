# AUDIT_POLICY_INFORMATION structure

## Description

The **AUDIT_POLICY_INFORMATION** structure specifies a security event type and when to audit that type.

## Members

### `AuditSubCategoryGuid`

A **GUID** structure that specifies an audit subcategory.

### `AuditingInformation`

A set of bit flags that specify the conditions under which the security event type specified by the **AuditSubCategoryGuid** and **AuditCategoryGuid** members are audited. The following values are defined.

**Important** Note that the meaning of these values differs depending on which function is using this structure.

| Value | Meaning |
| --- | --- |
| **POLICY_AUDIT_EVENT_UNCHANGED**<br><br>0x00000000 | Do not change auditing options for the specified event type.<br><br>This value is valid for the [AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy) and [AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy) functions. |
| **POLICY_AUDIT_EVENT_SUCCESS**<br><br>0x00000001 | Audit successful occurrences of the specified event type.<br><br>This value is valid for the [AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy) and [AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy) functions. |
| **POLICY_AUDIT_EVENT_FAILURE**<br><br>0x00000002 | Audit failed attempts to cause the specified event type.<br><br>This value is valid for the [AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy) and [AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy) functions. |
| **POLICY_AUDIT_EVENT_NONE**<br><br>0x00000004 | Do not audit the specified event type.<br><br>This value is valid for the [AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy) and [AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy) functions. |
| **PER_USER_POLICY_UNCHANGED**<br><br>0x00 | Do not change auditing options for the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |
| **PER_USER_AUDIT_SUCCESS_INCLUDE**<br><br>0x01 | Audit successful occurrences of the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |
| **PER_USER_AUDIT_SUCCESS_EXCLUDE**<br><br>0x02 | Do not audit successful occurrences of the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |
| **PER_USER_AUDIT_FAILURE_INCLUDE**<br><br>0x04 | Audit failed attempts to cause the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |
| **PER_USER_AUDIT_FAILURE_EXCLUDE**<br><br>0x08 | Do not audit failed attempts to cause the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |
| **PER_USER_AUDIT_NONE**<br><br>0x10 | Do not audit the specified event type.<br><br>This value is valid for the [AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy) and [AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy) functions. |

### `AuditCategoryGuid`

A **GUID** structure that specifies an audit-policy category.

## See also

[AuditComputeEffectivePolicyBySid](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditcomputeeffectivepolicybysid)

[AuditComputeEffectivePolicyByToken](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditcomputeeffectivepolicybytoken)

[AuditQueryPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditqueryperuserpolicy)

[AuditQuerySystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditquerysystempolicy)

[AuditSetPerUserPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetperuserpolicy)

[AuditSetSystemPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-auditsetsystempolicy)