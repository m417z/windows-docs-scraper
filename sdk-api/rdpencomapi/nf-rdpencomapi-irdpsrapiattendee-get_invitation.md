# IRDPSRAPIAttendee::get_Invitation

## Description

The invitation used to grant the attendee access to the conference.

This property is read-only.

## Parameters

## Remarks

An application can have multiple groups of attendees. For example, an application can define a "Moderators" group and a "Spectators" group. Attendees that belong to the "Moderators" group are granted interactive control, while attendees in the "Spectators" group are only granted access to view the session. The application achieves this implementation by creating two invitation objects, one for each group. When an attendee connects, the application can verify which group the attendee belongs to by checking the [GroupName](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiinvitation-get_groupname) property of the invitation object used for authentication. If the group name is "Spectators," the application sets the [ControlLevel](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nf-rdpencomapi-irdpsrapiattendee-get_controllevel) property for the attendee to CTRL_LEVEL_VIEW. If the group name is "Moderators," it sets the **ControlLevel** property to CTRL_LEVEL_INTERACTIVE.

If this property is accessed on the viewer side, it returns a dummy invitation.

## See also

[IRDPSRAPIAttendee](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiattendee)