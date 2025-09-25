# WLX_NOTIFICATION_INFO structure

## Description

[The WLX_NOTIFICATION_INFO structure is no longer available for use as of Windows Server 2008 and Windows Vista.]

This structure stores information about a [Winlogon](https://learn.microsoft.com/windows/desktop/SecGloss/w-gly) event.

## Members

### `Size`

Indicates the size of the structure, in bytes. Your application can check this value against the structure size to validate the structure.

### `Flags`

Reserved for internal use.

### `UserName`

String that specifies the name of the user currently logged on to the system. If the event occurs before a user logs on, this value is **NULL**.

### `Domain`

String that specifies the name of the domain the user is currently logged on to. If the event occurs before a user logs on, this value is **NULL**.

### `WindowStation`

Specifies the name of the window station the user is currently logged on to. If the event occurs before a user logs on, this value is **NULL**. Note that most configurations use a single, default window station. Some applications, such as
[About Terminal Services](https://learn.microsoft.com/windows/desktop/TermServ/about-terminal-services), use multiple window stations.

### `hToken`

A handle to the user's token. This value is **NULL** if the event occurs before a user logs on.

### `hDesktop`

A handle to the desktop that is currently active.

### `pStatusCallback`

Reserved for internal use.