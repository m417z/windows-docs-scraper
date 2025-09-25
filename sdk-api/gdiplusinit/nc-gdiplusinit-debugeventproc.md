## Description

**DebugEventProc** is the signature of a callback function that you implement in your application, and pass to the constructor of [**GdiplusStartupInput**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartupinput-gdiplusstartupinput).

## Parameters

### `level`

A [**DebugEventLevel**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/ne-gdiplusinit-debugeventlevel) object representing the level of the debug event.

### `message`

A pointer to a narrow string containing the debug event message.

## Remarks

## See also