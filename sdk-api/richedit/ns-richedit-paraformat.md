# PARAFORMAT structure

## Description

Contains information about paragraph formatting attributes in a rich edit control. This structure is used with the [EM_GETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getparaformat) and [EM_SETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setparaformat) messages.

In Microsoft Rich Edit 2.0, the [PARAFORMAT2](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-paraformat2) structure is a Microsoft Rich Edit 2.0 extension of the **PARAFORMAT** structure. Microsoft Rich Edit 2.0 allows you to use either structure with [EM_GETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getparaformat) and [EM_SETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setparaformat).

## Members

### `cbSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Structure size, in bytes. The member must be filled before passing to the rich edit control.

### `dwMask`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Members containing valid information or attributes to set. This parameter can be none or a combination of the following values. If both PFM_STARTINDENT and PFM_OFFSETINDENT are specified, PFM_STARTINDENT takes precedence.

| Value | Meaning |
| --- | --- |
| **PFM_ALIGNMENT** | The **wAlignment** member is valid. |
| **PFM_NUMBERING** | The **wNumbering** member is valid. |
| **PFM_OFFSET** | The **dxOffset** member is valid. |
| **PFM_OFFSETINDENT** | The **dxStartIndent** member is valid and specifies a relative value. |
| **PFM_RIGHTINDENT** | The **dxRightIndent** member is valid. |
| **PFM_RTLPARA** | **Rich Edit 2.0:** The **wEffects** member is valid |
| **PFM_STARTINDENT** | The **dxStartIndent** member is valid. |
| **PFM_TABSTOPS** | The *cTabStobs* and *rgxTabStops* members are valid. |

### `wNumbering`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying numbering options. This member can be zero or PFN_BULLET.

### `wReserved`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**Rich Edit 1.0:**: This member is named **wReserved**. Reserved; the value must be zero.

**Rich Edit 2.0:** This member is named **wEffects**. A bit flag that specifies a paragraph effect. It is included only for compatibility with TOM interfaces; the rich edit control stores the value but does not use it to display the text. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Displays text using left-to-right reading order. This is the default. |
| **PFE_RLTPARA** | Displays text using right-to-left reading order. |

### `wEffects`

### `dxStartIndent`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indentation of the first line in the paragraph, in twips. If the paragraph formatting is being set and PFM_OFFSETINDENT is specified, this member is treated as a relative value that is added to the starting indentation of each affected paragraph.

### `dxRightIndent`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size, of the right indentation relative to the right margin, in twips.

### `dxOffset`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indentation of the second and subsequent lines of a paragraph relative to the starting indentation, in twips. The first line is indented if this member is negative or outdented if this member is positive.

### `wAlignment`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Value specifying the paragraph alignment. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PFA_CENTER** | Paragraphs are centered. |
| **PFA_LEFT** | Paragraphs are aligned with the left margin. |
| **PFA_RIGHT** | Paragraphs are aligned with the right margin. |

### `cTabCount`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of tab stops.

### `rgxTabs`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Array of absolute tab stop positions. Each element in the array specifies information about a tab stop. The 24 low-order bits specify the absolute offset, in twips. To use this member, set the PFM_TABSTOPS flag in the
**dwMask** member.

**Rich Edit 2.0:** For compatibility with TOM interfaces, you can use the eight high-order bits to store additional information about each tab stop.

Bits 24-27 can specify one of the following values to indicate the tab alignment. These bits do not affect the rich edit control display for versions earlier than Microsoft Rich Edit 3.0.

| Value | Meaning |
| --- | --- |
| **0** | Ordinary tab |
| **1** | Center tab |
| **2** | Right-aligned tab |
| **3** | Decimal tab |
| **4** | Word bar tab (vertical bar) |

Bits 28-31 can specify one of the following values to indicate the type of tab leader. These bits do not affect the rich edit control display.

| Value | Meaning |
| --- | --- |
| **0** | No leader |
| **1** | Dotted leader |
| **2** | Dashed leader |
| **3** | Underlined leader |
| **4** | Thick line leader |
| **5** | Double line leader |

## See also

[EM_GETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getparaformat)

[EM_SETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setparaformat)

[PARAFORMAT2](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-paraformat2)

**Reference**