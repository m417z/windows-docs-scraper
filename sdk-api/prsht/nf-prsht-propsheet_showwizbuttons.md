# PropSheet_ShowWizButtons macro

## Syntax

```cpp
VOID PropSheet_ShowWizButtons(
   HWND  hDlg,
   DWORD dwFlag,
   DWORD dwButton
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

This macro does not return a value.

## Description

Show or hide buttons in a wizard. You can use this macro or send the [PSM_SHOWWIZBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/psm-showwizbuttons) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard.

### `dwFlag`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the following values that specify which property sheet buttons are to be shown. If a button value is included in both this parameter and *dwButton* then it is shown.

| Value | Meaning |
| --- | --- |
| **PSWIZB_BACK** | 0x0001. The **Back** button. |
| **PSWIZB_NEXT** | 0x0002. The **Next** button. |
| **PSWIZB_FINISH** | 0x0004. The **Finish** button. |
| **PSWIZB_CANCEL** | 0x0010. The **Cancel** button. |
| **PSWIZB_SHOW** | Set only this flag (defined as zero) to hide all buttons specified in *dwButton*. |
| **PSWIZB_RESTORE** | Not implemented. |

### `dwButton`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the same values used in *dwFlag*. Here, they specify which property sheet buttons are to be shown or hidden. If a button value appears in this parameter but not in *dwFlag*, it indicates that the button should be hidden.

## Remarks

The following example code hides the **Back** button and shows the **Next** button.

```
PropSheet_ShowWizButtons(hwnd,
                         PSWIZB_NEXT,
                         PSWIZB_BACK | PSWIZB_NEXT);
```