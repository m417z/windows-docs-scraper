## Description

Constructor for the [**GdiplusStartupInputEx**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinputex) structure.

The constructor sets the **GdiplusVersion** member to 2. All of the constructor parameters are optional, so you can declare a variable of type **GdiplusStartupInputEx** without passing any arguments to the constructor, and all of the members will be initialized with appropriate default values.

## Parameters

### `startupParameters`

Type: **INT**

See [**GdiplusStartupParams**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/ne-gdiplusinit-gdiplusstartupparams). The default value is **GdiplusStartupDefault** (0).

### `debugEventCallback`

Type: **[DebugEventProc](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nc-gdiplusinit-debugeventproc)**

Pointer to your [**DebugEventProc**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nc-gdiplusinit-debugeventproc) callback function, which GDI+ can call on debug builds for assertions and warnings. The default value is **NULL**.

### `suppressBackgroundThread`

Type: **BOOL**

Boolean value that specifies whether to suppress the GDI+ background thread. If you pass **TRUE**, then [**GdiplusStartup**](https://learn.microsoft.com/windows/win32/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) returns (in its *output* parameter) a pointer to a hook function, and a pointer to an unhook function. You must call those functions appropriately to replace the background thread. If you don't want to be responsible for calling the hook and unhook functions, then set this member to **FALSE**. The default value is **FALSE**.

### `suppressExternalCodecs`

Type: **BOOL**

Boolean value that specifies whether you want GDI+ to suppress external image codecs. The default value is **FALSE**.

## Remarks

## See also