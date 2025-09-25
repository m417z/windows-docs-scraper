# NMHEADERW structure

## Description

Contains information about header control notification messages. This structure supersedes the
**HD_NOTIFY** structure.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

A [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about the notification message.

### `iItem`

Type: **int**

The zero-based index of the header item that is the focus of the notification message.

### `iButton`

Type: **int**

A value specifying the index of the mouse button used to generate the notification message. This member can be one of the following values:

| Value | Meaning |
| --- | --- |
| **0** | Left button |
| **1** | Right button |
| **2** | Middle button |

### `pitem`

Type: **[HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema)***

An optional pointer to an [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure containing information about the item specified by
**iItem**. The
**mask** member of the **HDITEM** structure indicates which of its members are valid.

## Remarks

While most header control notifications pass a pointer to an **NMHEADER** structure, only some of them use the **pitem** member to pass an [HDITEM](https://learn.microsoft.com/windows/win32/api/commctrl/ns-commctrl-hditema) structure. Those that do use **pitem** may not provide complete information about the item. To obtain more information about an item, use [HDM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/hdm-getitem).

> [!NOTE]
> The commctrl.h header defines NMHEADER as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).