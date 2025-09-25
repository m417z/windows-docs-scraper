# IMSVidVideoRenderer2::put_SuppressEffects

## Description

\[The feature associated with this page, [Microsoft TV Technologies](https://learn.microsoft.com/previous-versions/windows/desktop/mstv/microsoft-tv-technologies-portal), is a legacy feature. Microsoft strongly recommends that new code does not use this feature.\]

The **put_SuppressEffects** method sets preferences for power management and visual effects.

## Parameters

### `bSuppress` [in]

Specifies a Boolean value. See Remarks for more information.

## Return value

Returns an **HRESULT** value. Possible values include the following.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |

## Remarks

If *bSuppress* equals VARIANT_TRUE, the Video Control does the following:

* Disables font smoothing and the system-wide drop shadow effect. (Only when the Video Control is using hardware overlay.) This is useful if the application draws onto the overlay.
* Disables the screen saver, and turns off power management for the display. This is useful to prevent the operating system from interrupting playback while the user is watching a program.

The Video Control restores the original system settings after it stops.

If *bSuppress* equals VARIANT_FALSE, the Video Control uses the existing system settings.

## See also

[IMSVidVideoRenderer2 Interface](https://learn.microsoft.com/windows/desktop/api/segment/nn-segment-imsvidvideorenderer2)

[IMSVidVideoRenderer::put_UsingOverlay](https://learn.microsoft.com/windows/desktop/api/segment/nf-segment-imsvidvideorenderer-put_usingoverlay)