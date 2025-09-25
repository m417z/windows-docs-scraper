# PUBAPPINFO structure

## Description

Provides information about a published application from an application publisher to **Add/Remove Programs** in Control Panel.

## Members

### `cbSize`

Type: **DWORD**

A value of type **DWORD** that specifies the size of the structure. This member is set by the **Add/Remove Programs** utility.

### `dwMask`

Type: **DWORD**

A bitmask that indicates which items in the structure are valid. This member can contain one or more [PUBAPPINFOFLAGS](https://learn.microsoft.com/windows/win32/api/shappmgr/ne-shappmgr-pubappinfoflags).

### `pszSource`

Type: **LPWSTR**

A pointer to a string containing the display name of the publisher. This name appears in **Add/Remove Programs** if duplicate application names are encountered. The string buffer must be allocated using the Shell task allocator.

### `stAssigned`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

The time when an application manager schedules the application installation. **Add/Remove Programs** does not allow the user to schedule an installation time later than the value in this member. This member is ignored if it describes a time prior to the current time.

### `stPublished`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

### `stScheduled`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

The installation time that the user sets by clicking **Add Later**. **Add/Remove Programs** calls the [IPublishedApp::Install](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-install) method with the *pInstallTime* parameter pointing to a [SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime) structure that contains the time the user entered. The application publisher maintains this value for installation scheduling. [IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo) returns the scheduled installation time in this member if the scheduled time has not been canceled using [IPublishedApp::Unschedule](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-unschedule).

### `stExpire`

Type: **[SYSTEMTIME](https://learn.microsoft.com/windows/desktop/api/minwinbase/ns-minwinbase-systemtime)**

The time after which you cannot install the published application using **Add/Remove Programs**.

## See also

[IAppPublisher](https://learn.microsoft.com/windows/desktop/api/shappmgr/nn-shappmgr-iapppublisher)