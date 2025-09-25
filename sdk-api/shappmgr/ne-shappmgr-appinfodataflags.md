# APPINFODATAFLAGS enumeration

## Description

Specifies application information to return from [IShellApp::GetAppInfo](https://learn.microsoft.com/windows/desktop/api/shappmgr/nf-shappmgr-ishellapp-getappinfo). These flags are bitmasks used in the [dwMask](https://learn.microsoft.com/windows/desktop/api/shappmgr/ns-shappmgr-appinfodata) member of the **APPINFODATA** structure.

## Constants

### `AIM_DISPLAYNAME:0x1`

Returns the display name.

### `AIM_VERSION:0x2`

Returns the version.

### `AIM_PUBLISHER:0x4`

Returns the application publisher.

### `AIM_PRODUCTID:0x8`

Returns the application's product ID.

### `AIM_REGISTEREDOWNER:0x10`

Returns the application's registered owner.

### `AIM_REGISTEREDCOMPANY:0x20`

Returns the application's registered company.

### `AIM_LANGUAGE:0x40`

Returns the language.

### `AIM_SUPPORTURL:0x80`

Returns the support URL.

### `AIM_SUPPORTTELEPHONE:0x100`

Returns the support telephone number.

### `AIM_HELPLINK:0x200`

Returns the Help link.

### `AIM_INSTALLLOCATION:0x400`

Returns the application's install location.

### `AIM_INSTALLSOURCE:0x800`

Returns the install source.

### `AIM_INSTALLDATE:0x1000`

Returns the application's install date.

### `AIM_CONTACT:0x4000`

Returns the application's contact information.

### `AIM_COMMENTS:0x8000`

Returns application comments.

### `AIM_IMAGE:0x20000`

Returns the application image.

### `AIM_READMEURL:0x40000`

Returns the URL of the application's ReadMe file.

### `AIM_UPDATEINFOURL:0x80000`

Returns the URL of the application's update information.

#### - AIM_REQUIREDBYPOLICY

Obsolete.

## Remarks

Add/Remove Programs in Control Panel uses only **AIM_DISPLAYNAME** and **AIM_SUPPORTURL.**