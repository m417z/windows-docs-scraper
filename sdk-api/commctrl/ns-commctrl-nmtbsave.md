# NMTBSAVE structure

## Description

This structure is passed to applications when they receive a [TBN_SAVE](https://learn.microsoft.com/windows/desktop/Controls/tbn-save) notification code. It contains information about the button currently being saved. Applications can modify the values of the members to save additional information.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

An [NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr) structure that contains additional information about the notification.

### `pData`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the data stream used to store the save information. When complete, it will contain blocks of Shell-defined information for each button, alternating with blocks defined by the application. Applications may also choose to place a block of global data at the start of
**pData**. The format and length of the application-defined blocks are determined by the application. When the save starts, the Shell will pass the amount of memory it needs in
**cbData**, but no memory will be allocated. You must allocate enough memory for
**pData** to hold your data, plus the Shell's.

### `pCurrent`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to the start of the unused portion of the data stream. You should load your data here, and then advance
**pCurrent** to the start of the remaining unused portion. The Shell will then load the information for the next button, advance
**pCurrent**, and so on.

### `cbData`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the data stream. When the save starts,
**cbData** will be set to the amount of data needed by the Shell. You should change it to the total amount allocated.

### `iItem`

Type: **int**

This parameter is usually the zero-based index of the button currently being saved. It is set to -1 to indicate that a save is starting.

### `cButtons`

Type: **int**

An estimate of the number of buttons. Because it is based on the size of the data stream, it may be incorrect. The client should update it as appropriate.

### `tbButton`

Type: **[TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton)**

A [TBBUTTON](https://learn.microsoft.com/windows/desktop/api/commctrl/ns-commctrl-tbbutton) structure that contains information about the button currently being saved.