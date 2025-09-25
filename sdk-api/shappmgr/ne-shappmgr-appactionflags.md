# APPACTIONFLAGS enumeration

## Description

Specifies application management actions supported by an application publisher. These flags are bitmasks passed to [IShellApp::GetPossibleActions](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getpossibleactions).

## Constants

### `APPACTION_INSTALL:0x1`

Indicates that the application can be installed. Published applications always set this bit.

### `APPACTION_UNINSTALL:0x2`

Not applicable to published applications.

### `APPACTION_MODIFY:0x4`

Not applicable to published applications.

### `APPACTION_REPAIR:0x8`

Not applicable to published applications.

### `APPACTION_UPGRADE:0x10`

Not applicable to published applications.

### `APPACTION_CANGETSIZE:0x20`

Not applicable to published applications.

### `APPACTION_MODIFYREMOVE:0x80`

Not applicable to published applications.

### `APPACTION_ADDLATER:0x100`

Indicates that the application supports scheduled installation. If this bit is set, then the Control Panel's Add or Remove Programs application presents the user an **Add Later** button. If you select **Add Later**, you are prompted to select the desired time of installation. The [IPublishedApp::Install](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ipublishedapp-install) method is then called with the installation time.

### `APPACTION_UNSCHEDULE:0x200`

Obsolete.

## Remarks

The Add or Remove Programs application in Control Panel uses only ****APPACTION_INSTALL**** and ****APPACTION_ADDLATER**** for published applications.