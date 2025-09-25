## Description

Indicates if the current OS allows only a limited number of concurrent interactive sessions.

## Return value

True if the current OS limits the number of concurrent interactive sessions; otherwise, false.

## Remarks

Most editions of Windows have a limit on the number of concurrent interactive sessions. Some editions of Windows—like Windows 10 Enterprise multi-session, Windows 11 Enterprise multi-session, and some editions of Windows Server—support an unlimited number of concurrent interactive session. This function returns true if there is a limit in place.

On Windows Server, this functions returns false only when the Remote Desktop Session Host role is installed.

## See also

[Windows Enterprise multi-session FAQ](https://learn.microsoft.com/azure/virtual-desktop/windows-multisession-faq)