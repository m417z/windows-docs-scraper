# D3DOVERLAYCAPS structure

## Description

Specifies hardware overlay capabilities for a Direct3D device.

## Members

### `Caps`

Contains a bitwise **OR** of the following flags.

| Value | Meaning |
| --- | --- |
| **D3DOVERLAYCAPS_FULLRANGERGB**<br><br>0x00000001 | The overlay supports RGB with a nominal range of 0–255 per channel. |
| **D3DOVERLAYCAPS_LIMITEDRANGERGB**<br><br>0x00000002 | The overlay supports RGB with a nominal range of 16–235 per channel. Reference black is (16,16,16) and reference white is (235,235,235). |
| **D3DOVERLAYCAPS_YCbCr_BT601**<br><br>0x00000004 | The overlay supports the BT.601 definition of YUV. |
| **D3DOVERLAYCAPS_YCbCr_BT709**<br><br>0x00000008 | The overlay supports the BT.709 definition of YUV. |
| **D3DOVERLAYCAPS_YCbCr_BT601_xvYCC**<br><br>0x00000010 | The overlay supports extended YCbCr (xvYCC) for BT.601 YUV. |
| **D3DOVERLAYCAPS_YCbCr_BT709_xvYCC**<br><br>0x00000020 | The overlay supports extended YCbCr (xvYCC) for BT.709 YUV. |
| **D3DOVERLAYCAPS_STRETCHX**<br><br>0x00000040 | The device can stretch and shrink the overlay data arbitrarily in the horizontal direction. |
| **D3DOVERLAYCAPS_STRETCHY**<br><br>0x00000080 | The device can stretch and shrink the overlay data arbitrarily in the vertical direction. |

### `MaxOverlayDisplayWidth`

The maximum overlay width after stretching.

### `MaxOverlayDisplayHeight`

The maximum overlay height after stretching.

## See also

[Direct3D Video Structures](https://learn.microsoft.com/windows/desktop/medfound/direct3d-video-structures)

[IDirect3D9ExOverlayExtension::CheckDeviceOverlayType](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3d9exoverlayextension-checkdeviceoverlaytype)