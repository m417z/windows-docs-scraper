## Description

The [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) function uses the **GdiplusStartupOutput** structure to return (in its *output* parameter) a pointer to a hook function and a pointer to an unhook function. If you set the **SuppressBackgroundThread** member of the *input* parameter to **TRUE**, then you are responsible for calling those functions to replace the Windows GDI+ background thread.

Call the hook and unhook functions before and after the application's main message loop; that is, a message loop that is active for the lifetime of GDI+. Call the hook function before the loop starts, and call the unhook function after the loop ends. The token parameter of the hook function receives an identifier that you should later pass to the unhook function. If you do not pass the proper identifier (the one returned by the hook function) to the unhook function, there will be resource leaks that won't be cleaned up until the process exits.

If you do not want to be responsible for calling the hook and unhook functions, set the **SuppressBackgroundThread** member of the *input* parameter (passed to [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup)) to **FALSE**.

## Members

### `NotificationHook`

Type: **NotificationHookProc**

Receives a pointer to a hook function.

### `NotificationUnhook`

Type: **NotificationUnhookProc**

Receives a pointer to an unhook function.

## See also

[GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown)

[GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup)

[GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput)

[Getting started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use)