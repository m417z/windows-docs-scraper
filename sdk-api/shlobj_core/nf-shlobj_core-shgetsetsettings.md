# SHGetSetSettings function

## Description

[**SHGetSetSettings** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Sets or retrieves Shell state settings.

## Parameters

### `lpss` [in, out]

Type: **LPSHELLSTATE**

A pointer to a [SHELLSTATE](https://learn.microsoft.com/windows/desktop/api/shlobj_core/ns-shlobj_core-shellstatea) structure that provides or receives the Shell state settings.

### `dwMask` [in]

Type: **DWORD**

One or more of the [SSF](https://learn.microsoft.com/windows/desktop/shell/ssf-constants) flags that indicate which settings should be set or retrieved.

### `bSet` [in]

Type: **BOOL**

**TRUE** to indicate that the contents of *lpss* should be used to set the Shell settings, **FALSE** to indicate that the Shell settings should be retrieved to *lpss*.

## See also

[SHGetSettings](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shgetsettings)