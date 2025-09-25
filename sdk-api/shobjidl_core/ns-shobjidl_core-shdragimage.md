# SHDRAGIMAGE structure

## Description

Contains the information needed to create a drag image.

## Members

### `sizeDragImage`

Type: **[SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size)**

A [SIZE](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-size) structure with the length and width of the drag image.

### `ptOffset`

Type: **[POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point)**

A [POINT](https://learn.microsoft.com/windows/win32/api/windef/ns-windef-point) structure that specifies the location of the cursor within the drag image. The structure should contain the offset from the upper-left corner of the drag image to the location of the cursor.

### `hbmpDragImage`

Type: **HBITMAP**

The drag image's bitmap handle.

### `crColorKey`

Type: **[COLORREF](https://learn.microsoft.com/windows/desktop/gdi/colorref)**

The color used by the control to fill the background of the drag image.

## Remarks

In Windows Vista this structure is defined in Shobjidl.idl. Prior to that, it was defined in Shlobj.h.

Use the following procedure to create the drag image.

1. Create a bitmap of the size specified by **sizeDragImage** with a handle to a device context (HDC) that is compatible with the screen.
2. Draw the bitmap.
3. Select the bitmap out of the HDC it was created with.
4. Destroy the HDC.
5. Assign the bitmap handle to **hbmpDragImage**.

**Note** Turn off antialiasing when drawing text. Otherwise, artifacts could occur at the edges, between the text color and the color key.

## See also

[IDragSourceHelper::InitializeFromBitmap](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idragsourcehelper-initializefrombitmap)

[IDragSourceHelper::InitializeFromWindow](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-idragsourcehelper-initializefromwindow)