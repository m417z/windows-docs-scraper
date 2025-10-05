# GRAYSTRINGPROC callback function

## Description

An application-defined callback function used with the [GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa) function. It is used to draw a string. The **GRAYSTRINGPROC** type defines a pointer to this callback function. _GrayStringProc_ (or _OutputProc_) is a placeholder for the application-defined or library-defined function name.

## Parameters

### `unnamedParam1`

Type: **HDC**

A handle to a device context with a bitmap of at least the width and height specified by the _nWidth_ and _nHeight_ parameters passed to [GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa). This parameter is typically named _hDc_.

### `unnamedParam2`

Type: **LPARAM**

A pointer to the string to be drawn. This parameter is typically named _lpData_.

### `unnamedParam3`

Type: **int**

The length, in characters, of the string. This parameter is typically named _nCount_.

## Return value

Type: **BOOL**

If it succeeds, the callback function should return **TRUE**.

If the function fails, the return value is **FALSE**.

## Remarks

> [!NOTE]
> The parameters are defined in the header with no names: `typedef BOOL (CALLBACK* GRAYSTRINGPROC)(HDC, LPARAM, int);`. Therefore, the syntax block lists them as `unnamedParam1` - `unnamedParam3`. You can name these parameters anything in your app. However, they are usually named as shown in the parameter descriptions.

The callback function must draw an image relative to the coordinates (0,0).

## See also

[GrayString](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-graystringa)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)