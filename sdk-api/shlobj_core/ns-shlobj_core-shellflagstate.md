# SHELLFLAGSTATE structure

## Description

Contains a set of flags that indicate the current Shell settings. This structure is used with the [SHGetSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsettings) function.

## Members

### `fShowAllObjects`

Type: **BOOL**

Nonzero if the **Show All Files** option is enabled, or zero otherwise.

### `fShowExtensions`

Type: **BOOL**

Nonzero if the **Hide extensions for known file types** option is disabled, or zero otherwise.

### `fNoConfirmRecycle`

Type: **BOOL**

Nonzero if the **Display Delete Confirmation Dialog** box in the Recycle Bin is enabled, or zero otherwise.

### `fShowSysFiles`

Type: **BOOL**

Nonzero if the **Don't show hidden files, folders, or drives** option is selected, or zero otherwise.

### `fShowCompColor`

Type: **BOOL**

Nonzero if the **Display encrypted or compressed NTFS files in color** option is enabled, or zero otherwise.

### `fDoubleClickInWebView`

Type: **BOOL**

Nonzero if the **Double-Click to Open an Item** option is enabled, or zero otherwise.

### `fDesktopHTML`

Type: **BOOL**

Nonzero if the **Active Desktop – View as Web Page** option is enabled, or zero otherwise.

### `fWin95Classic`

Type: **BOOL**

Nonzero if the **Classic Style** option is enabled, or zero otherwise.

### `fDontPrettyPath`

Type: **BOOL**

Nonzero if the **Allow All Uppercase Names** option is enabled, or zero otherwise.

### `fShowAttribCol`

Type: **BOOL**

Nonzero if the **Show File Attributes in Detail View** option is enabled, or zero otherwise.

**Windows Vista and later**. Not used.

### `fMapNetDrvBtn`

Type: **BOOL**

Nonzero if the **Show Map Network Drive Button in Toolbar** option is enabled, or zero otherwise.

### `fShowInfoTip`

Type: **BOOL**

Nonzero if the **Show Info Tips for Items in Folders & Desktop** option is enabled, or zero otherwise.

### `fHideIcons`

Type: **BOOL**

Nonzero if the **Show Desktop Icons** option is enabled, or zero otherwise.

### `fAutoCheckSelect`

Type: **BOOL**

**Windows Vista and later**: Nonzero if the **Use checkboxes to select items** option is enabled, or zero otherwise.

### `fIconsOnly`

Type: **BOOL**

**Windows Vista and later**: Nonzero if the **Always show icons, never thumbnails** option is enabled, or zero otherwise.

### `fRestFlags`

Type: **UINT**

For Windows Vista this bitfield is 1, otherwise member this is not used.