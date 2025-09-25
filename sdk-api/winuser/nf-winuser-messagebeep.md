# MessageBeep function

## Description

Plays a waveform sound. The waveform sound for each sound type is identified by an entry in the
registry.

**Note** On Windows Server 2022, the Microsoft\Windows\Multimedia\SystemSoundsService task in Task Scheduler is disabled. This task will need to be enabled for MessageBeep to function.

## Parameters

### `uType` [in]

The sound to be played. The sounds are set by the user through the Sound control panel application, and then
stored in the registry.

This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| 0xFFFFFFFF | A simple beep. If the sound card is not available, the sound is generated using the speaker. |
| **MB_ICONASTERISK**<br><br>0x00000040L | See **MB_ICONINFORMATION**. |
| **MB_ICONEXCLAMATION**<br><br>0x00000030L | See **MB_ICONWARNING**. |
| **MB_ICONERROR**<br><br>0x00000010L | The sound specified as the Windows Critical Stop sound. |
| **MB_ICONHAND**<br><br>0x00000010L | See **MB_ICONERROR**. |
| **MB_ICONINFORMATION**<br><br>0x00000040L | The sound specified as the Windows Asterisk sound. |
| **MB_ICONQUESTION**<br><br>0x00000020L | The sound specified as the Windows Question sound. |
| **MB_ICONSTOP**<br><br>0x00000010L | See **MB_ICONERROR**. |
| **MB_ICONWARNING**<br><br>0x00000030L | The sound specified as the Windows Exclamation sound. |
| **MB_OK**<br><br>0x00000000L | The sound specified as the Windows Default Beep sound. |

## Return value

If the function succeeds, the return value is nonzero.

If the function fails, the return value is zero. To get extended error information, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

After queuing the sound, the **MessageBeep** function
returns control to the calling function and plays the sound asynchronously.

If it cannot play the specified alert sound,
**MessageBeep** attempts to play the system default sound. If
it cannot play the system default sound, the function produces a standard beep sound using the
[Beep](https://learn.microsoft.com/windows/desktop/api/utilapiset/nf-utilapiset-beep)
function. Starting in Windows 7, this plays a simple tone on the default sound device.
See the documentation for the **Beep** function for further details.

The user can disable the warning beep by using the Sound control panel application.

**Note** To send a beep to a remote client, use the [Beep](https://learn.microsoft.com/windows/desktop/api/utilapiset/nf-utilapiset-beep) function.
The **Beep** function is redirected to the client, whereas
**MessageBeep** is not.

## See also

[Beep](https://learn.microsoft.com/windows/desktop/api/utilapiset/nf-utilapiset-beep)

[Error Handling Functions](https://learn.microsoft.com/windows/desktop/Debug/error-handling-functions)

[FlashWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-flashwindow)

[Notifying the User](https://learn.microsoft.com/windows/desktop/Debug/notifying-the-user)