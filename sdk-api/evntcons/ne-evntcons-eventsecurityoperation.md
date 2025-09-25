# EVENTSECURITYOPERATION enumeration (evntcons.h)

## Description

Defines what component of the security descriptor that the [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol) function modifies.

## Constants

### `EventSecuritySetDACL`

Clears the current discretionary access control list (DACL) and adds an ACE to the DACL. The *Sid*, *Rights*, and *AllowOrDeny* parameters of the [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol) function determine the contents of the ACE (who has access to the provider or session and the type of access). To add a new ACE to the DACL without clearing the existing DACL, specify EventSecurityAddDACL.

### `EventSecuritySetSACL`

Clears the current system access control list (SACL) and adds an audit ACE to the SACL. The *Sid* and *Rights* parameters of the [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol) function determine the contents of the ACE (who generates an audit record when attempting the specified access). To add a new ACE to the SACL without clearing the existing SACL, specify EventSecurityAddSACL.

### `EventSecurityAddDACL`

Adds an ACE to the current DACL. The *Sid*, *Rights*, and *AllowOrDeny* parameters of the [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol) function determine the contents of the ACE (who has access to the provider or session and the type of access).

### `EventSecurityAddSACL`

Adds an ACE to the current SACL. The *Sid* and *Rights* parameters of the [EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol) function determine the contents of the ACE (who generates an audit record when attempting the specified access).

### `EventSecurityMax`

Reserved.

## Remarks

For information on DACLs and SACLs, see [Access Control Lists](https://learn.microsoft.com/windows/desktop/SecAuthZ/access-control-lists).

## See also

[EventAccessControl](https://learn.microsoft.com/windows/desktop/api/evntcons/nf-evntcons-eventaccesscontrol)