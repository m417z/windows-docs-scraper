# COMPONENT structure

## Description

Used by Windows 2000 to hold information about a component. This structure replaces the [IE4COMPONENT](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-ie4component) structure.

## Members

### `dwSize`

Type: **DWORD**

The size of the structure.

### `dwID`

Type: **DWORD**

Reserved. Set to zero.

### `iComponentType`

Type: **int**

The component type. It can take one of the following values.

#### COMP_TYPE_HTMLDOC

HTML document

#### COMP_TYPE_PICTURE

Picture

#### COMP_TYPE_WEBSITE

Website

#### COMP_TYPE_CONTROL

ActiveX control. This value is valid only for [IActiveDesktop::AddDesktopItem](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iactivedesktop-adddesktopitem).

### `fChecked`

Type: **BOOL**

A value that is set to **TRUE** if the component is enabled, or **FALSE** if it's not.

### `fDirty`

Type: **BOOL**

A value that is set to **TRUE** if the component has been modified and not yet saved to disk. It will be set to **FALSE** if the component has not been modified, or if it has been modified and saved to disk.

### `fNoScroll`

Type: **BOOL**

A value that is set to **TRUE** if the component is scrollable, or **FALSE** if not.

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

The subscribed URL.

### `dwCurItemState`

Type: **DWORD**

The current state of the component. It can take one of the following values.

#### IS_NORMAL

Normal screen

#### IS_FULLSCREEN

Full screen

#### IS_SPLIT

Split screen

### `csiOriginal`

Type: **[COMPSTATEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-compstateinfo)**

A [COMPSTATEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-compstateinfo) structure with the state of the component when it was first added.

### `csiRestored`

Type: **[COMPSTATEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-compstateinfo)**

A [COMPSTATEINFO](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-compstateinfo) structure with the restored state of the component.