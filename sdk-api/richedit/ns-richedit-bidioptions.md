# BIDIOPTIONS structure

## Description

Contains bidirectional information about a rich edit control. This structure is used by the [EM_GETBIDIOPTIONS](https://learn.microsoft.com/windows/win32/controls/em-getbidioptions) and [EM_SETBIDIOPTIONS](https://learn.microsoft.com/windows/win32/controls/em-setbidioptions) messages to get and set the bidirectional information for a control.

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size, in bytes, of the structure. Before passing this structure to a rich edit control, set **cbSize** to the size of the **BIDIOPTIONS** structure. The rich edit control checks the size of **cbSize** before sending an [EM_GETBIDIOPTIONS](https://learn.microsoft.com/windows/win32/controls/em-getbidioptions) message.

### `wMask`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of mask bits that determine which of the **wEffects** flags will be set to 1 or 0 by the rich edit control. This approach eliminates the need to read the effects flags before changing them.

Obsolete bits are valid only for the bidirectional version of Rich Edit 1.0.

| Value | Meaning |
| --- | --- |
| **BOM_CONTEXTALIGNMENT** | The BOE_CONTEXTALIGNMENT value is valid. |
| **BOM_CONTEXTREADING** | The BOE_CONTEXTREADING value is valid. |
| **BOM_DEFPARADIR** | The BOE_RTLDIR value is valid. |
| **BOM_LEGACYBIDICLASS** | The BOE_LEGACYBIDICLASS value is valid. |
| **BOM_NEUTRALOVERRIDE** | The BOE_NEUTRALOVERRIDE value is valid. |
| **BOM_PLAINTEXT** | The BOE_PLAINTEXT value is valid. (obsolete). |
| **BOM_UNICODEBIDI** | The BOE_UNICODEBIDI value is valid. |

### `wEffects`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A set of flags that indicate the desired or current state of the effects flags. Obsolete bits are valid only for the bidirectional version of Rich Edit 1.0.

Obsolete bits are valid only for the bidirectional version of Rich Edit 1.0.

| Value | Meaning |
| --- | --- |
| **BOE_CONTEXTALIGNMENT** | If this flag is 1, context paragraph alignment is active. This feature is used only for plain-text controls. When active, the paragraph alignment is set to PFA_LEFT if the first strongly directional character is LTR, or PFA_RIGHT if the first strongly directional character is RTL. If the control has no strongly directional character, the alignment is chosen according to the directionality of the keyboard language when the control regains focus (default: 0). |
| **BOE_CONTEXTREADING** | If this flag is 1, context paragraph directionality is active. This feature is used only for plain-text controls. When active, the paragraph directionality effect PFE_RTLPARA is set to 0 if the first strongly directional character is LTR, or 1 if the first strongly directional character is RTL. If the control has no strongly directional character, the directionality is chosen according to the directionality of <br><br>the keyboard language when the control regains focus (default: 0). |
| **BOE_FORCERECALC** | **Windows 8**: Force the rich edit control to recalculate the bidirectional information, and then redraw the control. |
| **BOE_LEGACYBIDICLASS** | Causes the plus and minus characters to be treated as neutral characters with no implied direction. Also causes the slash character to be treated as a common separator. |
| **BOE_NEUTRALOVERRIDE** | If this flag is 1, the characters !"#&'()*+,-./:;<=> are treated as strong LTR characters (default: 0). |
| **BOE_PLAINTEXT** | Uses plain text layout (obsolete). |
| **BOE_RTLDIR** | Default paragraph direction—implies alignment (obsolete). |
| **BOE_UNICODEBIDI** | If this flag is 1, the Unicode Bidi Algorithm (UBA) is used for rich-text controls. The UBA is always used for plain-text controls (default: 0). |

## See also

[EM_GETBIDIOPTIONS](https://learn.microsoft.com/windows/win32/controls/em-getbidioptions)

[EM_SETBIDIOPTIONS](https://learn.microsoft.com/windows/win32/controls/em-setbidioptions)