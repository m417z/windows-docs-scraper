# NMLVEMPTYMARKUP structure

## Description

Contains information used with the [LVN_GETEMPTYMARKUP](https://learn.microsoft.com/windows/desktop/Controls/lvn-getemptymarkup) notification code.

## Members

### `hdr`

Type: **[NMHDR](https://learn.microsoft.com/windows/desktop/api/richedit/ns-richedit-nmhdr)**

Info on the notification message.

### `dwFlags`

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the following values. If **NULL**, markup is rendered left-justified in the listview area.

| Value | Meaning |
| --- | --- |
| **EMF_CENTERED** | Render markup centered in the listview area. |

### `szMarkup`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[L_MAX_URL_LENGTH]**

Markup to display.