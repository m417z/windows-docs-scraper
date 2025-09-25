# DrawThemeText function

## Description

Draws text using the color and font defined by the visual style.

## Parameters

### `hTheme` [in]

Type: **HTHEME**

Handle to a window's theme data. Use [OpenThemeData](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-openthemedata) to create an HTHEME.

### `hdc` [in]

Type: **[HDC](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

HDC to use for drawing.

### `iPartId` [in]

Type: **int**

The control part that has the desired text appearance. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states). If this value is 0, the text is drawn in the default font, or a font selected into the device context.

### `iStateId` [in]

Type: **int**

The control state that has the desired text appearance. See [Parts and States](https://learn.microsoft.com/windows/desktop/Controls/parts-and-states).

### `pszText` [in]

Type: **[LPCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that contains the text to draw.

### `cchText` [in]

Type: **int**

Value of type **int** that contains the number of characters to draw. If the parameter is set to -1, all the characters in the string are drawn.

### `dwTextFlags` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**DWORD** that contains one or more values that specify the string's formatting. See [Format Values](https://learn.microsoft.com/windows/desktop/Controls/theme-format-values) for possible parameter values.

**Note** DrawThemeText does not support DT_CALCRECT. However, [DrawThemeTextEx](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-drawthemetextex) does support DT_CALCRECT.

### `dwTextFlags2` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Not used. Set to zero.

### `pRect` [in]

Type: **LPCRECT**

Pointer to a [RECT](https://learn.microsoft.com/windows/desktop/api/windef/ns-windef-rect) structure that contains the rectangle, in logical coordinates, in which the text is to be drawn. It is recommended to use **pExtentRect** from [GetThemeTextExtent](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemetextextent) to retrieve the correct coordinates.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The function always uses the themed font for the specified part and state if one is defined. Otherwise it uses the font currently selected into the device context. To find out if a themed font is defined, you can call [GetThemeFont](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemefont) or [GetThemePropertyOrigin](https://learn.microsoft.com/windows/desktop/api/uxtheme/nf-uxtheme-getthemepropertyorigin) with TMT_FONT as the property identifier.

#### Examples

**DrawThemeText** uses parameters similar to the Win32 [DrawText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawtext) function, but with a few differences. One of the most notable is support for wide-character strings. Therefore, non-wide strings must be converted to wide strings, as in the following example.

**Security Warning:** Using [MultiByteToWideChar](https://learn.microsoft.com/windows/desktop/api/stringapiset/nf-stringapiset-multibytetowidechar) incorrectly can compromise the security of your application. Ensure that when creating wide-character buffers they are large enough to accommodate the size of the string in wide characters, not in bytes.

```cpp
INT cchText = GetWindowTextLength(_hwnd);
if (cchText > 0)
{
    TCHAR *pszText = new TCHAR[cchText+1];
    if (pszText)
    {
        if (GetWindowText(_hwnd, pszText, cchText+1))
        {
            int widelen = MultiByteToWideChar(CP_ACP, 0, reinterpret_cast<LPCSTR>(pszText),
                    cchText+1, NULL, 0);
            WCHAR *pszWideText = new WCHAR[widelen+1];
            MultiByteToWideChar(CP_ACP, 0, reinterpret_cast<LPCSTR>(pszText), cchText,
                    pszWideText, widelen);

            SetBkMode(hdcPaint, TRANSPARENT);
            DrawThemeText(_hTheme,
                    hdcPaint,
                    BP_PUSHBUTTON,
                    _iStateId,
                    pszWideText,
                    cchText,
                    DT_CENTER | DT_VCENTER | DT_SINGLELINE,
                    NULL,
                    &rcContent);

            delete [] pszWideText;
        }

        delete [] pszText;
    }
}

```

## See also

[Property Identifiers](https://learn.microsoft.com/windows/desktop/Controls/property-typedefs)