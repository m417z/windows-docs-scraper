# SECPKG_EVENT_NOTIFY structure

## Description

The **SECPKG_EVENT_NOTIFY** structure contains information about security events. This structure is passed to a function registered to receive event notifications. Event notification functions are registered by calling the
[RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification) function.

## Members

### `EventClass`

The event class.

### `Reserved`

Reserved.

### `EventDataSize`

The size of the **EventData** member.

### `EventData`

The event details.

### `PackageParameter`

Information specified as the *Parameter* value when [RegisterNotification](https://learn.microsoft.com/windows/desktop/api/ntsecpkg/nc-ntsecpkg-lsa_register_notification) is called to register for notification.