# PUBAPPINFOFLAGS enumeration

## Description

Specifies which members in the [PUBAPPINFO](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) structure are valid. These flags are bitmasks set in the **dwMask** member and passed to [IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo).

## Constants

### `PAI_SOURCE:0x1`

The [pszSource](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) string is valid and contains the display name of the publishing source. If multiple sources publish an application of the same name, Add/Remove Programs identifies them by "\<application name> : \<publishing source>".

### `PAI_ASSIGNEDTIME:0x2`

The [stAssigned](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) member is valid and contains the time that the application should be installed as assigned by an application administrator.

### `PAI_PUBLISHEDTIME:0x4`

Not used.

### `PAI_SCHEDULEDTIME:0x8`

The [stScheduled](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) member is valid and contains the time that the application should be installed as assigned by the user.

### `PAI_EXPIRETIME:0x10`

The [stExpired](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-pubappinfo) member is valid and contains the time after which Add/Remove Programs should no longer install the program.

## See also

[IPublishedApp::GetPublishedAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-getpublishedappinfo)