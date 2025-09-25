# DwmSetIconicLivePreviewBitmap function

## Description

Sets a static, iconic bitmap to display a *live preview* (also known as a *Peek preview*) of a window or tab. The taskbar can use this bitmap to show a full-sized preview of a window or tab.

## Parameters

### `hwnd` [in]

A handle to the window. This window must belong to the calling process.

### `hbmp` [in]

A handle to the bitmap to represent the window that *hwnd* specifies.

### `pptClient` [in, optional]

The offset of a tab window's *client region* (the content area inside the client window frame) from the host window's frame. This offset enables the tab window's contents to be drawn correctly in a live preview when it is drawn without its frame.

### `dwSITFlags` [in]

The display options for the live preview. This parameter can be 0 or the following value.

#### DWM_SIT_DISPLAYFRAME (0x00000001)

0x00000001. Displays a frame around the provided bitmap.

## Return value

Returns **S_OK** if the function succeeds, or an error value otherwise. Note that because this bitmap is not cached, if the window is not being previewed when an application calls this function, the function returns a success code but the bitmap is discarded and not used.

## Remarks

A *live preview* (also known as a *Peek preview*) of a window appears when a user moves the mouse pointer over the window's thumbnail in the taskbar or gives the thumbnail focus in the ALT+TAB window. This view is a full-sized view of the window and can be a snapshot or an iconic representation.

A window typically calls the **DwmSetIconicLivePreviewBitmap** function in response to a [WM_DWMSENDICONICLIVEPREVIEWBITMAP](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmsendiconiclivepreviewbitmap) message. The returned bitmap must not be larger than the client area of the window or frame and must have 32-bit color depth.

The Desktop Window Manager (DWM) uses a copy of the bitmap, but the caller retains ownership of the original bitmap and is responsible for freeing the resources that it uses when it is no longer needed. The DWM does not keep its copy of the bitmap when the DWM stops displaying the live preview representation.

#### Examples

 To set a static, iconic bitmap to use as a live preview for the application's window, an application calls the **DwmSetIconicLivePreviewBitmap** function. To set this bitmap, the application must call [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) to set window attributes for non-client rendering to **DWMWA_FORCE_ICONIC_REPRESENTATION** and **DWMWA_HAS_ICONIC_BITMAP**, as shown in the following code.

```cpp
            // Set DWM window attributes to provide the iconic bitmap, and
            // to always render the thumbnail using the iconic bitmap.
            BOOL fForceIconic = TRUE;
            BOOL fHasIconicBitmap = TRUE;

            DwmSetWindowAttribute(
                hwnd,
                DWMWA_FORCE_ICONIC_REPRESENTATION,
                &fForceIconic,
                sizeof(fForceIconic));

            DwmSetWindowAttribute(
                hwnd,
                DWMWA_HAS_ICONIC_BITMAP,
                &fHasIconicBitmap,
                sizeof(fHasIconicBitmap));

```

Then, the application calls **DwmSetIconicLivePreviewBitmap** to respond to the [WM_DWMSENDICONICLIVEPREVIEWBITMAP](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmsendiconiclivepreviewbitmap) message, as shown in the following code.

```cpp
        case WM_DWMSENDICONICLIVEPREVIEWBITMAP:
        {
            // This window is being asked to provide a bitmap to show in Peek preview.
            // This indicates the thumbnail in the taskbar is being previewed.
            RECT rectWindow = {0, 0, 0, 0};
            if (GetClientRect(hwnd, &rectWindow))
            {
                nWidth = rectWindow.right - rectWindow.left;
                nHeight = rectWindow.bottom - rectWindow.top;
            }

            hbm = CreateDIB(nWidth, nHeight);
            if (hbm)
            {
                hr = DwmSetIconicLivePreviewBitmap(hwnd, hbm, NULL, DWM_SIT_DISPLAYFRAME);
                DeleteObject(hbm);
            }
        }
        break;

```

For the complete example, see the [Customize an Iconic Thumbnail and a Live Preview Bitmap](https://learn.microsoft.com/windows/desktop/dwm/dwm-sample-customizethumbnail) sample.