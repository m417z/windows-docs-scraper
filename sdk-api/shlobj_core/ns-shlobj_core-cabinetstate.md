# CABINETSTATE structure

## Description

[**CABINETSTATE** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Holds the global configuration for Windows Explorer and Windows Internet Explorer. This structure is used in the [ReadCabinetState](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-readcabinetstate) and [WriteCabinetState](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-writecabinetstate) functions.

## Members

### `cLength`

Type: **WORD**

The size of the structure, in bytes.

### `nVersion`

Type: **WORD**

### `fFullPathTitle`

Type: **BOOL**

#### TRUE

Display the full path in the title bar.

#### FALSE

Display only the file name in the title bar.

### `fSaveLocalView`

Type: **BOOL**

#### TRUE

Remember each folder's view settings.

#### FALSE

Use global settings for all folders.

### `fNotShell`

Type: **BOOL**

Not used.

### `fSimpleDefault`

Type: **BOOL**

Not used.

### `fDontShowDescBar`

Type: **BOOL**

Not used.

### `fNewWindowMode`

Type: **BOOL**

#### TRUE

Display in a new window.

#### FALSE

Display in the current window.

### `fShowCompColor`

Type: **BOOL**

#### TRUE

Show encrypted or compressed NTFS files in color.

#### FALSE

Do not show encrypted or compressed NTFS files in color.

### `fDontPrettyNames`

Type: **BOOL**

Not used.

### `fAdminsCreateCommonGroups`

Type: **BOOL**

Used when an administrator installs an application that places an icon in the **Start** menu.

#### TRUE

Add the icon to the **Start** menu for all users (CSIDL_COMMON_STARTMENU). This is the default value.

#### FALSE

Add the icon to only the current user (CSIDL_STARTMENU).

### `fUnusedFlags`

Type: **UINT**

Not used.

### `fMenuEnumFilter`

Type: **UINT**

One or both of the following flags.

#### SHCONTF_FOLDERS

Display folders.

#### SHCONTF_NONFOLDERS

Display non-folder items.