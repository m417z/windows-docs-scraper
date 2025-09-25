# NMLVFINDITEMW structure

## Description

Contains information the owner needs to find items requested by a [virtual list-view](https://learn.microsoft.com/windows/desktop/Controls/list-view-controls-overview) control. This structure is used with the [LVN_ODFINDITEM](https://learn.microsoft.com/windows/desktop/Controls/lvn-odfinditem) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information on this notification code.

### `iStart`

Type: **int**

Index of the item at which the search will start.

### `lvfi`

Type: **[LVFINDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfindinfoa)**

[LVFINDINFO](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-lvfindinfoa) structure that contains information necessary to perform a search.

## Remarks

> [!NOTE]
> The commctrl.h header defines NMLVFINDITEM as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).