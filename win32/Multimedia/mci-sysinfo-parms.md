# MCI\_SYSINFO\_PARMS structure

The **MCI\_SYSINFO\_PARMS** structure contains information for the [**MCI\_SYSINFO**](https://learn.microsoft.com/windows/win32/multimedia/mci-sysinfo) command.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**lpstrReturn**

Pointer to a user-supplied buffer for the return string. It is also used to return a **DWORD** value when the MCI\_SYSINFO\_QUANTITY flag is used.

**dwRetSize**

Size, in bytes, of return buffer.

**dwNumber**

Number indicating the device position in the MCI device table or in the list of open devices if the MCI\_SYSINFO\_OPEN flag is set.

**wDeviceType**

Type of device. This member can be one of the values listed in [MCI Device Types](https://learn.microsoft.com/windows/win32/multimedia/mci-device-types).

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_SYSINFO**](https://learn.microsoft.com/windows/win32/multimedia/mci-sysinfo)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

