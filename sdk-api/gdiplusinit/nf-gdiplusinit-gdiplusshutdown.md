## Description

The **GdiplusShutdown** function cleans up resources used by Windows GDI+. Each call to [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) should be paired with a call to **GdiplusShutdown**.

## Parameters

### `token`

Type: [in] **ULONG_PTR**

Token returned by a previous call to [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup).

## Remarks

You must call [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) before you create any GDI+ objects, and you must delete all of your GDI+ objects (or have them go out of scope) before you call **GdiplusShutdown**.

**Note** For Windows 7 and earlier, if GDI+ can't create a font family, it substitutes the generic Sans Serif family and client-side caches the pointer for the generic family. Because calls to [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) and **GdiplusShutdown** are not aware of this caching, the operating system retains the pointer for the generic family object past the object's lifetime, which causes the operating system to crash. For Windows 8 and later, GDI+ returns a sentinel value for the generic family object that remains constant across calls to **GdiplusStartup** and **GdiplusShutdown** so the operating system doesn't retain the pointer for the generic family object past the object's lifetime.

#### Examples

For an example of calling [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup) and **GdiplusShutdown**, see [GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup).

## See also

[GdiplusStartup](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusstartup)

[GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput)

[GdiplusStartupOutput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput)

[Getting Started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use)