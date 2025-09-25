# _DXGKARG_CREATEPERIODICFRAMENOTIFICATION structure

## Description

The arguments needed to create a periodic frame notification.

## Members

### `hAdapter`

A handle to the adapter associated with VidPnSourceID.

### `VidPnTargetId`

The output that the compositor wishes to receive notifications for.

### `Time`

Represents an offset before the VSync. The Time value may not be longer than a VSync interval while in VSync mode. In units of 100ns.

### `NotificationID`

Represents an ID for the notification that will be used to track which interrupt has fired from the GPU.

### `hNotification`

A Handle to the notification object, later used to destroy the object.