# IMSVidVMR9::put_SuppressEffects

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

This topic applies to Update Rollup 2 for Microsoft Windows XP Media Center Edition 2005.

The **put_SuppressEffects** method specifies whether the Video Control configures the system for optimal video playback.

## Parameters

### `bSuppress` [in]

Specifies a Boolean value. See Remarks for more information.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

If *bSuppress* equals VARIANT_TRUE, the Video Control configures several system parameters during video playback:

* Disables the screen saver timeout.
* Disables Microsoft ClearType smoothing.
* Disables the drop shadow effect.
* Disables alpha-blended mouse cursors.
* Prevents the system from turning off the display (power management).

For applications based on the Windows Graphics Device Interface (GDI), these settings improve the video playback experience. When playback stops, the Video Control restores the original system settings.

If *bSuppress* equals VARIANT_FALSE, the Video Control does not modify any of these system settings.

The default value for this property is VARIANT_TRUE. Set this property to VARIANT_FALSE if your application wants to control all of the system settings; for example, if you are providing a custom allocator-presenter (see [IMSVidVMR9::SetAllocator](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvmr9-setallocator)).

## See also

[IMSVidVMR9 Interface](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/msvidvmr9)