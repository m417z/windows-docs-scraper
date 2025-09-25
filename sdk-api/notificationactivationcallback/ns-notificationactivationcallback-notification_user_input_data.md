# NOTIFICATION_USER_INPUT_DATA structure

## Description

Contains information about how a user interacted with a notification toast in the action center. This structure is used by [Activate](https://learn.microsoft.com/previous-versions/windows/desktop/api/notificationactivationcallback/nf-notificationactivationcallback-inotificationactivationcallback-activate).

## Members

### `Key`

The ID of the user input field in the XML payload.

### `Value`

The input value selected by the user for a given input field.

## Remarks

Each key-value pair contains a piece of information based on an item in the notification toast when the [Activate](https://learn.microsoft.com/previous-versions/windows/desktop/api/notificationactivationcallback/nf-notificationactivationcallback-inotificationactivationcallback-activate) callback is triggered.

## See also

[Respond to toast activations](https://learn.microsoft.com/previous-versions/windows/desktop/win32_tile_badge_notif/respond-to-toast-activations)