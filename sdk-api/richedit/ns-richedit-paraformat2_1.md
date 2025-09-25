# PARAFORMAT2 structure

## Description

Contains information about paragraph formatting attributes in a rich edit control. **PARAFORMAT2** is a Microsoft Rich Edit 2.0 extension of the [PARAFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-paraformat) structure. Microsoft Rich Edit 2.0 allows you to use either structure with the [EM_GETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getparaformat) and [EM_SETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setparaformat) messages.

## Members

#### - cbSize

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Structure size, in bytes. Before passing this structure to a rich edit control, set **cbSize** to the size of the [PARAFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-paraformat) or **PARAFORMAT2** structure. If **cbSize** equals the size of a **PARAFORMAT** structure, the control uses only the **PARAFORMAT** members.

#### - dwMask

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The members of the **PARAFORMAT2** structure that contain valid information. The
**dwMask** member can be a combination of the values from two sets of bit flags. One set indicates the structure members that are valid; another set indicates the valid attributes in the
**wEffects** member.

Set the following values to indicate the valid structure members.

| Value | Meaning |
| --- | --- |
| **PFM_ALIGNMENT** | The **wAlignment** member is valid. |
| **PFM_ALL** | A combination of the following values: PFM_STARTINDENT, PFM_RIGHTINDENT, PFM_OFFSET, PFM_ALIGNMENT, PFM_TABSTOPS, PFM_NUMBERING, PFM_OFFSETINDENT, and PFM_RTLPARA. |
| **PFM_ALL2** | A combination of the following values: PFM_ALL, PFM_EFFECTS, PFM_SPACEBEFORE, PFM_SPACEAFTER, PFM_LINESPACING, PFM_STYLE, PFM_SHADING, PFM_BORDER, PFM_NUMBERINGTAB, PFM_NUMBERINGSTART, and PFM_NUMBERINGSTYLE. |
| **PFM_BORDER** | The **wBorderSpace**, **wBorderWidth**, and **wBorders** members are valid. |
| **PFM_LINESPACING** | The **dyLineSpacing** and **bLineSpacingRule** members are valid. |
| **PFM_NUMBERING** | The **wNumbering** member is valid. |
| **PFM_NUMBERINGSTART** | The **wNumberingStart** member is valid. |
| **PFM_NUMBERINGSTYLE** | The **wNumberingStyle** member is valid. |
| **PFM_NUMBERINGTAB** | The **wNumberingTab** member is valid. |
| **PFM_OFFSET** | The **dxOffset** member is valid. |
| **PFM_OFFSETINDENT** | The **dxStartIndent** member is valid. If you are setting the indentation, **dxStartIndent** specifies the amount to indent relative to the current indentation. |
| **PFM_OUTLINELEVEL** | The **bOutlineLevel** member is valid. |
| **PFM_RIGHTINDENT** | The **dxRightIndent** member is valid. |
| **PFM_SHADING** | The **wShadingWeight** and **wShadingStyle** members are valid. |
| **PFM_SPACEAFTER** | The **dySpaceAfter** member is valid. |
| **PFM_SPACEBEFORE** | The **dySpaceBefore** member is valid. |
| **PFM_STARTINDENT** | The **dxStartIndent** member is valid and specifies the indentation from the left margin. If both PFM_STARTINDENT and PFM_OFFSETINDENT are specified, PFM_STARTINDENT takes precedence. |
| **PFM_STYLE** | The **sStyle** member is valid. |
| **PFM_TABSTOPS** | The **cTabCount** and **rgxTabs** members are valid. |

Set the following values to indicate the valid attributes of the **wEffects** member.

