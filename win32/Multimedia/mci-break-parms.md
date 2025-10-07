# MCI\_BREAK\_PARMS structure

The **MCI\_BREAK\_PARMS** structure contains virtual-key code and window information for the [**MCI\_BREAK**](https://learn.microsoft.com/windows/win32/multimedia/mci-break) command.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**nVirtKey**

Virtual-key code for break key.

**hwndBreak**

Handle to the window that must be the current window for break detection.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members. The following flags are defined:

MCI\_BREAK\_HWND

Validates the **hwndBreak** member specifying the window that must have focus to enable break detection.

MCI\_BREAK\_KEY

Validates the **nVirtKey** member specifying the virtual-key code to be used for the break key.

MCI\_BREAK\_OFF

Disables any existing break key.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_BREAK**](https://learn.microsoft.com/windows/win32/multimedia/mci-break)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

