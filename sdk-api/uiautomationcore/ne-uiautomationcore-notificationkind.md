# NotificationKind enumeration

## Description

Defines values that indicate the type of a notification event, and a hint to the listener about the processing of the event. For example, if multiple notifications are received, they should all be read, or only the last one should be read, and so on.

## Constants

### `NotificationKind_ItemAdded:0`

The current element and/or the container has had something added to it that should be presented to the user.

### `NotificationKind_ItemRemoved:1`

The current element has had something removed from inside of it that should be presented to the user.

### `NotificationKind_ActionCompleted:2`

The current element has a notification that an action was completed.

### `NotificationKind_ActionAborted:3`

The current element has a notification that an action was aborted.

### `NotificationKind_Other:4`

The current element has a notification not an add, remove, completed, or aborted action.