| Value | Meaning |
| --- | --- |
| **PFM_DONOTHYPHEN** | The PFE_DONOTHYPHEN value is valid. |
| **PFM_EFFECTS** | A combination of the following values: PFM_RTLPARA, PFM_KEEP, PFM_KEEPNEXT, PFM_TABLE, PFM_PAGEBREAKBEFORE, PFM_NOLINENUMBER, PFM_NOWIDOWCONTROL, PFM_DONOTHYPHEN, PFM_SIDEBYSIDE, and PFM_TABLEROWDELIMITER. |
| **PFM_KEEP** | The PFE_KEEP value is valid. |
| **PFM_KEEPNEXT** | The PFE_KEEPNEXT value is valid. |
| **PFM_NOLINENUMBER** | The PFE_NOLINENUMBER value is valid. |
| **PFM_NOWIDOWCONTROL** | The PFE_NOWIDOWCONTROL value is valid. |
| **PFM_PAGEBREAKBEFORE** | The PFE_PAGEBREAKBEFORE value is valid. |
| **PFM_RTLPARA** | The PFE_RTLPARA value is valid. |
| **PFM_SIDEBYSIDE** | The PFE_SIDEBYSIDE value is valid. |
| **PFM_TABLE** | The PFE_TABLE value is valid. |
| **PFM_TABLEROWDELIMITER** | The PFE_TABLEROWDELIMITER value is valid. |

#### - wNumbering

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Options used for bulleted or numbered paragraphs. To use this member, set the PFM_NUMBERING flag in the
**dwMask** member.

This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **zero** | No paragraph numbering or bullets. |
| **PFN_BULLET** | Insert a bullet at the beginning of each selected paragraph. |

