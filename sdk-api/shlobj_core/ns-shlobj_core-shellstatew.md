# SHELLSTATEW structure

## Description

Contains settings for the Shell's state. This structure is used with the [SHGetSetSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsetsettings) function.

## Members

### `fShowAllObjects`

Type: **BOOL**

**TRUE** to show all objects, including hidden files and folders. **FALSE** to hide hidden files and folders.

### `fShowExtensions`

Type: **BOOL**

**TRUE** to show file name extensions, **FALSE** to hide them.

### `fNoConfirmRecycle`

Type: **BOOL**

**TRUE** to show no confirmation dialog box when deleting items to the Recycle Bin, **FALSE** to display the confirmation dialog box.

### `fShowSysFiles`

Type: **BOOL**

**TRUE** to show system files, **FALSE** to hide them.

### `fShowCompColor`

Type: **BOOL**

**TRUE** to show encrypted or compressed NTFS files in color.

### `fDoubleClickInWebView`

Type: **BOOL**

**TRUE** to require a double-click to open an item when in web view.

### `fDesktopHTML`

Type: **BOOL**

**TRUE** to use Active Desktop, **FALSE** otherwise.

### `fWin95Classic`

Type: **BOOL**

**TRUE** to enforce Windows 95 Shell behavior and restrictions.

### `fDontPrettyPath`

Type: **BOOL**

**TRUE** to prevent the conversion of the path to all lowercase characters.

### `fShowAttribCol`

Type: **BOOL**

Not used.

### `fMapNetDrvBtn`

Type: **BOOL**

**TRUE** to display a **Map Network Drive** button.

### `fShowInfoTip`

Type: **BOOL**

**TRUE** to show a pop-up description for folders and files.

### `fHideIcons`

Type: **BOOL**

**TRUE** to hide desktop icons, **FALSE** to show them.

### `fWebView`

Type: **BOOL**

**TRUE** to display as a web view.

### `fFilter`

Type: **BOOL**

Not used.

### `fShowSuperHidden`

Type: **BOOL**

**TRUE** to show operating system files.

### `fNoNetCrawling`

Type: **BOOL**

**TRUE** to disable automatic searching for network folders and printers.

### `dwWin95Unused`

Type: **DWORD**

Not used.

### `uWin95Unused`

Type: **UINT**

Not used.

### `lParamSort`

Type: **LONG**

The column to sort by.

### `iSortDirection`

Type: **int**

Alphabetical sort direction for the column specified by **lParamSort**. Use 1 for an ascending sort, -1 for a descending sort.

### `version`

Type: **UINT**

Not used.

### `uNotUsed`

Type: **UINT**

Not used.

### `fSepProcess`

Type: **BOOL**

**TRUE** to launch folder windows in separate processes, **FALSE** to launch in the same process.

### `fStartPanelOn`

Type: **BOOL**

**Windows XP only**. **TRUE** to use the Windows XP-style Start menu, **FALSE** to use the classic Start menu.

### `fShowStartPage`

Type: **BOOL**

Not used.

### `fAutoCheckSelect`

Type: **BOOL**

**Introduced in Windows Vista**. **TRUE** to use the Windows Vista-style checkbox folder views, **FALSE** to use the classic views.

### `fIconsOnly`

Type: **BOOL**

**Introduced in Windows Vista**. **TRUE** to show generic icons only, **FALSE** to show thumbnail-style icons in folders.

### `fShowTypeOverlay`

Type: **BOOL**

**Introduced in Windows Vista**. **TRUE** indicates a thumbnail should show the application that would be invoked when opening the item, **FALSE** indicates that no application will be shown.

### `fShowStatusBar`

Type: **BOOL**

**Introduced in Windows 8**. **TRUE** to show the status bar; otherwise, **FALSE**.

### `fSpareFlags`

Type: **UINT**

Not used.

## Remarks

> [!NOTE]
> The shlobj_core.h header defines SHELLSTATE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).