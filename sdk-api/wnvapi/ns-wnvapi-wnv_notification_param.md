# WNV_NOTIFICATION_PARAM structure

## Description

Specifies the version, notification type, and the buffer location in a [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function call. The buffer specified in this structure is filled by the Windows Network Virtualization (WNV) driver when the notifications of the specific type are available.

## Members

### `Header`

Type: **[WNV_OBJECT_HEADER](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_header)**

The version and buffer size for this structure.

### `NotificationType`

Type: **[WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type)**

A value of the [WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type) enumeration that specifies the type of notifications requested, such as policy mismatches, Internet Control Message Protocol
(ICMP) redirect message arrivals, and object changes.

### `PendingNotifications`

Type: **ULONG**

An output value that provides the caller information about the number of pending events of the specified notification type. The pending events are queued within the WNV driver along with the events that have already been added to the **Buffer** field when the current [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function call is completed. This field allows the WNV driver to indicate the number of remaining events to the caller of **WnvRequestNotification**, so the caller can estimate the size of the buffer required. The caller should post another call with enough buffer size to **WnvRequestNotification** to consume these remaining events.

### `Buffer`

Type: **PUCHAR**

A pointer to a buffer that is filled by the WNV driver with notification structures of the specified notification type when completing the call to [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification). The eventual content in this field is explained by the following table.

| Value of the **NotificationType** field | Content of the **Buffer** field |
| --- | --- |
| **WnvPolicyMismatchType** | One or more [WNV_POLICY_MISMATCH_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_policy_mismatch_param) structures |
| **WnvRedirectType** | One or more [WNV_REDIRECT_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_redirect_param) structures |
| **WnvObjectChangeType** | One or more [WNV_OBJECT_CHANGE_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_object_change_param) structures |