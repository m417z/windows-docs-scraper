# POLICYSETTINGSTATUSINFO structure

## Description

The
**POLICYSETTINGSTATUSINFO** structure provides information about a policy-setting event.

## Members

### `szKey`

This member is optional. If it is **NULL**, the system generates a value.

### `szEventSource`

Pointer to a string specifying the name of the source (application, service, driver, subsystem) that generated the log entry.

### `szEventLogName`

Pointer to a string specifying the name of the event log.

### `dwEventID`

Specifies the event log message ID.

### `dwErrorCode`

A
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes) that indicates an error that occurred during the application of the policy setting.

### `status`

Specifies the status of the policy setting. This member can be one of the following values.

#### RSOPUnspecified

The client-side extension does not define a status for this policy setting.

#### RSOPApplied

The policy setting was applied successfully.

#### RSOPIgnored

The policy setting was ignored; the system made no attempt to apply it.

#### RSOPFailed

Application of the policy setting failed. Details about the failure are indicated by the other members of the structure.

#### RSOPSubsettingFailed

The policy setting was applied successfully, but an error occurred while attempting to apply the child setting.

### `timeLogged`

Specifies a
[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that indicates the time at which the source generated the event.

## See also

[Group Policy Overview](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/about-group-policy)

[Group Policy Structures](https://learn.microsoft.com/previous-versions/windows/desktop/Policy/group-policy-structures)

[RSoPSetPolicySettingStatus](https://learn.microsoft.com/windows/desktop/api/userenv/nf-userenv-rsopsetpolicysettingstatus)