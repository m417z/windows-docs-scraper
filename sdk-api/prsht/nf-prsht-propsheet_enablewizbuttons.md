# PropSheet_EnableWizButtons macro

## Syntax

```cpp
VOID PropSheet_EnableWizButtons(
   HWND  hDlg,
   DWORD dwState,
   DWORD dwMask
);
```

## Return value

Type: **[VOID](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

No meaningful return value.

## Description

Enables or disables buttons in an Aero wizard. You can use this macro or send the [PSM_ENABLEWIZBUTTONS](https://learn.microsoft.com/windows/desktop/Controls/psm-enablewizbuttons) message explicitly.

## Parameters

### `hDlg`

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the wizard.

### `dwState`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the following values that specify which property sheet buttons are to be enabled. If a button value is included in both this parameter and *dwMask*, it is enabled.

| Value | Meaning |
| --- | --- |
| **PSWIZB_BACK** | 0x0001. The **Back** button. |
| **PSWIZB_NEXT** | 0x0002. The **Next** button. |
| **PSWIZB_FINISH** | 0x0004. The **Finish** button. |
| **PSWIZB_CANCEL** | 0x0010. The **Cancel** button. |

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One or more of the same values used in *dwState*, specifying which buttons are affected by this call. If a button value appears in this parameter but not in *dwState*, the button is disabled.

## Remarks

The following example code enables the **Back** button and disables the **Next** button.

```
PropSheet_EnableWizButtons(hwnd,
                         PSWIZB_NEXT,
                         PSWIZB_BACK | PSWIZB_NEXT);
```