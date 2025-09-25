# POLICY_AUDIT_EVENTS_INFO structure

## Description

The **POLICY_AUDIT_EVENTS_INFO** structure is used to set and query the system's auditing rules. The
[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy) and
[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) functions use this structure when their *InformationClass* parameters are set to **PolicyAuditEventsInformation**.

## Members

### `AuditingMode`

Indicates whether auditing is enabled.

If this flag is **TRUE**, the system generates audit records according to the event auditing options specified in the **EventAuditingOptions** member.

If this flag is **FALSE**, the system does not generate audit records. However, note that set operations update the event auditing options as specified in the **EventAuditingOptions** member even when **AuditingMode** is **FALSE**.

### `EventAuditingOptions`

Pointer to an array of POLICY_AUDIT_EVENT_OPTIONS variables. Each element in this array specifies the auditing options for an audit event type. The index of each array element corresponds to an audit event type value in the
[POLICY_AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_audit_event_type) enumeration type.

Each POLICY_AUDIT_EVENT_OPTIONS variable in the array can specify the following auditing options. You can also combine the success and failure options, POLICY_AUDIT_EVENT_SUCCESS and POLICY_AUDIT_EVENT_FAILURE.

When [LSASetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy) is called to change the audit policy, any new POLICY_AUDIT_EVENT_OPTIONS array elements are added to any existing audit options. Adding a new POLICY_AUDIT_EVENT_OPTIONS element combined with the POLICY_AUDIT_EVENT_NONE audit option cancels all previous audit options and begins a new set of options.

| Value | Meaning |
| --- | --- |
| **POLICY_AUDIT_EVENT_UNCHANGED** | For set operations, specify this value to leave the current options unchanged. For read operations, this value means that no audit records for this type are generated. This is the default. |
| **POLICY_AUDIT_EVENT_SUCCESS** | Generate audit records for successful events of this type. |
| **POLICY_AUDIT_EVENT_FAILURE** | Generate audit records for failed attempts to cause an event of this type to occur. |
| **POLICY_AUDIT_EVENT_NONE** | Do not generate audit records for events of this type. |

### `MaximumAuditEventCount`

Specifies the number of elements in the **EventAuditingOptions** array. For set operations, if this value is less than the number of audit event types supported by the system, the system does not change the auditing options for event types with indexes equal to or higher than the value specified in **MaximumAuditEventCount**.

## Remarks

LSA Policy defines a mask for the valid event auditing options. The POLICY_AUDIT_EVENT_MASK mask evaluates to **TRUE** if it is set equal to any of the preceding event auditing options.

## See also

[LsaQueryInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsaqueryinformationpolicy)

[LsaSetInformationPolicy](https://learn.microsoft.com/windows/desktop/api/ntsecapi/nf-ntsecapi-lsasetinformationpolicy)

[POLICY_AUDIT_EVENT_TYPE](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_audit_event_type)

[POLICY_INFORMATION_CLASS](https://learn.microsoft.com/windows/desktop/api/ntsecapi/ne-ntsecapi-policy_information_class)