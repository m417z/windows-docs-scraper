# TOUCH_COORD_TO_PIXEL macro

## Syntax

```cpp
long TOUCH_COORD_TO_PIXEL(
    long l
);
```

## Return value

Type: **long**

The coordinate value in pixels.

## Description

Converts touch coordinates to pixels.

## Parameters

### `l`

The value to be converted from touch coordinates to pixels.

## Remarks

The **TOUCH_COORD_TO_PIXEL** macro is used to convert from touch coordinates (currently centipixels) to pixels.
Touch coordinates are finer grained than pixels so that application developers can use subpixel granularity
for specialized applications such as graphic design.

#### Examples

```cpp
case WM_TOUCH:
  cInputs = LOWORD(wParam);
  pInputs = new TOUCHINPUT[cInputs];
  if (pInputs){
    if (GetTouchInputInfo((HTOUCHINPUT)lParam, cInputs, pInputs, sizeof(TOUCHINPUT))){
      for (int i=0; i < static_cast<INT>(cInputs); i++){
        TOUCHINPUT ti = pInputs[i];
        index = GetContactIndex(ti.dwID);
        if (ti.dwID != 0 && index < MAXPOINTS){
          // Do something with your touch input handle
          ptInput.x = TOUCH_COORD_TO_PIXEL(ti.x);
          ptInput.y = TOUCH_COORD_TO_PIXEL(ti.y);
          ScreenToClient(hWnd, &ptInput);

          if (ti.dwFlags & TOUCHEVENTF_UP){
            points[index][0] = -1;
            points[index][1] = -1;
          }else{
            points[index][0] = ptInput.x;
            points[index][1] = ptInput.y;
          }
        }
      }
    }
    // If you handled the message and don't want anything else done with it, you can close it
    CloseTouchInputHandle((HTOUCHINPUT)lParam);
    delete [] pInputs;
  }else{
    // Handle the error here
  }

```

## See also

[Macros](https://learn.microsoft.com/windows/desktop/wintouch/touch-macros)