Rich Edit versions earlier than version 3.0 do not display paragraph numbers. However, for compatibility with Microsoft [Text Object Model](https://learn.microsoft.com/windows/win32/controls/text-object-model) (TOM) interfaces,
**wNumbering** can specify one of the following values. (The rich edit control stores the value but does not use it to display the text.)

| Value | Meaning |
| --- | --- |
| **PFN_ARABIC** | Use Arabic numbers (0, 1, 2, and so on). |
| **PFN_LCLETTER** | Use lowercase letters (a, b, c, and so on). |
| **PFN_LCROMAN** | Use lowercase Roman letters (i, ii, iii, and so on). |
| **PFN_UCLETTER** | Use uppercase letters (A, B, C, and so on). |
| **PFN_UCROMAN** | Use uppercase Roman letters (I, II, III, and so on). |
| **7** | Uses a sequence of characters beginning with the Unicode character specified by the **wNumberingStart** member. |

### `wReserved`

#### - wEffects

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This member is also known as **wReserved** for Microsoft Rich Edit 1.0 because it was reserved.

**Rich Edit 1.0:**
Reserved; the value must be zero.

**Rich Edit 2.0:** A set of bit flags that specify paragraph effects. These flags are included only for compatibility with TOM interfaces; the rich edit control stores the value but does not use it to display the text.

This member can be a combination of the following values.

| Value | Meaning |
| --- | --- |
| **PFE_DONOTHYPHEN** | Disables automatic hyphenation. |
| **PFE_KEEP** | No page break within the paragraph. |
| **PFE_KEEPNEXT** | No page break between this paragraph and the next. |
| **PFE_NOLINENUMBER** | Disables line numbering (not implemented). |
| **PFE_NOWIDOWCONTROL** | Disables widow and orphan control for the selected paragraph. |
| **PFE_PAGEBREAKBEFORE** | Inserts a page break before the selected paragraph. |
| **PFE_RTLPARA** | Displays text using right-to-left reading order (in Rich Edit 2.1 and later). |
| **PFE_SIDEBYSIDE** | Displays paragraphs side by side (not implemented). |
| **PFE_TABLE** | The paragraph is a table row. |
| **PFE_TABLEROWDELIMITER** | The paragraph is a start delimiter (U+FFF9 U+000D) or end delimiter (U+FFFB U+000D) of a row in a table. |

#### - dxStartIndent

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indentation of the paragraph's first line, in twips. The indentation of subsequent lines depends on the **dxOffset** member. To use the **dxStartIndent** member, set the PFM_STARTINDENT or PFM_OFFSETINDENT flag in the **dwMask** member. If you are setting the indentation, use the PFM_STARTINDENT flag to specify an absolute indentation from the left margin; or use the PFM_OFFSETINDENT flag to specify an indentation relative to the paragraph's current indentation. Use either flag to retrieve the current indentation.

#### - dxRightIndent

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indentation of the right side of the paragraph, relative to the right margin, in twips. To use this member, set the PFM_RIGHTINDENT flag in the **dwMask** member.

#### - dxOffset

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indentation of the second and subsequent lines, relative to the indentation of the first line, in twips. The first line is indented if this member is negative or outdented if this member is positive. To use this member, set the PFM_OFFSET flag in the **dwMask** member.

#### - wAlignment

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Paragraph alignment. To use this member, set the PFM_ALIGNMENT flag in the **dwMask** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PFA_LEFT** | Paragraphs are aligned with the left margin. |
| **PFA_RIGHT** | Paragraphs are aligned with the right margin. |
| **PFA_CENTER** | Paragraphs are centered. |
| **PFA_JUSTIFY** | **RichEdit 2.0:**Paragraphs are justified. Rich edit controls earlier than RichEdit 3.0 display the text aligned with the left margin. |
| **PFA_FULL_INTERWORD** | Paragraphs are justified by expanding the blanks alone. |

#### - cTabCount

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of tab stops defined in the
**rgxTabs** array.

#### - rgxTabs

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

### `dySpaceBefore`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the spacing above the paragraph, in twips. To use this member, set the PFM_SPACEBEFORE flag in the
**dwMask** member. The value must be greater than or equal to zero.

### `dySpaceAfter`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the size of the spacing below the paragraph, in twips. To use this member, set the PFM_SPACEAFTER flag in the
**dwMask** member. The value must be greater than or equal to zero.

### `dyLineSpacing`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Spacing between lines. For a description of how this value is interpreted, see the
**bLineSpacingRule** member. To use this member, set the PFM_LINESPACING flag in the
**dwMask** member.

### `sStyle`

Type: **[SHORT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Text style. To use this member, set the PFM_STYLE flag in the
**dwMask** member. This member is included only for compatibility with TOM interfaces and Word; the rich edit control stores the value but does not use it to display the text.

### `bLineSpacingRule`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of line spacing. To use this member, set the PFM_LINESPACING flag in the
**dwMask** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Single spacing. The **dyLineSpacing** member is ignored. |
| **1** | One-and-a-half spacing. The **dyLineSpacing** member is ignored. |
| **2** | Double spacing. The **dyLineSpacing** member is ignored. |
| **3** | The **dyLineSpacing** member specifies the spacingfrom one line to the next, in twips. However, if **dyLineSpacing** specifies a value that is less than single spacing, the control displays single-spaced text. |
| **4** | The **dyLineSpacing** member specifies the spacing from one line to the next, in twips. The control uses the exact spacing specified, even if **dyLineSpacing** specifies a value that is less than single spacing. |
| **5** | The value of **dyLineSpacing** / 20 is the spacing, in lines, from one line to the next. Thus, setting **dyLineSpacing** to 20 produces single-spaced text, 40 is double spaced, 60 is triple spaced, and so on. |

### `bOutlineLevel`

Type: **[BYTE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Reserved; must be zero.

### `wShadingWeight`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Percentage foreground color used in shading. The
**wShadingStyle** member specifies the foreground and background shading colors. A value of 5 indicates a shading color consisting of 5 percent foreground color and 95 percent background color. To use these members, set the PFM_SHADING flag in the
**dwMask** member. This member is included only for compatibility with Word; the rich edit control stores the value but does not use it to display the text.

### `wShadingStyle`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Style and colors used for background shading. Bits 0 to 3 contain the shading style, bits 4 to 7 contain the foreground color index, and bits 8 to 11 contain the background color index. To use this member, set the PFM_SHADING flag in the
**dwMask** member. This member is included only for compatibility with Word; the rich edit control stores the value but does not use it to display the text.

The shading style can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | None |
| **1** | Dark horizontal |
| **2** | Dark vertical |
| **3** | Dark down diagonal |
| **4** | Dark up diagonal |
| **5** | Dark grid |
| **6** | Dark trellis |
| **7** | Light horizontal |
| **8** | Light vertical |
| **9** | Light down diagonal |
| **10** | Light up diagonal |
| **11** | Light grid |
| **12** | Light trellis |

The foreground and background color indexes can be one of the following values.

| Value | Meaning |
| --- | --- |
| **0** | Black |
| **1** | Blue |
| **2** | Cyan |
| **3** | Green |
| **4** | Magenta |
| **5** | Red |
| **6** | Yellow |
| **7** | White |
| **8** | Dark blue |
| **9** | Dark cyan |
| **10** | Dark green |
| **11** | Dark magenta |
| **12** | Dark red |
| **13** | Dark yellow |
| **14** | Dark gray |
| **15** | Light gray |

### `wNumberingStart`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Starting number or Unicode value used for numbered paragraphs. Use this member in conjunction with the
**wNumbering** member. This member is included only for compatibility with TOM interfaces; the rich edit control stores the value but does not use it to display the text or bullets. To use this member, set the PFM_NUMBERINGSTART flag in the
**dwMask** member.

### `wNumberingStyle`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Numbering style used with numbered paragraphs. Use this member in conjunction with the
**wNumbering** member. This member is included only for compatibility with TOM interfaces; the rich edit control stores the value but rich edit versions earlier than 3.0 do not use it to display the text or bullets. To use this member, set the PFM_NUMBERINGSTYLE flag in the
**dwMask** member. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **PFNS_PAREN** | Follows the number with a right parenthesis. |
| **PFNS_PARENS** | Encloses the number in parentheses. |
| **PFNS_PERIOD** | Follows the number with a period. |
| **PFNS_PLAIN** | Displays only the number. |
| **PFNS_NONUMBER** | Continues a numbered list without applying the next number or bullet. |
| **PFNS_NEWNUMBER** | Starts a new number with **wNumberingStart**. |

### `wNumberingTab`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum space between a paragraph number and the paragraph text, in twips. Use this member in conjunction with the
**wNumbering** member. The
**wNumberingTab** member is included for compatibility with TOM interfaces; previous to Microsoft Rich Edit 3.0, the rich edit control stores the value but does not use it to display text. To use this member, set the PFM_NUMBERINGTAB flag in the
**dwMask** member.

### `wBorderSpace`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The space between the border and the paragraph text, in twips. The
**wBorderSpace** member is included for compatibility with Word; the rich edit control stores the values but does not use them to display text. To use this member, set the PFM_BORDER flag in the
**dwMask** member.

### `wBorderWidth`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Border width, in twips. To use this member, set the PFM_BORDER flag in the
**dwMask** member.

### `wBorders`

Type: **[WORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Border location, style, and color. Bits 0 to 7 specify the border locations, bits 8 to 11 specify the border style, and bits 12 to 15 specify the border color index. To use this member, set the PFM_BORDER flag in the
**dwMask** member.

Specify the border locations using a combination of the following values in bits 0 to 7.

| Value | Meaning |
| --- | --- |
| **1** | Left border. |
| **2** | Right border. |
| **4** | Top border. |
| **8** | Bottom border. |
| **16** | Inside borders. |
| **32** | Outside borders. |
| **64** | Autocolor. If this bit is set, the color index in bits 12 to 15 is not used. |

Specify the border style using one of the following values for bits 8 to 11.

| Value | Meaning |
| --- | --- |
| **0** | None |
| **1** | **3**/**4** point |
| **2** | 1**1**/**2** point |
| **3** | 2**1**/**4** point |
| **4** | 3 point |
| **5** | 4**1**/**2** point |
| **6** | 6 point |
| **7** | **3**/**4** point double |
| **8** | 1**1**/**2** point double |
| **9** | 2**1**/**4** point double |
| **10** | **3**/**4** point gray |
| **11** | **3**/**4** point gray dashed |

Specify the border color using one of the following values for bits 12 to 15. This value is ignored if the autocolor bit (bit 6) is set.

| Value | Meaning |
| --- | --- |
| **0** | Black |
| **1** | Blue |
| **2** | Cyan |
| **3** | Green |
| **4** | Magenta |
| **5** | Red |
| **6** | Yellow |
| **7** | White |
| **8** | Dark blue |
| **9** | Dark cyan |
| **10** | Dark green |
| **11** | Dark magenta |
| **12** | Dark red |
| **13** | Dark yellow |
| **14** | Dark gray |
| **15** | Light gray |

## See also

[EM_GETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-getparaformat)

[EM_SETPARAFORMAT](https://learn.microsoft.com/windows/win32/controls/em-setparaformat)

[PARAFORMAT](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-paraformat)