## Description

The **SetBkMode** function sets the background mix mode of the specified device context. The background mix mode is used with text, hatched brushes, and pen styles that are not solid lines.

## Parameters

### `hdc` [in]

A handle to the device context.

### `mode` [in]

The background mode. This parameter can be one of the following values.

|Value|Meaning|
|-|-|
|`OPAQUE`|Background is filled with the current background color before the text, hatched brush, or pen is drawn.|
|`TRANSPARENT`|Background is unaffected.|

## Return value

If the function succeeds, the return value specifies the previous background mode.

If the function fails, the return value is zero.

## Remarks

The **SetBkMode** function affects the line styles for lines drawn using a pen created by the [CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen) function. **SetBkMode** does not affect lines drawn using a pen created by the [ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen) function.

## Examples

To see how to make the background of a hatch brush transparent or opaque, refer to the example shown in the [CreateHatchBrush](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createhatchbrush) topic.

The next example draws a string 36 times, rotating it 10 degrees
counterclockwise each time. It also sets the background mode to transparent to make the text visible.

```cpp
#include "strsafe.h"
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int wmId, wmEvent;
    PAINTSTRUCT ps;
    HDC hdc;

    switch (message)
    {

    case WM_PAINT:
        {
        hdc = BeginPaint(hWnd, &ps);
        RECT rc;
        int angle;
        HGDIOBJ hfnt, hfntPrev;
        WCHAR lpszRotate[22] = TEXT("String to be rotated.");
        HRESULT hr;
        size_t pcch = 22;

// Allocate memory for a LOGFONT structure.

PLOGFONT plf = (PLOGFONT) LocalAlloc(LPTR, sizeof(LOGFONT));

// Specify a font typeface name and weight.

hr = StringCchCopy(plf->lfFaceName, 6, TEXT("Arial"));
if (FAILED(hr))
{
// TODO: write error handler
}

plf->lfWeight = FW_NORMAL;

// Retrieve the client-rectangle dimensions.

GetClientRect(hWnd, &rc);

// Set the background mode to transparent for the
// text-output operation.

SetBkMode(hdc, TRANSPARENT);

// Draw the string 36 times, rotating 10 degrees
// counter-clockwise each time.

for (angle = 0; angle < 3600; angle += 100)
{
    plf->lfEscapement = angle;
    hfnt = CreateFontIndirect(plf);
    hfntPrev = SelectObject(hdc, hfnt);

    //
    // The StringCchLength call is fitted to the lpszRotate string
    //
    hr = StringCchLength(lpszRotate, 22, &pcch);
    if (FAILED(hr))
    {
    // TODO: write error handler
    }
    TextOut(hdc, rc.right / 2, rc.bottom / 2,
        lpszRotate, pcch);
    SelectObject(hdc, hfntPrev);
    DeleteObject(hfnt);
}

// Reset the background mode to its default.

SetBkMode(hdc, OPAQUE);

// Free the memory allocated for the LOGFONT structure.

LocalFree((LOCALHANDLE) plf);
        EndPaint(hWnd, &ps);
        break;
        }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
```

## See also

[CreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-createpen)

[ExtCreatePen](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-extcreatepen)

[GetBkMode](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getbkmode)

[Painting and Drawing Functions](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing-functions)

[Painting and Drawing Overview](https://learn.microsoft.com/windows/desktop/gdi/painting-and-drawing)