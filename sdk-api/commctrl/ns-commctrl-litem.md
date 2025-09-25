# LITEM structure

## Description

Used to set and retrieve information about a link item.

## Members

### `mask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more of the following flags, describing the information to set or retrieve:

| Value | Meaning |
| --- | --- |
| LIF_ITEMINDEX | Retrieve the numeric item index. Items are always accessed by index, therefore you must always set this flag and assign a value to **iLink**. To obtain the item ID you must set both LIF_ITEMINDEX and LIF_ITEMID. |
| LIF_STATE | Use **stateMask** to get or set the state of the link. |
| LIF_ITEMID | Specify the item by the ID value given in **szID**. |
| LIF_URL | Set or get the URL for this item. |

### `iLink`

Type: **int**

Value of type **int** that contains the item index. This numeric index is used to access a SysLink control link.

### `state`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of one or more of the following flags, describing the state of the item:

| Value | Meaning |
| --- | --- |
| LIS_ENABLED | The link can respond to user input. This is the default unless the entire control was created with [WS_DISABLED](https://learn.microsoft.com/windows/desktop/winmsg/window-styles). In this case, all links are disabled. |
| LIS_FOCUSED | The link has the keyboard focus. Pressing ENTER sends an NM_CLICK notification. |
| LIS_VISITED | The link has been visited by the user. Changing the URL to one that has not been visited causes this flag to be cleared. |
| LIS_HOTTRACK | Indicates that the syslink control will highlight in a different color (COLOR_HIGHLIGHT) when the mouse hovers over the control. |
| LIS_DEFAULTCOLORS | Enable custom text colors to be used. |

### `stateMask`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Combination of flags describing which state item to get or set. Allowable items are identical to those allowed in **state**.

### `szID`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[MAX_LINKID_TEXT]**

**WCHAR** string that contains the ID name. The maximum number of characters in the array is MAX_LINKID_TEXT. The ID name cannot be used to access a SysLink control link. You use the item index to access the item.

### `szUrl`

Type: **[WCHAR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)[L_MAX_URL_LENGTH]**

**WCHAR** string that contains the URL represented by the link. The maximum number of characters in the array is L_MAX_URL_LENGTH.