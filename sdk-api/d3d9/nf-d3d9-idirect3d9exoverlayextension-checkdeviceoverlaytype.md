# IDirect3D9ExOverlayExtension::CheckDeviceOverlayType

## Description

Queries the overlay hardware capabilities of a Direct3D device.

## Parameters

### `Adapter` [in]

An ordinal number that denotes the display adapter. **D3DADAPTER_DEFAULT** is always the primary display adapter.

### `DevType` [in]

Specifies the Direct3D device type as a member of the **D3DDEVTYPE** enumerated type.

### `OverlayWidth` [in]

The width of the overlay to create, in pixels.

### `OverlayHeight` [in]

The height of the overlay to create, in pixels.

### `OverlayFormat` [in]

The surface format of the overlay.

### `pDisplayMode` [in]

A pointer to a **D3DDISPLAYMODEEX** structure that specifies the display mode that will be used. If this parameter is **NULL**, the current display mode is assumed.

### `DisplayRotation` [in]

Specifies the display rotation mode as a member of the **D3DDISPLAYROTATION** enumerated type.

### `pOverlayCaps` [out]

A pointer to a [D3DOVERLAYCAPS](https://learn.microsoft.com/windows/desktop/api/d3d9caps/ns-d3d9caps-d3doverlaycaps) structure. If the driver supports the overlay settings specified in the input parameters, the method fills this structure with the capabilities of the overlay hardware.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **D3DERR_INVALIDCALL** | Invalid parameter, or the device does not support hardware overlay. |
| **D3DERR_UNSUPPORTEDOVERLAY** | The device does not support overlay for the specified size or display mode. |
| **D3DERR_UNSUPPORTEDOVERLAYFORMAT** | The device does not support overlay for the specified surface format. |

## See also

[Hardware Overlay Support](https://learn.microsoft.com/windows/desktop/medfound/hardware-overlay-support)

[IDirect3D9ExOverlayExtension](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3d9exoverlayextension)