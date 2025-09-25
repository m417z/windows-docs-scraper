# IsAppThemed function

## Description

Reports whether the current application's user interface displays using visual styles.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the following values.

| Return code | Description |
| --- | --- |
| **TRUE** | The application has a visual style applied. |
| **FALSE** | The application does not have a visual style applied. |

## Remarks

Prior to Windows 8, a visual style can be turned off in Control Panel, so that an application can support visual styles but not have a visual style applied at a given time.

 In Windows 8, it is not possible to turn off visual styles.

Do not call this function during [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) or global objects constructors. This may cause invalid return values.