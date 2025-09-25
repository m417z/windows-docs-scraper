# QOS_NOTIFY_FLOW enumeration

## Description

The **QOS_NOTIFY_FLOW** enumeration specifies the circumstances that must be present for the [QOSNotifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosnotifyflow) function to send a notification.

## Constants

### `QOSNotifyCongested:0`

Notifications will be sent when congestion is detected. If the flow is currently congested, a notification may be sent immediately.

### `QOSNotifyUncongested:1`

Notifications will be sent when the flow is not congested. If the flow is currently uncongested, a notification may be sent immediately.

### `QOSNotifyAvailable:2`

Notifications will be sent when the flow's available capacity is sufficient to allow upgrading its bandwidth to a specified capacity.

## See also

[QOSNotifyFlow](https://learn.microsoft.com/previous-versions/windows/desktop/api/qos2/nf-qos2-qosnotifyflow)

[Quality Windows Audio/Video Experience (qWAVE)](https://learn.microsoft.com/previous-versions/windows/desktop/qos/quality-windows-audio-video-experience--qwave-)