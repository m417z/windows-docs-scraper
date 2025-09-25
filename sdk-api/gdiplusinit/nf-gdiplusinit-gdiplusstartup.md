## Description

The **GdiplusStartup** function initializes Windows GDI+. Call **GdiplusStartup** before making any other GDI+ calls, and call [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) when you have finished using GDI+.

## Parameters

### `token`

Type: [out] **ULONG_PTR token***

Pointer to a **ULONG_PTR** that receives a token. Pass the token to [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) when you have finished using GDI+.

### `input`

Type: [in] **const [GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput)***

Pointer to a [GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput) structure that contains the GDI+ version, a pointer to a debug callback function, a Boolean value that specifies whether to suppress the background thread, and a Boolean value that specifies whether to suppress external image codecs.

### `output`

Type: [out] **[GdiplusStartupOutput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput)***

Pointer to a [GdiplusStartupOutput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput) structure that receives a pointer to a notification hook function and a pointer to a notification unhook function. If the **SuppressBackgroundThread** data member of the *input* parameter is **FALSE**, then this parameter can be **NULL**.

## Return value

Type: **[Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status)**

If the function succeeds, it returns **Ok**, which is an element of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

If the function fails, it returns one of the other elements of the [Status](https://learn.microsoft.com/windows/desktop/api/gdiplustypes/ne-gdiplustypes-status) enumeration.

## Remarks

You must call **GdiplusStartup** before you create any GDI+ objects, and you must delete all of your GDI+ objects (or have them go out of scope) before you call [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown).

You can call **GdiplusStartup** on one thread and call [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) on another thread as long as you delete all of your GDI+ objects (or have them go out of scope) before you call **GdiplusShutdown**.

Do not call **GdiplusStartup** or [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) in [DllMain](https://learn.microsoft.com/windows/desktop/Dlls/dllmain) or in any function that is called by DllMain. If you want to create a DLL that uses GDI+, you should use one of the following techniques to initialize GDI+:

* Require your clients to call **GdiplusStartup** before they call the functions in your DLL and to call [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) when they have finished using your DLL.
* Export your own startup function that calls **GdiplusStartup** and your own shutdown function that calls [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown). Require your clients to call your startup function before they call other functions in your DLL and to call your shutdown function when they have finished using your DLL.
* Call **GdiplusStartup** and [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) in each of your functions that make GDI+ calls.

**Warning** For info about how to use dynamic data exchange (DDE) with GDI+, see [Special CWinApp Services](https://learn.microsoft.com/cpp/mfc/special-cwinapp-services).

## Examples

For an example of calling **GdiplusStartup** and [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) in a Windows application, see [Getting Started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use).

The following console application uses a GDI+[Image](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nl-gdiplusheaders-image) object to retrieve the width and height of a JPEG image. The code calls **GdiplusStartup** before creating the
**Image** object and calls [GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown) before terminating. Note that the
**Image** object is deleted before the call to **GdiplusShutdown**.

In the following code, the variable
*gdiplusStartupInput* is initialized by the default constructor of the [GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput) structure. The default constructor sets the data members of the structure to the following values:

* **GdiplusVersion** = 1
* **DebugEventCallback** = **NULL**
* **SuppressBackgroundThread** = **FALSE**
* **SuppressExternalCodecs** = **FALSE**

```cpp
#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
using namespace Gdiplus;

INT main()
{
   GdiplusStartupInput gdiplusStartupInput;
   ULONG_PTR gdiplusToken;
   GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

   Image* image = new Image(L"FakePhoto.jpg");
   printf("The width of the image is %u.\n", image->GetWidth());
   printf("The height of the image is %u.\n", image->GetHeight());

   delete image;
   GdiplusShutdown(gdiplusToken);
   return 0;
}
```

## See also

[GdiplusShutdown](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/nf-gdiplusinit-gdiplusshutdown)

[GdiplusStartupInput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupinput)

[GdiplusStartupOutput](https://learn.microsoft.com/windows/desktop/api/gdiplusinit/ns-gdiplusinit-gdiplusstartupoutput)

[Getting Started](https://learn.microsoft.com/windows/desktop/gdiplus/-gdiplus-getting-started-use)