# GetMouseMovePointsEx function

## Description

Retrieves a history of up to 64 previous coordinates of the mouse or pen.

## Parameters

### `cbSize` [in]

Type: **UINT**

The size, in bytes, of the [MOUSEMOVEPOINT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousemovepoint) structure.

### `lppt` [in]

Type: **LPMOUSEMOVEPOINT**

A pointer to a [MOUSEMOVEPOINT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousemovepoint) structure containing valid mouse coordinates (in screen coordinates). It may also contain a time stamp.

The **GetMouseMovePointsEx** function searches for the point in the mouse coordinates history. If the function finds the point, it returns the last
*nBufPoints* prior to and including the supplied point.

If your application supplies a time stamp, the **GetMouseMovePointsEx** function will use it to differentiate between two equal points that were recorded at different times.

An application should call this function using the mouse coordinates received from the [WM_MOUSEMOVE](https://learn.microsoft.com/windows/desktop/inputdev/wm-mousemove) message and convert them to screen coordinates.

### `lpptBuf` [out]

Type: **LPMOUSEMOVEPOINT**

A pointer to a buffer that will receive the points. It should be at least
*cbSize**
*nBufPoints* in size.

### `nBufPoints` [in]

Type: **int**

The number of points to be retrieved.

### `resolution` [in]

Type: **DWORD**

The resolution desired. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **GMMP_USE_DISPLAY_POINTS**<br><br>1 | Retrieves the points using the display resolution. |
| **GMMP_USE_HIGH_RESOLUTION_POINTS**<br><br>2 | Retrieves high resolution points. Points can range from zero to 65,535 (0xFFFF) in both x- and y-coordinates. This is the resolution provided by absolute coordinate pointing devices such as drawing tablets. |

## Return value

Type: **int**

If the function succeeds, the return value is the number of points in the buffer. Otherwise, the function returns
–1. For extended error information, your application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The system retains the last 64 mouse coordinates and their time stamps. If your application supplies a mouse coordinate to **GetMouseMovePointsEx** and the coordinate exists in the system's mouse coordinate history, the function retrieves the specified number of coordinates from the systems' history. You can also supply a time stamp, which will be used to differentiate between identical points in the history.

The **GetMouseMovePointsEx** function will return points that eventually were dispatched not only to the calling thread but also to other threads.

**GetMouseMovePointsEx** may fail or return erroneous values in the following cases:

* If negative coordinates are passed in the [MOUSEMOVEPOINT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousemovepoint) structure.
* If **GetMouseMovePointsEx** retrieves a coordinate with a negative value.

These situations can occur if multiple monitors are present. To correct this, first call
[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) to get the following values:

* SM_XVIRTUALSCREEN,
* SM_YVIRTUALSCREEN,
* SM_CXVIRTUALSCREEN, and
* SM_CYVIRTUALSCREEN.

Then, for each point that is returned from **GetMouseMovePointsEx**, perform the following transform:

```
int nVirtualWidth = GetSystemMetrics(SM_CXVIRTUALSCREEN) ;
int nVirtualHeight = GetSystemMetrics(SM_CYVIRTUALSCREEN) ;
int nVirtualLeft = GetSystemMetrics(SM_XVIRTUALSCREEN) ;
int nVirtualTop = GetSystemMetrics(SM_YVIRTUALSCREEN) ;
int cpt = 0 ;
int mode = GMMP_USE_DISPLAY_POINTS ;

MOUSEMOVEPOINT mp_in ;
MOUSEMOVEPOINT mp_out[64] ;

ZeroMemory(&mp_in, sizeof(mp_in)) ;
mp_in.x = pt.x & 0x0000FFFF ;//Ensure that this number will pass through.
mp_in.y = pt.y & 0x0000FFFF ;
cpt = GetMouseMovePointsEx(&mp_in, &mp_out, 64, mode) ;

for (int i = 0; i < cpt; i++)
{
   switch(mode)
   {
   case GMMP_USE_DISPLAY_POINTS:
      if (mp_out[i].x > 32767)
         mp_out[i].x -= 65536 ;
      if (mp_out[i].y > 32767)
         mp_out[i].y -= 65536 ;
      break ;
   case GMMP_USE_HIGH_RESOLUTION_POINTS:
      mp_out[i].x = ((mp_out[i].x * (nVirtualWidth - 1)) - (nVirtualLeft * 65536)) / nVirtualWidth ;
      mp_out[i].y = ((mp_out[i].y * (nVirtualHeight - 1)) - (nVirtualTop * 65536)) / nVirtualHeight ;
      break ;
   }
}
```

## See also

**Conceptual**

[MOUSEMOVEPOINT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-mousemovepoint)

[Mouse Input](https://learn.microsoft.com/windows/desktop/inputdev/mouse-input)

**Reference**