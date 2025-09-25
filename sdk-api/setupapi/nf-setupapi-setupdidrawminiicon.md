# SetupDiDrawMiniIcon function

## Description

The **SetupDiDrawMiniIcon** function draws the specified mini-icon at the location requested.

## Parameters

### `hdc` [in]

The handle to the device context in which the mini-icon will be drawn.

### `rc` [in]

The rectangle in the specified device context handle to draw the mini-icon in.

### `MiniIconIndex` [in]

The index of the mini-icon, as retrieved from [SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon) or [SetupDiGetClassBitmapIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassbitmapindex). The following predefined indexes for devices can be used:

| Class | Index |
| --- | --- |
| Computer/System | 0 |
| Display/Monitor | 2 |
| Network Adapter | 3 |
| Mouse | 5 |
| Keyboard | 6 |
| Sound | 8 |
| FDC/HDC | 9 |
| Ports | 10 |
| Printer | 14 |
| Network Transport | 15 |
| Network Client | 16 |
| Network Service | 17 |
| Unknown | 18 |

### `Flags` [in]

These flags control the drawing operation. The LOWORD contains the actual flags defined as follows:

#### DMI_MASK

Draw the mini-icon's mask into HDC.

#### DMI_BKCOLOR

Use the system color index specified in the HIWORD of *Flags* as the background color. If this flag is not set, COLOR_WINDOW is used.

#### DMI_USERECT

If set, **SetupDiDrawMiniIcon** uses the supplied rectangle and stretches the icon to fit.

## Return value

This function returns the offset from the left side of *rc* where the string should start. If the draw operation fails, the function returns zero.

## Remarks

By default, the icon is centered vertically and forced against the left side of the specified rectangle.

**SetupDiDrawMiniIcon** draws the 16-bit version of the icon that is specified by the *MiniIconIndex*  parameter. Instead of **SetupDiDrawMiniIcon**, you should use [SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon) together with **DrawIcon** or **DrawIconEx** to draw the 32-bit version of the icon. The following is an example of how to use **DrawIconEx** to display an icon:

```
HICON hIcon;

if (SetupDiLoadClassIcon(&GUID_DEVCLASS_USB, &hIcon, NULL)) {
    DrawIconEx(hDC, 0, 0, hIcon, GetSystemMetrics(SM_CXSMICON),GetSystemMetrics(SM_CYSMICON), 0, NULL, DI_NORMAL);
DestroyIcon(hIcon);
}
```

For more information about [DrawIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-drawicon) or [DrawIconEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-drawiconex), refer to the Microsoft Windows Software Development Kit (SDK) for Windows 7 and .NET Framework 4.0 documentation.

## See also

[SetupDiGetClassBitmapIndex](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdigetclassbitmapindex)

[SetupDiLoadClassIcon](https://learn.microsoft.com/windows/desktop/api/setupapi/nf-setupapi-setupdiloadclassicon)