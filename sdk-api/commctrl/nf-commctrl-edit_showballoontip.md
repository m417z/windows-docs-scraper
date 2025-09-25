# Edit_ShowBalloonTip macro

## Syntax

```cpp
BOOL Edit_ShowBalloonTip(
   HWND            hwnd,
   PEDITBALLOONTIP peditballoontip
);
```

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

If the macro succeeds, it returns **TRUE**. Otherwise it returns **FALSE**.

## Description

Displays a balloon tip associated with an edit control. You can use this macro or send the [EM_SHOWBALLOONTIP](https://learn.microsoft.com/windows/desktop/Controls/em-showballoontip) message explicitly.

## Parameters

### `hwnd`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the edit control.

### `peditballoontip`

Type: **PEDITBALLOONTIP**

A pointer to an [EDITBALLOONTIP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-editballoontip) structure that contains information about the balloon tip to display.

## Remarks

**Note** To use this macro, you must provide a manifest specifying Comctl32.dll version 6.0. For more information on manifests, see [Enabling Visual Styles](https://learn.microsoft.com/windows/desktop/Controls/cookbook-overview).

## See also

**Conceptual**

[EDITBALLOONTIP](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-editballoontip)

[EM_SHOWBALLOONTIP](https://learn.microsoft.com/windows/desktop/Controls/em-showballoontip)

[Edit Controls](https://learn.microsoft.com/windows/desktop/Controls/edit-controls)

**Reference**