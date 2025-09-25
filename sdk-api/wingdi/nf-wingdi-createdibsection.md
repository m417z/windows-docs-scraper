# CreateDIBSection function

## Description

The **CreateDIBSection** function creates a DIB that applications can write to directly. The function gives you a pointer to the location of the bitmap bit values. You can supply a handle to a file-mapping object that the function will use to create the bitmap, or you can let the system allocate the memory for the bitmap.

## Parameters

### `hdc` [in]

A handle to a device context. If the value of *iUsage* is DIB_PAL_COLORS, the function uses this device context's logical palette to initialize the DIB colors.

### `pbmi` [in]

A pointer to a [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure that specifies various attributes of the DIB, including the bitmap dimensions and colors.

### `usage` [in]

The type of data contained in the **bmiColors** array member of the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure pointed to by *pbmi* (either logical palette indexes or literal RGB values). The following values are defined.

| Value | Meaning |
| --- | --- |
| **DIB_PAL_COLORS** | The **bmiColors** member is an array of 16-bit indexes into the logical palette of the device context specified by *hdc*. |
| **DIB_RGB_COLORS** | The [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure contains an array of literal RGB values. |

### `ppvBits` [out]

A pointer to a variable that receives a pointer to the location of the DIB bit values.

### `hSection` [in]

A handle to a file-mapping object that the function will use to create the DIB. This parameter can be **NULL**.

If *hSection* is not **NULL**, it must be a handle to a file-mapping object created by calling the [CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga) function with the PAGE_READWRITE or PAGE_WRITECOPY flag. Read-only DIB sections are not supported. Handles created by other means will cause **CreateDIBSection** to fail.

If *hSection* is not **NULL**, the **CreateDIBSection** function locates the bitmap bit values at offset *dwOffset* in the file-mapping object referred to by *hSection*. An application can later retrieve the *hSection* handle by calling the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function with the **HBITMAP** returned by **CreateDIBSection**.

If *hSection* is **NULL**, the system allocates memory for the DIB. In this case, the **CreateDIBSection** function ignores the *dwOffset* parameter. An application cannot later obtain a handle to this memory. The **dshSection** member of the [DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection) structure filled in by calling the [GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject) function will be **NULL**.

### `offset` [in]

The offset from the beginning of the file-mapping object referenced by *hSection* where storage for the bitmap bit values is to begin. This value is ignored if *hSection* is **NULL**. The bitmap bit values are aligned on doubleword boundaries, so *dwOffset* must be a multiple of the size of a **DWORD**.

## Return value

If the function succeeds, the return value is a handle to the newly created DIB, and **ppvBits* points to the bitmap bit values.

If the function fails, the return value is **NULL**, and **ppvBits* is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) can return the following value:

| Error code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the input parameters is invalid. |

## Remarks

As noted above, if *hSection* is **NULL**, the system allocates memory for the DIB. The system closes the handle to that memory when you later delete the DIB by calling the [DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject) function. If *hSection* is not **NULL**, you must close the *hSection* memory handle yourself after calling **DeleteObject** to delete the bitmap.

You cannot paste a DIB section from one application into another application.

**CreateDIBSection** does not use the [BITMAPINFOHEADER](https://learn.microsoft.com/windows/win32/api/wingdi/ns-wingdi-bitmapinfoheader) parameters *biXPelsPerMeter* or *biYPelsPerMeter* and will not provide resolution information in the [BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo) structure.

You need to guarantee that the GDI subsystem has completed any drawing to a bitmap created by **CreateDIBSection** before you draw to the bitmap yourself. Access to the bitmap must be synchronized. Do this by calling the [GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush) function. This applies to any use of the pointer to the bitmap bit values, including passing the pointer in calls to functions such as [SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits).

**ICM:** No color management is done.

## See also

[BITMAPINFO](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-bitmapinfo)

[Bitmap Functions](https://learn.microsoft.com/windows/desktop/gdi/bitmap-functions)

[Bitmaps Overview](https://learn.microsoft.com/windows/desktop/gdi/bitmaps)

[CreateFileMapping](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-createfilemappinga)

[DIBSECTION](https://learn.microsoft.com/windows/desktop/api/wingdi/ns-wingdi-dibsection)

[DeleteObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-deleteobject)

[GdiFlush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-gdiflush)

[GetDIBColorTable](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdibcolortable)

[GetObject](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getobject)

[SetDIBColorTable](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibcolortable)

[SetDIBits](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-setdibits)