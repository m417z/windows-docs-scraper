# SetThemeAppProperties function

## Description

Sets the flags that determine how visual styles are implemented in the calling application.

## Parameters

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that specifies one or more of the following bit flags, which can be combined with a logical OR.

| Value | Meaning |
| --- | --- |
| STAP_ALLOW_NONCLIENT | Specifies that the nonclient areas of application windows will have visual styles applied. |
| STAP_ALLOW_CONTROLS | Specifies that the common controls used in an application will have visual styles applied. |
| STAP_ALLOW_WEBCONTENT | Specifies that web content displayed in an application will have visual styles applied. |

## Remarks

After you set the flags, send a [WM_THEMECHANGED](https://learn.microsoft.com/windows/desktop/winmsg/wm-themechanged) message to your application's main window for the changes to take effect.

#### Examples

This example combines flags and calls this function as shown.

```cpp
DWORD dwFlags = (STAP_ALLOW_NONCLIENT |
        STAP_ALLOW_CONTROLS | STAP_ALLOW_WEBCONTENT);
SetThemeAppProperties(dwFlags);

```

## See also

[GetThemeAppProperties](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemeappproperties)