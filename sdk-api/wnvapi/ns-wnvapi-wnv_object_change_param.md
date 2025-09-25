# WNV_OBJECT_CHANGE_PARAM structure

## Description

Specifies the parameters of an event that causes the Windows Network Virtualization (WNV) driver to generate a **WnvObjectChangeType** type of notification. If there is a pending call to the [WnvRequestNotification](https://learn.microsoft.com/previous-versions/windows/desktop/api/wnvapi/nf-wnvapi-wnvrequestnotification) function of this type, the WNV driver fills the buffer that is passed in the *NotificationParam* argument's [WNV_NOTIFICATION_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_notification_param) structure with one or more instances of this structure and completes the **WnvRequestNotification** function call.

## Members

### `ObjectType`

Type: **[WNV_OBJECT_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_object_type)**

The object type that causes the change notification.

### `ObjectParam`

The parameters for the corresponding object type. If the object type is **WnvProviderAddressType**, this field points to the [WNV_PROVIDER_ADDRESS_CHANGE_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_provider_address_change_param) structure that describes the provider address object that generated an object change event.

### `ObjectParam.ProviderAddressChange`

**Type: **[WNV_PROVIDER_ADDRESS_CHANGE_PARAM](https://learn.microsoft.com/windows/desktop/api/wnvapi/ns-wnvapi-wnv_provider_address_change_param)****
The provider address change parameters for this object change event.

### `ObjectParam.CustomerAddressChange`

## Remarks

There is currently only one type of object defined and tracked in this structure: **WnvProviderAddressType**.

## See also

[WNV_NOTIFICATION_TYPE](https://learn.microsoft.com/windows/desktop/api/wnvapi/ne-wnvapi-wnv_notification_type)