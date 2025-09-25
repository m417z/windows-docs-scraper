# SelectFont macro

## Syntax

```cpp
HFONT SelectFont(
    HDC hdc,
    HFONT hfont
);
```

## Return value

Type: **[HFONT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If **SelectFont** succeeds, the return value is a handle to the font object being replaced. If an error occurs, the return value is **NULL**.

## Description

The **SelectFont** macro selects a font object into the specified device context (DC). The new font object replaces the previous font object.

## Parameters

### `hdc`

A handle to the DC.

### `hfont`

A handle to the font object to be selected. The font object must have been created using either [CreateFont](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfonta) or [CreateFontIndirect](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createfontindirecta).

## Remarks

After an application has finished drawing with the new font object, it should always replace a new font object with the original font object.

The **SelectFont** macro is equivalent to calling [SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject) as follows:

``` syntax

((HFONT) SelectObject((hdc), (HGDIOBJ)(HFONT)(hfont)))

```

## See also

[DeleteFont](https://learn.microsoft.com/windows/desktop/api/windowsx/nf-windowsx-deletefont)

[SelectObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-selectobject)