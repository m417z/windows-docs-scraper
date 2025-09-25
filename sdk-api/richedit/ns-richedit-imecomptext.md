# IMECOMPTEXT structure

## Description

Contains information about the Input Method Editor (IME) composition text in a Microsoft Rich Edit control.

## Members

### `cb`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the output buffer, in bytes.

### `flags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of composition string. It can be one of the following values.

| Value | Meaning |
| --- | --- |
| **ICT_RESULTREADSTR** | The final composed string. |

## Remarks

This structure is used with the [EM_GETIMECOMPTEXT](https://learn.microsoft.com/windows/win32/controls/em-getimecomptext) message.

## See also

[EM_GETIMECOMPTEXT](https://learn.microsoft.com/windows/win32/controls/em-getimecomptext)