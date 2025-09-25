# NotificationProcessing enumeration

## Description

Defines values that indicate how a notification should be processed.

## Constants

### `NotificationProcessing_ImportantAll:0`

These notifications should be presented to the user as soon as possible and
all of the notifications from this source should be delivered to the user.

**Warning** Use this in a limited capacity as this style of message could cause a flooding of information to the user due to the nature of the request to deliver all notifications.

### `NotificationProcessing_ImportantMostRecent:1`

These notifications
should be presented to the user as soon as possible. The most recent notification from this source should be delivered to the user because it supersedes all of the other notifications.

### `NotificationProcessing_All:2`

These notifications
should be presented to the user when possible.
All of the notifications from this source should be delivered to the user.

### `NotificationProcessing_MostRecent:3`

These notifications
should be presented to the user when possible. The most recent notification from this source should be delivered to the user because it supersedes all of the other notifications.

### `NotificationProcessing_CurrentThenMostRecent:4`

These notifications should be presented to the user when possible. Don’t interrupt the current notification for this one.
If new notifications come in from the same source while the current notification is being presented, keep the most recent and ignore the rest until the current processing is completed. Then, use the most recent message as the current message.

### `NotificationProcessing_ImportantCurrentThenMostRecent:5`

Introduced in Windows, build 26100. These notifications should be presented to the user as soon as possible.
Don’t interrupt the current notification, as it is considered important and must be allowed to finish.
If new notifications arrive from the same source during this time, retain only the most recent one and discard the others.
Once the current notification has been processed, immediately present the most recent pending notification.