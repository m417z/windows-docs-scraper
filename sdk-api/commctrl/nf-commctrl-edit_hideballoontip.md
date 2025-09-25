# Edit_HideBalloonTip macro

## Syntax

```cpp
BOOL Edit_HideBalloonTip(
   HWND hwnd
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Hides any balloon tip associated with an edit control. You can use this macro or send the [EM_HIDEBALLOONTIP](https://learn.microsoft.com/windows/desktop/Controls/em-hideballoontip) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

**Conceptual**

[EM_HIDEBALLOONTIP](https://learn.microsoft.com/windows/desktop/Controls/em-hideballoontip)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

**Reference**