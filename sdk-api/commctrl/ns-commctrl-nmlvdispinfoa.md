# NMLVDISPINFOA structure

## Description

Contains information about an [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) or [LVN_SETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-setdispinfo) notification code. This structure is the same as the **LV_DISPINFO** structure, but has been renamed to fit standard naming conventions.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about this notification code.

### `item`

Type: **[LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema)**

[LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure that identifies the item or subitem. The structure either contains or receives information about the item. The **mask** member contains a set of bit flags that specify which item attributes are relevant.
For more information on the available bit flags, see **LVITEM**.

## Remarks

If the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure is receiving item text, the **pszText** and **cchTextMax** members specify the address and size of a buffer. You can either copy text to the buffer or assign the address of a string to the **pszText** member. In the latter case, you must not change or delete the string until the corresponding item text is deleted or two additional [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) messages have been sent.

If you are handling the [LVN_GETDISPINFO](https://learn.microsoft.com/windows/desktop/Controls/lvn-getdispinfo) message, you can set the LVIF_DI_SETITEM flag in the **mask** member of the [LVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvitema) structure. This tells the operating system to store the requested list item information and not ask for it again. For list-view controls with the [LVS_REPORT](https://learn.microsoft.com/windows/desktop/Controls/list-view-window-styles) style, this flag only applies to the first (subitem 0) column's information. The control will not store information for subitems.

> [!NOTE]
> The commctrl.h header defines NMLVDISPINFO as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).