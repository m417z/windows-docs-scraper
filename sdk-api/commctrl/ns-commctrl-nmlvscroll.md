# NMLVSCROLL structure

## Description

Provides information about a scrolling operation.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains information about a [LVN_ENDSCROLL](https://learn.microsoft.com/windows/desktop/Controls/lvn-endscroll) or a [LVN_BEGINSCROLL](https://learn.microsoft.com/windows/desktop/Controls/lvn-beginscroll) notification code.

### `dx`

Type: **int**

Value of type **int** that specifies in pixels the horizontal position where a scrolling operation should begin or end.

### `dy`

Type: **int**

Value of type **int** that specifies in pixels the vertical position where a scrolling operation should begin or end.