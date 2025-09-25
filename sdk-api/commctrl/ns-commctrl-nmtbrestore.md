## Description

Allows applications to extract the information that was placed in [NMTBSAVE](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-nmtbsave) when the toolbar state was saved. This structure is passed to applications when they receive a [TBN_RESTORE](https://learn.microsoft.com/windows/desktop/Controls/tbn-restore) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `pData`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the data stream with the stored save information. It contains Shell-defined blocks of information for each button, alternating with application-defined blocks. Applications may also place a block of global data at the start of
**pData**. The format and length of the application-defined blocks are determined by the application.

### `pCurrent`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Pointer to the current block of application-defined data. After extracting the data, the application must advance
**pCurrent** to the end of the block, so it is pointing to the next block of Shell-defined data.

### `cbData`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of
**pData**.

### `iItem`

Type: **int**

Value of -1 indicates that the restore is starting, and
**pCurrent** will point to the start of the data stream. Otherwise, it is the zero-based button index, and
**pCurrent** will point to the current button's data.

### `cButtons`

Type: **int**

Estimate of the number of buttons. Because the estimate is based on the size of the data stream, it might be incorrect. The client should update it as appropriate.

### `cbBytesPerRecord`

Type: **int**

Number of bytes needed to hold the data for each button. When the restore starts,
**cbBytesPerRecord** will be set to the size of the Shell-defined data structure. You need to increment it by the size of the structure that holds the application-defined data.

### `tbButton`

Type: **[TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton)**

[TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structure that contains information about the button currently being restored. Applications must modify this structure as necessary before returning.