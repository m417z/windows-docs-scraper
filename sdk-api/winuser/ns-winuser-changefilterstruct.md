# CHANGEFILTERSTRUCT structure

## Description

Contains extended result information obtained by calling
the [ChangeWindowMessageFilterEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilterex) function.

## Members

### `cbSize`

Type: **DWORD**

The size of the structure, in bytes.
Must be set to `sizeof(CHANGEFILTERSTRUCT)`, otherwise the function fails with **ERROR_INVALID_PARAMETER**.

### `ExtStatus`

Type: **DWORD**

If the function succeeds, this field contains one of the following values.

| Value | Meaning |
| --- | --- |
| **MSGFLTINFO_NONE**<br><br>0 | See the Remarks section. Applies to **MSGFLT_ALLOW** and **MSGFLT_DISALLOW**. |
| **MSGFLTINFO_ALLOWED_HIGHER**<br><br>3 | The message is allowed at a scope higher than the window. Applies to **MSGFLT_DISALLOW**. |
| **MSGFLTINFO_ALREADYALLOWED_FORWND**<br><br>1 | The message has already been allowed by this window's message filter, and the function thus succeeded with no change to the window's message filter. Applies to **MSGFLT_ALLOW**. |
| **MSGFLTINFO_ALREADYDISALLOWED_FORWND**<br><br>2 | The message has already been blocked by this window's message filter, and the function thus succeeded with no change to the window's message filter. Applies to **MSGFLT_DISALLOW**. |

## Remarks

Certain messages whose value is smaller than **WM_USER** are required to pass through the filter,
regardless of the filter setting. There will be no effect when you attempt to use this function to allow or
block such messages.

An application may use the [ChangeWindowMessageFilter](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilter) function to
allow or block a message in a process-wide manner.
If the message is allowed by either the process message filter
or the window message filter, it will be delivered to the window.

The following table lists the possible values returned in **ExtStatus**.

| Message already allowed at higher scope | Message already allowed by window's message filter | Operation requested | Indicator returned in ExtStatus on success |
| --- | --- | --- | --- |
| No | No | **MSGFLT_ALLOW** | **MSGFLTINFO_NONE** |
| No | No | **MSGFLT_DISALLOW** | **MSGFLTINFO_ALREADYDISALLOWED_FORWND** |
| No | No | **MSGFLT_RESET** | **MSGFLTINFO_NONE** |
| No | Yes | **MSGFLT_ALLOW** | **MSGFLTINFO_ALREADYALLOWED_FORWND** |
| No | Yes | **MSGFLT_DISALLOW** | **MSGFLTINFO_NONE** |
| No | Yes | **MSGFLT_RESET** | **MSGFLTINFO_NONE** |
| Yes | No | **MSGFLT_ALLOW** | **MSGFLTINFO_NONE** |
| Yes | No | **MSGFLT_DISALLOW** | **MSGFLTINFO_ALLOWED_HIGHER** |
| Yes | No | **MSGFLT_RESET** | **MSGFLTINFO_NONE** |
| Yes | Yes | **MSGFLT_ALLOW** | **MSGFLTINFO_ALREADYALLOWED_FORWND** |
| Yes | Yes | **MSGFLT_DISALLOW** | **MSGFLTINFO_ALLOWED_HIGHER** |
| Yes | Yes | **MSGFLT_RESET** | **MSGFLTINFO_NONE** |

## See also

[ChangeWindowMessageFilterEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-changewindowmessagefilterex)