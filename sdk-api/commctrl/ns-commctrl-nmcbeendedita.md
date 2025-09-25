# NMCBEENDEDITA structure

## Description

Contains information about the conclusion of an edit operation within a ComboBoxEx control. This structure is used with the [CBEN_ENDEDIT](https://learn.microsoft.com/windows/desktop/Controls/cben-endedit) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification code.

### `fChanged`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value indicating whether the contents of the control's edit box have changed. This value is nonzero if the contents have been modified, or zero otherwise.

### `iNewSelection`

Type: **int**

The zero-based index of the item that will be selected after completing the edit operation. This value can be CB_ERR if no item will be selected.

### `szText`

Type: **[TCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A zero-terminated string that contains the text from within the control's edit box.

### `iWhy`

Type: **int**

A value that specifies the action that generated the [CBEN_ENDEDIT](https://learn.microsoft.com/windows/desktop/Controls/cben-endedit) notification code. This value can be one of the following:

| Value | Meaning |
| --- | --- |
| **CBENF_DROPDOWN** | The user activated the drop-down list. |
| **CBENF_ESCAPE** | The user pressed ESC. |
| **CBENF_KILLFOCUS** | The edit box lost the keyboard focus. |
| **CBENF_RETURN** | The user completed the edit operation by pressing ENTER. |

## Remarks

> [!NOTE]
> The commctrl.h header defines NMCBEENDEDIT as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).