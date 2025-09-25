# OBJECTPOSITIONS structure

## Description

Contains object position information.

## Members

### `nmhdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)**

The **code** member of this structure identifies the notification code being sent.

### `cObjectCount`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of object positions.

### `pcpPositions`

Type: **[LONG](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The object positions.

## Remarks

This is used in the [EN_OBJECTPOSITIONS](https://learn.microsoft.com/windows/win32/controls/en-objectpositions) notification.

## See also

[EN_OBJECTPOSITIONS](https://learn.microsoft.com/windows/win32/controls/en-objectpositions)

[NMHDR](https://learn.microsoft.com/windows/win32/api/richedit/ns-richedit-nmhdr)

**Reference**