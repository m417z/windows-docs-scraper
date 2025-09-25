# GetClipboardSequenceNumber function

## Description

Retrieves the clipboard sequence number for the current window station.

## Return value

Type: **DWORD**

The return value is the clipboard sequence number. If you do not have **WINSTA_ACCESSCLIPBOARD** access to the window station, the function returns zero.

## Remarks

The system keeps a serial number for the clipboard for each window station. This number is incremented whenever the contents of the clipboard change or the clipboard is emptied. You can track this value to determine whether the clipboard contents have changed and optimize creating DataObjects. If clipboard rendering is delayed, the sequence number is not incremented until the changes are rendered.

## See also

[Clipboard](https://learn.microsoft.com/windows/desktop/dataxchg/clipboard)