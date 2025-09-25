# DwmSetIconicThumbnail function

## Description

Sets a static, iconic bitmap on a window or tab to use as a thumbnail representation. The taskbar can use this bitmap as a thumbnail switch target for the window or tab.

## Parameters

### `hwnd` [in]

A handle to the window or tab. This window must belong to the calling process.

### `hbmp` [in]

A handle to the bitmap to represent the window that *hwnd* specifies.

### `dwSITFlags` [in]

The display options for the thumbnail. One of the following values:

#### 0 (0x00000000)

No frame is displayed around the provided thumbnail.

#### DWM_SIT_DISPLAYFRAME (0x00000001)

Displays a frame around the provided thumbnail.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application typically calls the **DwmSetIconicThumbnail** function after it receives a [WM_DWMSENDICONICTHUMBNAIL](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmsendiconicthumbnail) message for its window. The thumbnail should not exceed the maximum x-coordinate and y-coordinate that are specified in that message. The thumbnail must also have a 32-bit color depth.

The application calls [DwmInvalidateIconicBitmaps](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwminvalidateiconicbitmaps) to indicate to the Desktop Window Manager (DWM) that the iconic thumbnail and live preview bitmaps are out-of-date and should be refreshed. The DWM then requests new versions from the window when they are needed. However, if the DWM bitmap cache is full, DWM will not request updated versions.

The DWM uses a copy of the bitmap, but the application can release this copy at any time because of memory constraints. If the copy is released, the window is not notified, but it might receive a subsequent [WM_DWMSENDICONICTHUMBNAIL](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmsendiconicthumbnail) request when its thumbnail is needed again. The caller retains ownership of the original bitmap and is responsible for freeing the resources that it uses when it is no longer needed.

#### Examples

Before calling **DwmSetIconicThumbnail**, the application must first call the [DwmSetWindowAttribute](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmsetwindowattribute) function to set the **DWMWA_FORCE_ICONIC_REPRESENTATION** and **DWMWA_HAS_ICONIC_BITMAP** attributes, as shown in the following example.

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

Next, the application calls the **DwmSetIconicThumbnail** function in response to a [WM_DWMSENDICONICTHUMBNAIL](https://learn.microsoft.com/windows/desktop/dwm/wm-dwmsendiconicthumbnail) message, as shown in the following example.

```cpp
        case WM_DWMSENDICONICTHUMBNAIL:
        {
            // This window is being asked to provide its iconic bitmap. This indicates
            // a thumbnail is being drawn.
            hbm = CreateDIB(HIWORD(lParam), LOWORD(lParam));
            if (hbm)
            {
                hr = DwmSetIconicThumbnail(hwnd, hbm, 0);
                DeleteObject(hbm);
            }
        }
        break;

```

For the complete example code, see the [Customize an Iconic Thumbnail and a Live Preview Bitmap](https://learn.microsoft.com/windows/desktop/dwm/dwm-sample-customizethumbnail) sample.