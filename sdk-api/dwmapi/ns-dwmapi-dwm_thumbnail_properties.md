# DWM_THUMBNAIL_PROPERTIES structure

## Description

Specifies Desktop Window Manager (DWM) thumbnail properties. Used by the [DwmUpdateThumbnailProperties](https://learn.microsoft.com/windows/desktop/api/dwmapi/nf-dwmapi-dwmupdatethumbnailproperties) function.

## Members

### `dwFlags`

A bitwise combination of [DWM thumbnail constant](https://learn.microsoft.com/windows/desktop/dwm/dwm-tnp-constants) values that indicates which members of this structure are set.

### `rcDestination`

The area in the destination window where the thumbnail will be rendered.

### `rcSource`

The region of the source window to use as the thumbnail. By default, the entire window is used as the thumbnail.

### `opacity`

The opacity with which to render the thumbnail. 0 is fully transparent while 255 is fully opaque. The default value is 255.

### `fVisible`

**TRUE** to make the thumbnail visible; otherwise, **FALSE**. The default is **FALSE**.

### `fSourceClientAreaOnly`

**TRUE** to use only the thumbnail source's client area; otherwise, **FALSE**. The default is **FALSE**.