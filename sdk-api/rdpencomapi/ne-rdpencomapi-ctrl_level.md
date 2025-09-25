# CTRL_LEVEL enumeration

## Description

Defines the level of control that an attendee has on a session.

## Constants

### `CTRL_LEVEL_MIN:0`

Minimum enumeration value.

### `CTRL_LEVEL_INVALID:0`

The control level is not valid.

### `CTRL_LEVEL_NONE:1`

The attendee cannot view or interact with the session. This is the default.

### `CTRL_LEVEL_VIEW:2`

The attendee can view the session.

### `CTRL_LEVEL_INTERACTIVE:3`

The attendee can view and interact with the session. The local keyboard and mouse input is redirected to
the session.

### `CTRL_LEVEL_REQCTRL_VIEW:4`

The attendee can view the session.

**Windows Server 2012, Windows 8, Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This enumeration value is not supported.

### `CTRL_LEVEL_REQCTRL_INTERACTIVE:5`

The attendee can view and interact with the session. The local keyboard and mouse input is redirected to the
session. Hosting applications that want to allow users to control the shared session must either define
**uiAccess** as "true" in their application manifest OR run at High Integrity
Level (elevated). For more information see
[Setting UIAccess in the Application Manifest File](https://learn.microsoft.com/windows/desktop/WinAuto/uiauto-securityoverview).

**Windows Server 2012, Windows 8, Windows Server 2008 R2, Windows 7, Windows Server 2008 and Windows Vista:** This enumeration value is not supported.

### `CTRL_LEVEL_MAX:5`

Maximum enumeration value.

## See also

[ControlLevel Property of IRDPSRAPIAttendee](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiattendee-get_controllevel)

[IRDPSRAPIViewer::RequestControl](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiviewer-requestcontrol)

[OnControlLevelChangeRequest](https://learn.microsoft.com/previous-versions/windows/desktop/rdp/oncontrollevelchangerequest)