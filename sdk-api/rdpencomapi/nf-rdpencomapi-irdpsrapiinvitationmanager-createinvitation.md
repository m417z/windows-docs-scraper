# IRDPSRAPIInvitationManager::CreateInvitation

## Description

Creates an invitation.

## Parameters

### `bstrAuthString` [in]

Type: **BSTR**

String to use for the authorization. The string is limited to 255 characters and must be unique for the session. If **NULL**, the method generates the string for you.

### `bstrGroupName` [in]

Type: **BSTR**

The name of the group. The string must be unique for the session. Applications typically use the group name to separate attendees into groups that can be granted different authorization levels.

### `bstrPassword` [in]

Type: **BSTR**

Password to use for authentication. The password is limited to 255 characters. You must provide the password to the viewer out-of-band from the ticket.

### `AttendeeLimit` [in]

Type: **long**

The maximum number of attendees.

### `ppInvitation` [out]

Type: **IRDPSRAPIInvitation****

An [IRDPSRAPIInvitation](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiinvitation) interface pointer.

## Return value

Type: **HRESULT**

If the method succeeds, the return value is **S_OK**. Otherwise, the return value is an error code.

## See also

[IRDPSRAPIInvitationManager](https://learn.microsoft.com/windows/desktop/api/rdpencomapi/nn-rdpencomapi-irdpsrapiinvitationmanager)