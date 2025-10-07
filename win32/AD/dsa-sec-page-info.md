# DSA\_SEC\_PAGE\_INFO structure

The **DSA\_SEC\_PAGE\_INFO** structure is used with the [**WM\_ADSPROP\_SHEET\_CREATE**](https://learn.microsoft.com/windows/win32/ad/wm-adsprop-sheet-create) and [**WM\_DSA\_SHEET\_CREATE\_NOTIFY**](https://learn.microsoft.com/windows/win32/ad/wm-dsa-sheet-create-notify) messages to define a secondary property sheet in an Active Directory MMC snap-in.

> [!Note]
> This structure is not defined in a published header file. To use this structure, define it in the exact format shown.

## Members

**hwndParentSheet**

Contains the window handle of the parent of the secondary property sheet.

**offsetTitle**

Contains the offset, in bytes, from the start of the **DSA\_SEC\_PAGE\_INFO** structure to a NULL-terminated, Unicode string that contains the title of the secondary property sheet.

**dsObjectNames**

Contains a [**DSOBJECTNAMES**](https://learn.microsoft.com/windows/desktop/api/Dsclient/ns-dsclient-dsobjectnames) structure that defines the secondary property sheet. Only one secondary property sheet can be created at a time, so the **DSOBJECTNAMES** structure can only contain one [**DSOBJECT**](https://learn.microsoft.com/windows/desktop/api/Dsclient/ns-dsclient-dsobject) structure.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------|
| Minimum supported client<br> | Windows Vista<br> |
| Minimum supported server<br> | Windows Server 2008<br> |

## See also

[**WM\_ADSPROP\_SHEET\_CREATE**](https://learn.microsoft.com/windows/win32/ad/wm-adsprop-sheet-create)

[**WM\_DSA\_SHEET\_CREATE\_NOTIFY**](https://learn.microsoft.com/windows/win32/ad/wm-dsa-sheet-create-notify)

[**DSOBJECTNAMES**](https://learn.microsoft.com/windows/desktop/api/Dsclient/ns-dsclient-dsobjectnames)

[**DSOBJECT**](https://learn.microsoft.com/windows/desktop/api/Dsclient/ns-dsclient-dsobject)

