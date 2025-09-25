# GetThemeSysFont function

## Description

Retrieves the [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) of a system font.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to theme data.

### `iFontId` [in]

Type: **int**

Value of type **int** that specifies a system font. May be one of the following values.

| Value | Meaning |
| --- | --- |
| **TMT_CAPTIONFONT** | The font used by window captions. |
| **TMT_SMALLCAPTIONFONT** | The font used by window small captions. |
| **TMT_MENUFONT** | The font used by menus. |
| **TMT_STATUSFONT** | The font used in status messages. |
| **TMT_MSGBOXFONT** | The font used to display messages in a message box. |
| **TMT_ICONTITLEFONT** | The font used for icons. |

### `plf` [out]

Type: **LOGFONTW***

Pointer to a [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) structure that receives the font information from this function.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function requires vssym32.h and uxtheme.h.

If the theme data handle is not a **NULL** handle, this function returns the desired [LOGFONT](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-logfonta) from the SysMetrics section of the visual style. If the theme data handle is **NULL**, the function returns the value of the global system metric of the same type.

The font is scaled in dots per inch for the current logical screen.