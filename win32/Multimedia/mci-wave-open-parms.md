# MCI\_WAVE\_OPEN\_PARMS structure

The **MCI\_WAVE\_OPEN\_PARMS** structure contains information for [**MCI\_OPEN**](https://learn.microsoft.com/windows/win32/multimedia/mci-open) command for waveform-audio devices.

## Members

**dwCallback**

The low-order word specifies a window handle used for the MCI\_NOTIFY flag.

**wDeviceID**

Indentifier returned to application.

**lpstrDeviceType**

Name or constant identifier of the device type. (The name of the device is typically obtained from the registry or SYSTEM.INI file.) This member can be one of the values listed in [MCI Device Types](https://learn.microsoft.com/windows/win32/multimedia/mci-device-types).

**lpstrElementName**

Device element name (usually a path).

**lpstrAlias**

Optional device alias.

**dwBufferSeconds**

Buffer length, in seconds.

## Remarks

When assigning data to the members of this structure, set the corresponding flags in the *fdwCommand* parameter of the [**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85)) function to validate the members.

You can use the [**MCI\_OPEN\_PARMS**](https://learn.microsoft.com/windows/win32/multimedia/mci-open-parms) structure instead of **MCI\_WAVE\_OPEN\_PARMS** if you are not using the extended data members.

## Requirements

| Requirement | Value |
|-------------------------------------|-------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Mciapi.h |

## See also

[**MCI**](https://learn.microsoft.com/windows/win32/multimedia/mci)

[**MCI Structures**](https://learn.microsoft.com/windows/win32/multimedia/mci-structures)

[**MCI\_OPEN**](https://learn.microsoft.com/windows/win32/multimedia/mci-open)

[**mciSendCommand**](https://learn.microsoft.com/previous-versions//dd757160(v=vs.85))

[**MCI\_OPEN\_PARMS**](https://learn.microsoft.com/windows/win32/multimedia/mci-open-parms)

