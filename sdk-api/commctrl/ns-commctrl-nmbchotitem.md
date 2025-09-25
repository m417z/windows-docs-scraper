# NMBCHOTITEM structure

## Description

Contains information about the movement of the mouse over a button control.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The action of the mouse. This parameter can be one of the following values combined with HICF_MOUSE.

| Value | Meaning |
| --- | --- |
| **HICF_ENTERING** | The mouse is entering the button. |
| **HICF_LEAVING** | The mouse is leaving the button. |

## See also

[BCN_HOTITEMCHANGE](https://learn.microsoft.com/windows/desktop/Controls/bcn-hotitemchange)

[Buttons](https://learn.microsoft.com/windows/desktop/Controls/buttons)

**Conceptual**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)

**Reference**