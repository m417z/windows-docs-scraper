# IE4COMPONENT structure

## Description

Used by Microsoft Internet Explorer 4.0 and Microsoft Internet Explorer 4.01 to hold information about a component. With Windows 2000, it is replaced by the [COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-component) structure.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure.

### `dwID`

Type: **DWORD**

Reserved. Set to zero.

### `iComponentType`

Type: **int**

The component type. It can be set to one of these values:

#### COMP_TYPE_HTMLDOC

#### COMP_TYPE_PICTURE

#### COMP_TYPE_WEBSITE

#### COMP_TYPE_CONTROL

### `fChecked`

Type: **BOOL**

A value that is set to **TRUE** if the component is enabled, or **FALSE** if not.

### `fDirty`

Type: **BOOL**

A value that is set to **TRUE** if the component has been modified and not yet saved to disk. It will be set to **FALSE** if the component has not been modified, or if it has been modified and saved to disk.

### `fNoScroll`

Type: **BOOL**

A value that is set to **TRUE** if the component is scrollable, or **FALSE** if it's not.

### `cpPos`

Type: **[COMPPOS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-comppos)**

A [COMPPOS](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-comppos) structure containing position and size information.

### `wszFriendlyName`

Type: **WCHAR[MAX_PATH]**

The component's friendly name.

### `wszSource`

Type: **WCHAR[INTERNET_MAX_URL_LENGTH]**

The component's URL.

### `wszSubscribedURL`

Type: **WCHAR[INTERNET_MAX_URL_LENGTH]**

The URL that a user has been subscribed to.