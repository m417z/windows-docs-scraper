# NMTVASYNCDRAW structure

## Description

Contains an explanation of why the draw of an icon or overlay tree item failed. This structure is sent on a [TVN_ASYNCDRAW](https://learn.microsoft.com/windows/desktop/Controls/tvn-asyncdraw) notification. Set the **dwRetFlags** member to indicate what action the control should take. Note that a draw can fail if there is no image; in other words, when the icon image has not been extracted.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure.

### `pimldp`

Type: **[IMAGELISTDRAWPARAMS](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imagelistdrawparams)***

[IMAGELISTDRAWPARAMS](https://learn.microsoft.com/windows/desktop/api/commoncontrols/ns-commoncontrols-imagelistdrawparams) structure describing the image that failed to draw.

### `hr`

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Result code indicating why the draw failed, either ILDRF_IMAGELOWQUALITY, ILDRF_OVERLAYLOWQUALITY, E_PENDING, or S_OK. A code of S_OK indicates that the image is present but not at the required image quality.

### `hItem`

Type: **HTREEITEM**

Handle of the tree item that failed to draw.

### `lParam`

Type: **[LPARAM](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Data for **hItem**. This is the same data for the item that is retrieved with the message [TVM_GETITEM](https://learn.microsoft.com/windows/desktop/Controls/tvm-getitem) using the appropriate **mask** in structure [TVITEM](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tvitema). This data is parent specific; the parent can store information that helps it identify the tree item or other information. Data is provided in **lParam** for convenience, so that the parent does not need to send message **TVM_GETITEM**.

### `dwRetFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Action that the sender (the tree-view control) should execute on return. Value must be one of the following flags:

| Value | Meaning |
| --- | --- |
| **ADRF_DRAWIMAGE** | Draw the image specified by **iRetImageIndex**. |
| **ADRF_DRAWSYNC** | Proceed to draw the image anyway, that is, synchronously extract the image and paint. Assuming the control is on the UI thread, use of this flag implies low priority UI performance, since extraction times may vary and the UI could be unresponsive for an extended period of time during extraction. |
| **ADRF_DRAWNOTHING** | Do not draw an image. |

### `iRetImageIndex`

Type: **int**

Index of the image to draw in the image list. Used if ADRF_DRAWIMAGE is returned in **dwRetFlags**.