## Description

The **GdiplusStartupInput** structure holds a block of arguments that are required by the [GdiplusStartup](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) function.

## Members

### `GdiplusVersion`

Type: **UINT32**

Specifies the version of GDI+. Must be 1.

### `DebugEventCallback`

Type: **[DebugEventProc](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nc-gdiplusinit-debugeventproc)**

Pointer to a callback function that GDI+ can call, on debug builds, for assertions and warnings. The default value is **NULL**.

### `SuppressBackgroundThread`

Type: **BOOL**

Boolean value that specifies whether to suppress the GDI+ background thread. If you set this member to **TRUE**, then [GdiplusStartup](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) returns (in its *output* parameter) a pointer to a hook function, and a pointer to an unhook function. You must call those functions appropriately to replace the background thread. If you don't want to be responsible for calling the hook and unhook functions, then set this member to **FALSE**. The default value is **FALSE**.

### `SuppressExternalCodecs`

Type: **BOOL**

Boolean value that specifies whether you want GDI+ to suppress external image codecs. GDI+ version 1.0 doesn't support external image codecs, so this field is ignored. The default value is **FALSE**.

## Remarks

The **GdiplusStartupInput** structure provides a constructor that sets the **GdiplusVersion** member to 1, and allows you to specify values for the other three members. All of the constructor parameters are optional, so you can declare a variable of type **GdiplusStartupInput** without passing any arguments to the constructor, and all of the members will be initialized with appropriate default values.

If you set the **SuppressBackgroundThread** member to **TRUE** in the *input* parameter of [GdiplusStartup](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup), then you must call the hook and unhook functions returned in the *output* parameter returned by that function. Call those functions before and after the application's main message loop; that is, a message loop that is active for the lifetime of GDI+. Call the hook function before the loop starts, and call the unhook function after the loop ends.

## See also

* [GdiplusShutdown](https://learn.microsoft.com/windows/win32/api/gdiplusinit/(windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown)
* [GdiplusStartup](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup)
* [GdiplusStartupOutput](https://learn.microsoft.com/windows/win32/api/gdiplusinit/(windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput)
* [Getting started](https://learn.microsoft.com/windows/win32/gdiplus/-gdiplus-getting-started-use)