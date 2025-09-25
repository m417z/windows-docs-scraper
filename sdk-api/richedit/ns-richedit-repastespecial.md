# REPASTESPECIAL structure

## Description

Contains information identifying whether the display aspect of a pasted object should be based on the content of the object or the icon that represent the object.

## Members

### `dwAspect`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Display aspect. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **DVASPECT_CONTENT** | Aspect is based on the content of the object. |
| **DVASPECT_ICON** | Aspect is based on the icon view of the object. |

### `dwParam`

Type: **[DWORD_PTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Aspect data. If **dwAspect** is DVASPECT_ICON, this member contains the handle to the metafile with the icon view of the object.

## See also

[EM_PASTESPECIAL](https://learn.microsoft.com/windows/win32/controls/em-pastespecial)