# ITfLangBarItemBitmapButton::DrawBitmap

## Description

Obtains the bitmap and mask for the bitmap button item.

## Parameters

### `bmWidth` [in]

Contains the width, in pixels, of the bitmap button item.

### `bmHeight` [in]

Contains the height, in pixels, of the bitmap button item.

### `dwFlags` [in]

Not currently used.

### `phbmp` [out]

Pointer to an **HBITMAP** value that receives the handle of the bitmap drawn for the bitmap item.

### `phbmpMask` [out]

Pointer to an **HBITMAP** value that receives the handle of the mask bitmap. This is a monochrome bitmap that functions as a mask for *phbmp*. Each black pixel in this bitmap will cause the corresponding pixel in *phbmp* to be displayed in its normal color. Each white pixel in this bitmap will cause the cooresponding pixel in *phbmp* to be displayed in the inverse of its normal color.

To display the bitmap without color conversion, create a monochrome bitmap the same size as *phbmp* and set each pixel to black (RGB(0, 0, 0)).

## Return value

This method can return one of these values.

| Value | Description |
| --- | --- |
| **S_OK** | The method was successful. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_OUTOFMEMORY** | A memory allocation failure occurred. |