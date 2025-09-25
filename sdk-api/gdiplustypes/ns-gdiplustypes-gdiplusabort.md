## Description

The **GdiplusAbort** structure provides a mechanism that allows Windows GDI+ to call an application-defined **Abort** method periodically during time-consuming rendering operations.

See [GdiplusAbort::Abort](https://learn.microsoft.com/windows/win32/api/gdiplustypes/nf-gdiplustypes-gdiplusabort-abort).

## Members

## Remarks

The **GdiplusAbort** structure has only one method, a virtual method named **Abort**. The **GdiplusAbort** structure has no data members.

To create a callback method, follow these steps.

1. Create a structure that descends from **GdiplusAbort**, and implement the following method.

   `HRESULT __stdcall Abort(void)`
2. Create data members to hold any data that will be needed by the **Abort** method.
3. Pass the address of the **GdiplusAbort** descendant to the [Image::SetAbort](https://learn.microsoft.com/windows/desktop/api/gdiplusheaders/nf-gdiplusheaders-image-setabort) method.

During certain time-consuming rendering operations (for example, a call to the [Graphics::DrawImage](https://learn.microsoft.com/windows/desktop/api/gdiplusgraphics/nf-gdiplusgraphics-graphics-drawimage(inimage_inconstpointf_inint)) method), GDI+ calls the **Abort** method periodically. For some operations the callback is every 250 milliseconds; for other operations the callback is not based on a timer. If the **Abort** method returns S_OK, GDI+ continues the rendering operation. If the **Abort** method returns E_ABORT, GDI+ aborts the rendering operation.