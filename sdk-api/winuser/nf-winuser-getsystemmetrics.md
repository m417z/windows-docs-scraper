# GetSystemMetrics function

## Description

Retrieves the specified
system metric or system configuration setting.

Note that all dimensions
retrieved by **GetSystemMetrics** are in pixels.

## Parameters

### `nIndex` [in]

Type: **int**

The system metric or configuration setting to be retrieved. This parameter can be one of the following values.
Note that all SM_CX* values are widths and all SM_CY* values are heights. Also note that all settings
designed to return Boolean data represent **TRUE** as any nonzero value, and **FALSE** as a zero value.

| Value | Meaning |
| --- | --- |
| **SM_ARRANGE**<br><br>56 | The flags that specify how the system arranged minimized windows. For more information, see the Remarks section in this topic. |
| **SM_CLEANBOOT**<br><br>67 | The value that specifies how the system is started:<br><br>* 0 Normal boot<br>* 1 Fail-safe boot<br>* 2 Fail-safe with network boot<br><br>A fail-safe boot (also called SafeBoot, Safe Mode, or Clean Boot) bypasses the user startup files. |
| **SM_CMONITORS**<br><br>80 | The number of display monitors on a desktop. For more information, see the Remarks section in this topic. |
| **SM_CMOUSEBUTTONS**<br><br>43 | The number of buttons on a mouse, or zero if no mouse is installed. |
| **SM_CONVERTIBLESLATEMODE**<br><br>0x2003 | Reflects the state of the laptop or slate mode, 0 for Slate Mode and non-zero otherwise. When this system metric changes, the system sends a broadcast message via [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) with "ConvertibleSlateMode" in the LPARAM. Note that this system metric doesn't apply to desktop PCs. In that case, use [GetAutoRotationState](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getautorotationstate). |
| **SM_CXBORDER**<br><br>5 | The width of a window border, in pixels. This is equivalent to the SM_CXEDGE value for windows with the 3-D look. |
| **SM_CXCURSOR**<br><br>13 | The nominal width of a cursor, in pixels. |
| **SM_CXDLGFRAME**<br><br>7 | This value is the same as SM_CXFIXEDFRAME. |
| **SM_CXDOUBLECLK**<br><br>36 | The width of the rectangle around the location of a first click in a double-click sequence, in pixels. The second click must occur within the rectangle that is defined by SM_CXDOUBLECLK and SM_CYDOUBLECLK for the system to consider the two clicks a double-click. The two clicks must also occur within a specified time.<br><br>To set the width of the double-click rectangle, call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) with SPI_SETDOUBLECLKWIDTH. |
| **SM_CXDRAG**<br><br>68 | The number of pixels on either side of a mouse-down point that the mouse pointer can move before a drag operation begins. This allows the user to click and release the mouse button easily without unintentionally starting a drag operation. If this value is negative, it is subtracted from the left of the mouse-down point and added to the right of it. |
| **SM_CXEDGE**<br><br>45 | The width of a 3-D border, in pixels. This metric is the 3-D counterpart of SM_CXBORDER. |
| **SM_CXFIXEDFRAME**<br><br>7 | The thickness of the frame around the perimeter of a window that has a caption but is not sizable, in pixels. SM_CXFIXEDFRAME is the height of the horizontal border, and SM_CYFIXEDFRAME is the width of the vertical border.<br><br>This value is the same as SM_CXDLGFRAME. |
| **SM_CXFOCUSBORDER**<br><br>83 | The width of the left and right edges of the focus rectangle that the [DrawFocusRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawfocusrect) draws. This value is in pixels.<br><br>**Windows 2000:** This value is not supported. |
| **SM_CXFRAME**<br><br>32 | This value is the same as SM_CXSIZEFRAME. |
| **SM_CXFULLSCREEN**<br><br>16 | The width of the client area for a full-screen window on the primary display monitor, in pixels. To get the coordinates of the portion of the screen that is not obscured by the system taskbar or by application desktop toolbars, call the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the SPI_GETWORKAREA value. |
| **SM_CXHSCROLL**<br><br>21 | The width of the arrow bitmap on a horizontal scroll bar, in pixels. |
| **SM_CXHTHUMB**<br><br>10 | The width of the thumb box in a horizontal scroll bar, in pixels. |
| **SM_CXICON**<br><br>11 | The system large width of an icon, in pixels. The [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function can load only icons with the dimensions that SM_CXICON and SM_CYICON specifies. See [Icon Sizes](https://learn.microsoft.com/windows/win32/menurc/about-icons#icon-sizes) for more info. |
| **SM_CXICONSPACING**<br><br>38 | The width of a grid cell for items in large icon view, in pixels. Each item fits into a rectangle of size SM_CXICONSPACING by SM_CYICONSPACING when arranged. This value is always greater than or equal to SM_CXICON. |
| **SM_CXMAXIMIZED**<br><br>61 | The default width, in pixels, of a maximized top-level window on the primary display monitor. |
| **SM_CXMAXTRACK**<br><br>59 | The default maximum width of a window that has a caption and sizing borders, in pixels. This metric refers to the entire desktop. The user cannot drag the window frame to a size larger than these dimensions. A window can override this value by processing the [WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo) message. |
| **SM_CXMENUCHECK**<br><br>71 | The width of the default menu check-mark bitmap, in pixels. |
| **SM_CXMENUSIZE**<br><br>54 | The width of menu bar buttons, such as the child window close button that is used in the multiple document interface, in pixels. |
| **SM_CXMIN**<br><br>28 | The minimum width of a window, in pixels. |
| **SM_CXMINIMIZED**<br><br>57 | The width of a minimized window, in pixels. |
| **SM_CXMINSPACING**<br><br>47 | The width of a grid cell for a minimized window, in pixels. Each minimized window fits into a rectangle this size when arranged. This value is always greater than or equal to SM_CXMINIMIZED. |
| **SM_CXMINTRACK**<br><br>34 | The minimum tracking width of a window, in pixels. The user cannot drag the window frame to a size smaller than these dimensions. A window can override this value by processing the [WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo) message. |
| **SM_CXPADDEDBORDER**<br><br>92 | The amount of border padding for captioned windows, in pixels.<br><br>**Windows XP/2000:** This value is not supported. |
| **SM_CXSCREEN**<br><br>0 | The width of the screen of the primary display monitor, in pixels. This is the same value obtained by calling [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) as follows: `GetDeviceCaps( hdcPrimaryMonitor, HORZRES)`. |
| **SM_CXSIZE**<br><br>30 | The width of a button in a window caption or title bar, in pixels. |
| **SM_CXSIZEFRAME**<br><br>32 | The thickness of the sizing border around the perimeter of a window that can be resized, in pixels. SM_CXSIZEFRAME is the width of the horizontal border, and SM_CYSIZEFRAME is the height of the vertical border.<br><br>This value is the same as SM_CXFRAME. |
| **SM_CXSMICON**<br><br>49 | The system small width of an icon, in pixels. Small icons typically appear in window captions and in small icon view. See [Icon Sizes](https://learn.microsoft.com/windows/win32/menurc/about-icons#icon-sizes) for more info. |
| **SM_CXSMSIZE**<br><br>52 | The width of small caption buttons, in pixels. |
| **SM_CXVIRTUALSCREEN**<br><br>78 | The width of the [virtual screen](https://learn.microsoft.com/windows/win32/gdi/the-virtual-screen), in pixels. The virtual screen is the bounding rectangle of all display monitors. The SM_XVIRTUALSCREEN metric is the coordinates for the left side of the virtual screen. |
| **SM_CXVSCROLL**<br><br>2 | The width of a vertical scroll bar, in pixels. |
| **SM_CYBORDER**<br><br>6 | The height of a window border, in pixels. This is equivalent to the SM_CYEDGE value for windows with the 3-D look. |
| **SM_CYCAPTION**<br><br>4 | The height of a caption area, in pixels. |
| **SM_CYCURSOR**<br><br>14 | The nominal height of a cursor, in pixels. |
| **SM_CYDLGFRAME**<br><br>8 | This value is the same as SM_CYFIXEDFRAME. |
| **SM_CYDOUBLECLK**<br><br>37 | The height of the rectangle around the location of a first click in a double-click sequence, in pixels. The second click must occur within the rectangle defined by SM_CXDOUBLECLK and SM_CYDOUBLECLK for the system to consider the two clicks a double-click. The two clicks must also occur within a specified time.<br><br>To set the height of the double-click rectangle, call [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) with SPI_SETDOUBLECLKHEIGHT. |
| **SM_CYDRAG**<br><br>69 | The number of pixels above and below a mouse-down point that the mouse pointer can move before a drag operation begins. This allows the user to click and release the mouse button easily without unintentionally starting a drag operation. If this value is negative, it is subtracted from above the mouse-down point and added below it. |
| **SM_CYEDGE**<br><br>46 | The height of a 3-D border, in pixels. This is the 3-D counterpart of SM_CYBORDER. |
| **SM_CYFIXEDFRAME**<br><br>8 | The thickness of the frame around the perimeter of a window that has a caption but is not sizable, in pixels. SM_CXFIXEDFRAME is the height of the horizontal border, and SM_CYFIXEDFRAME is the width of the vertical border.<br><br>This value is the same as SM_CYDLGFRAME. |
| **SM_CYFOCUSBORDER**<br><br>84 | The height of the top and bottom edges of the focus rectangle drawn by [DrawFocusRect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-drawfocusrect). This value is in pixels.<br><br>**Windows 2000:** This value is not supported. |
| **SM_CYFRAME**<br><br>33 | This value is the same as SM_CYSIZEFRAME. |
| **SM_CYFULLSCREEN**<br><br>17 | The height of the client area for a full-screen window on the primary display monitor, in pixels. To get the coordinates of the portion of the screen not obscured by the system taskbar or by application desktop toolbars, call the [SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function with the SPI_GETWORKAREA value. |
| **SM_CYHSCROLL**<br><br>3 | The height of a horizontal scroll bar, in pixels. |
| **SM_CYICON**<br><br>12 | The system large height of an icon, in pixels. The [LoadIcon](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-loadicona) function can load only icons with the dimensions that SM_CXICON and SM_CYICON specifies. See [Icon Sizes](https://learn.microsoft.com/windows/win32/menurc/about-icons#icon-sizes) for more info. |
| **SM_CYICONSPACING**<br><br>39 | The height of a grid cell for items in large icon view, in pixels. Each item fits into a rectangle of size SM_CXICONSPACING by SM_CYICONSPACING when arranged. This value is always greater than or equal to SM_CYICON. |
| **SM_CYKANJIWINDOW**<br><br>18 | For double byte character set versions of the system, this is the height of the Kanji window at the bottom of the screen, in pixels. |
| **SM_CYMAXIMIZED**<br><br>62 | The default height, in pixels, of a maximized top-level window on the primary display monitor. |
| **SM_CYMAXTRACK**<br><br>60 | The default maximum height of a window that has a caption and sizing borders, in pixels. This metric refers to the entire desktop. The user cannot drag the window frame to a size larger than these dimensions. A window can override this value by processing the [WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo) message. |
| **SM_CYMENU**<br><br>15 | The height of a single-line menu bar, in pixels. |
| **SM_CYMENUCHECK**<br><br>72 | The height of the default menu check-mark bitmap, in pixels. |
| **SM_CYMENUSIZE**<br><br>55 | The height of menu bar buttons, such as the child window close button that is used in the multiple document interface, in pixels. |
| **SM_CYMIN**<br><br>29 | The minimum height of a window, in pixels. |
| **SM_CYMINIMIZED**<br><br>58 | The height of a minimized window, in pixels. |
| **SM_CYMINSPACING**<br><br>48 | The height of a grid cell for a minimized window, in pixels. Each minimized window fits into a rectangle this size when arranged. This value is always greater than or equal to SM_CYMINIMIZED. |
| **SM_CYMINTRACK**<br><br>35 | The minimum tracking height of a window, in pixels. The user cannot drag the window frame to a size smaller than these dimensions. A window can override this value by processing the [WM_GETMINMAXINFO](https://learn.microsoft.com/windows/desktop/winmsg/wm-getminmaxinfo) message. |
| **SM_CYSCREEN**<br><br>1 | The height of the screen of the primary display monitor, in pixels. This is the same value obtained by calling [GetDeviceCaps](https://learn.microsoft.com/windows/desktop/api/wingdi/nf-wingdi-getdevicecaps) as follows: `GetDeviceCaps( hdcPrimaryMonitor, VERTRES)`. |
| **SM_CYSIZE**<br><br>31 | The height of a button in a window caption or title bar, in pixels. |
| **SM_CYSIZEFRAME**<br><br>33 | The thickness of the sizing border around the perimeter of a window that can be resized, in pixels. SM_CXSIZEFRAME is the width of the horizontal border, and SM_CYSIZEFRAME is the height of the vertical border.<br><br>This value is the same as SM_CYFRAME. |
| **SM_CYSMCAPTION**<br><br>51 | The height of a small caption, in pixels. |
| **SM_CYSMICON**<br><br>50 | The system small height of an icon, in pixels. Small icons typically appear in window captions and in small icon view. See [Icon Sizes](https://learn.microsoft.com/windows/win32/menurc/about-icons#icon-sizes) for more info. |
| **SM_CYSMSIZE**<br><br>53 | The height of small caption buttons, in pixels. |
| **SM_CYVIRTUALSCREEN**<br><br>79 | The height of the [virtual screen](https://learn.microsoft.com/windows/win32/gdi/the-virtual-screen), in pixels. The virtual screen is the bounding rectangle of all display monitors. The SM_YVIRTUALSCREEN metric is the coordinates for the top of the virtual screen. |
| **SM_CYVSCROLL**<br><br>20 | The height of the arrow bitmap on a vertical scroll bar, in pixels. |
| **SM_CYVTHUMB**<br><br>9 | The height of the thumb box in a vertical scroll bar, in pixels. |
| **SM_DBCSENABLED**<br><br>42 | Nonzero if User32.dll supports DBCS; otherwise, 0. |
| **SM_DEBUG**<br><br>22 | Nonzero if the debug version of User.exe is installed; otherwise, 0. |
| **SM_DIGITIZER**<br><br>94 | Nonzero if the current operating system is Windows 7 or Windows Server 2008 R2 and the Tablet PC Input service is started; otherwise, 0. The return value is a bitmask that specifies the type of digitizer input supported by the device. For more information, see Remarks.<br><br>**Windows Server 2008, Windows Vista and Windows XP/2000:** This value is not supported. |
| **SM_IMMENABLED**<br><br>82 | Nonzero if Input Method Manager/Input Method Editor features are enabled; otherwise, 0.<br><br>SM_IMMENABLED indicates whether the system is ready to use a Unicode-based IME on a Unicode application. To ensure that a language-dependent IME works, check SM_DBCSENABLED and the system ANSI code page. Otherwise the ANSI-to-Unicode conversion may not be performed correctly, or some components like fonts or registry settings may not be present. |
| **SM_MAXIMUMTOUCHES**<br><br>95 | Nonzero if there are digitizers in the system; otherwise, 0. <br><br>SM_MAXIMUMTOUCHES returns the aggregate maximum of the maximum number of contacts supported by every digitizer in the system. If the system has only single-touch digitizers, the return value is 1. If the system has multi-touch digitizers, the return value is the number of simultaneous contacts the hardware can provide.<br><br>**Windows Server 2008, Windows Vista and Windows XP/2000:** This value is not supported. |
| **SM_MEDIACENTER**<br><br>87 | Nonzero if the current operating system is the Windows XP, Media Center Edition, 0 if not. |
| **SM_MENUDROPALIGNMENT**<br><br>40 | Nonzero if drop-down menus are right-aligned with the corresponding menu-bar item; 0 if the menus are left-aligned. |
| **SM_MIDEASTENABLED**<br><br>74 | Nonzero if the system is enabled for Hebrew and Arabic languages, 0 if not. |
| **SM_MOUSEPRESENT**<br><br>19 | Nonzero if a mouse is installed; otherwise, 0. This value is rarely zero, because of support for virtual mice and because some systems detect the presence of the port instead of the presence of a mouse. |
| **SM_MOUSEHORIZONTALWHEELPRESENT**<br><br>91 | Nonzero if a mouse with a horizontal scroll wheel is installed; otherwise 0. |
| **SM_MOUSEWHEELPRESENT**<br><br>75 | Nonzero if a mouse with a vertical scroll wheel is installed; otherwise 0. |
| **SM_NETWORK**<br><br>63 | The least significant bit is set if a network is present; otherwise, it is cleared. The other bits are reserved for future use. |
| **SM_PENWINDOWS**<br><br>41 | Nonzero if the Microsoft Windows for Pen computing extensions are installed; zero otherwise. |
| **SM_REMOTECONTROL**<br><br>0x2001 | This system metric is used in a Terminal Services environment to determine if the current Terminal Server session is being remotely controlled. Its value is nonzero if the current session is remotely controlled; otherwise, 0.<br><br>You can use terminal services management tools such as Terminal Services Manager (tsadmin.msc) and shadow.exe to control a remote session. When a session is being remotely controlled, another user can view the contents of that session and potentially interact with it. |
| **SM_REMOTESESSION**<br><br>0x1000 | This system metric is used in a Terminal Services environment. If the calling process is associated with a Terminal Services client session, the return value is nonzero. If the calling process is associated with the Terminal Services console session, the return value is 0. **Windows Server 2003 and Windows XP:** The console session is not necessarily the physical console. For more information, see [WTSGetActiveConsoleSessionId](https://learn.microsoft.com/windows/desktop/api/winbase/nf-winbase-wtsgetactiveconsolesessionid). |
| **SM_SAMEDISPLAYFORMAT**<br><br>81 | Nonzero if all the display monitors have the same color format, otherwise, 0. Two displays can have the same bit depth, but different color formats. For example, the red, green, and blue pixels can be encoded with different numbers of bits, or those bits can be located in different places in a pixel color value. |
| **SM_SECURE**<br><br>44 | This system metric should be ignored; it always returns 0. |
| **SM_SERVERR2**<br><br>89 | The build number if the system is Windows Server 2003 R2; otherwise, 0. |
| **SM_SHOWSOUNDS**<br><br>70 | Nonzero if the user requires an application to present information visually in situations where it would otherwise present the information only in audible form; otherwise, 0. |
| **SM_SHUTTINGDOWN**<br><br>0x2000 | Nonzero if the current session is shutting down; otherwise, 0.<br><br>**Windows 2000:** This value is not supported. |
| **SM_SLOWMACHINE**<br><br>73 | Nonzero if the computer has a low-end (slow) processor; otherwise, 0. |
| **SM_STARTER**<br><br>88 | Nonzero if the current operating system is Windows 7 Starter Edition, Windows Vista Starter, or Windows XP Starter Edition; otherwise, 0. |
| **SM_SWAPBUTTON**<br><br>23 | Nonzero if the meanings of the left and right mouse buttons are swapped; otherwise, 0. |
| **SM_SYSTEMDOCKED**<br><br>0x2004 | Reflects the state of the docking mode, 0 for Undocked Mode and non-zero otherwise. When this system metric changes, the system sends a broadcast message via [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) with "SystemDockMode" in the LPARAM. |
| **SM_TABLETPC**<br><br>86 | Nonzero if the current operating system is the Windows XP Tablet PC edition or if the current operating system is Windows Vista or Windows 7 and the Tablet PC Input service is started; otherwise, 0. The SM_DIGITIZER setting indicates the type of digitizer input supported by a device running Windows 7 or Windows Server 2008 R2. For more information, see Remarks. |
| **SM_XVIRTUALSCREEN**<br><br>76 | The coordinates for the left side of the [virtual screen](https://learn.microsoft.com/windows/win32/gdi/the-virtual-screen). The virtual screen is the bounding rectangle of all display monitors. The SM_CXVIRTUALSCREEN metric is the width of the virtual screen. |
| **SM_YVIRTUALSCREEN**<br><br>77 | The coordinates for the top of the [virtual screen](https://learn.microsoft.com/windows/win32/gdi/the-virtual-screen). The virtual screen is the bounding rectangle of all display monitors. The SM_CYVIRTUALSCREEN metric is the height of the virtual screen. |

## Return value

Type: **int**

If the function succeeds, the return value is the requested system metric or configuration setting.

If the function fails, the return value is 0.
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) does not provide extended error information.

## Remarks

System metrics can vary from display to display.

**GetSystemMetrics**(SM_CMONITORS) counts only
visible display monitors. This is different from
[EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors), which enumerates both visible display
monitors and invisible pseudo-monitors that are associated with mirroring drivers. An invisible pseudo-monitor is associated with a pseudo-device used to mirror application drawing for remoting or other purposes.

The SM_ARRANGE setting specifies how the system arranges minimized windows, and consists of a starting
position and a direction. The starting position can be one of the following values.

| Value | Meaning |
| --- | --- |
| ARW_BOTTOMLEFT | Start at the lower-left corner of the screen. The default position. |
| ARW_BOTTOMRIGHT | Start at the lower-right corner of the screen. Equivalent to ARW_STARTRIGHT. |
| ARW_TOPLEFT | Start at the upper-left corner of the screen. Equivalent to ARW_STARTTOP. |
| ARW_TOPRIGHT | Start at the upper-right corner of the screen. Equivalent to ARW_STARTTOP | SRW_STARTRIGHT. |

The direction in which to arrange minimized windows can be one of the following values.

| Value | Meaning |
| --- | --- |
| ARW_DOWN | Arrange vertically, top to bottom. |
| ARW_HIDE | Hide minimized windows by moving them off the visible area of the screen. |
| ARW_LEFT | Arrange horizontally, left to right. |
| ARW_RIGHT | Arrange horizontally, right to left. |
| ARW_UP | Arrange vertically, bottom to top. |

The SM_DIGITIZER setting specifies the type of digitizers that are installed on a device running Windows 7 or Windows Server 2008 R2. The return value is a bitmask that specifies one or more of the following values.

| Value | Meaning |
| --- | --- |
| NID_INTEGRATED_TOUCH<br><br>0x01 | The device has an integrated touch digitizer. |
| NID_EXTERNAL_TOUCH<br><br>0x02 | The device has an external touch digitizer. |
| NID_INTEGRATED_PEN<br><br>0x04 | The device has an integrated pen digitizer. |
| NID_EXTERNAL_PEN<br><br>0x08 | The device has an external pen digitizer. |
| NID_MULTI_INPUT<br><br>0x40 | The device supports multiple sources of digitizer input. |
| NID_READY<br><br>0x80 | The device is ready to receive digitizer input. |

This API is not DPI aware, and should not be used if the calling thread is per-monitor DPI aware. For the DPI-aware version of this API, see [GetSystemMetricsForDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetricsfordpi). For more information on DPI awareness, see [the Windows High DPI documentation.](https://learn.microsoft.com/windows/desktop/hidpi/high-dpi-desktop-application-development-on-windows)

#### Examples

The following example uses the
[GetSystemMetrics](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetrics) function to determine whether a mouse is installed and whether the mouse buttons are swapped. The example also uses the
[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa) function to retrieve the mouse threshold and speed. It displays the information in the console.

``` syntax
#include <windows.h>
#include <stdio.h>
#pragma comment(lib, "user32.lib")

void main()
{
   BOOL fResult;
   int aMouseInfo[3];

   fResult = GetSystemMetrics(SM_MOUSEPRESENT);

   if (fResult == 0)
      printf("No mouse installed.\n");
   else
   {
      printf("Mouse installed.\n");

      // Determine whether the buttons are swapped.

      fResult = GetSystemMetrics(SM_SWAPBUTTON);

      if (fResult == 0)
         printf("Buttons not swapped.\n");
      else printf("Buttons swapped.\n");

      // Get the mouse speed and the threshold values.

      fResult = SystemParametersInfo(
         SPI_GETMOUSE,  // get mouse information
         0,             // not used
         &aMouseInfo,   // holds mouse information
         0);            // not used

      if( fResult )
      {
         printf("Speed: %d\n", aMouseInfo[2]);
         printf("Threshold (x,y): %d,%d\n",
            aMouseInfo[0], aMouseInfo[1]);
      }
   }
}
```

## See also

[EnumDisplayMonitors](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-enumdisplaymonitors)

[GetSystemMetricsForDPI](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getsystemmetricsfordpi)

[SystemParametersInfo](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-systemparametersinfoa)