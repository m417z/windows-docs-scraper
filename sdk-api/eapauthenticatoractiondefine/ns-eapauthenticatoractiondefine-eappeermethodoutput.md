# EapPeerMethodOutput structure

## Description

Contains the action information returned by an EAP peer method.

## Members

### `action`

[EapPeerMethodResponseAction](https://learn.microsoft.com/windows/win32/api/eapauthenticatoractiondefine/ne-eapauthenticatoractiondefine-eappeermethodresponseaction) enumeration value that indicates the response EAPHost should take as a result of the EAP peer method operation.

### `fAllowNotifications`

If **TRUE**, allows EAPHost to raise a notification to the user; otherwise, do not allow notifications.

## See also

[EAPHost Peer Method Structures](https://learn.microsoft.com/windows/win32/eaphost/eap-host-peer-method-structures)