# IRDPSRAPIInvitation::get_Revoked

## Description

The revoked state of the invitation.

This property is read/write.

## Parameters

## Remarks

There is no way to delete an invitation, only to revoke it. This enables the application to check whether a ticket was issued before to ensure that each invitation has a unique ticket. If an invitation state is revoked, no new attendees can connect by using that invitation.

## See also

[IRDPSRAPIInvitation](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiinvitation)