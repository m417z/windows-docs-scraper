# WTSStartRemoteControlSessionA function

## Description

Starts the remote control of another Remote Desktop Services session. You must call this function from a remote session.

## Parameters

### `pTargetServerName` [in]

A pointer to the name of the server where the session that you want remote control of exists.

### `TargetLogonId` [in]

The logon ID of the session that you want remote control of.

### `HotkeyVk` [in]

The virtual-key code that represents the key to press to stop remote control of the session. The key that is defined in this parameter is used with the *HotkeyModifiers* parameter.

### `HotkeyModifiers` [in]

The virtual modifier that represents the key to press to stop remote control of the session. The virtual modifier is used with the *HotkeyVk* parameter.

For example, if the **WTSStartRemoteControlSession** function is called with *HotkeyVk* set to **VK_MULTIPLY** and *HotkeyModifiers* set to **REMOTECONTROL_KBDCTRL_HOTKEY**, the user who has remote control of the target session can press CTRL + * to stop remote control of the session and return to their own session.

#### REMOTECONTROL_KBDSHIFT_HOTKEY

The SHIFT key

#### REMOTECONTROL_KBDCTRL_HOTKEY

The CTRL key

#### REMOTECONTROL_KBDALT_HOTKEY

The ALT key

## Return value

If the function succeeds, the return value is a nonzero value.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!NOTE]
> The wtsapi32.h header defines WTSStartRemoteControlSession as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).