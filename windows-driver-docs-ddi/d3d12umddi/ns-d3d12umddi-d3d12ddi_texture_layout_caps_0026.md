# D3D12DDI_TEXTURE_LAYOUT_CAPS_0026 structure

## Description

Specifies texture layout capabilities.

## Members

### `DeviceDependentLayoutCount`

A device dependent layout count. This must be the number of device-dependent layouts supported by the adapter.

### `DeviceDependentSwizzleCount`

A device dependent swizzle count. This must be the number of device-dependent swizzle patterns supported by the adapter.

### `Supports64KStandardSwizzle`

Whether the texture layout supports 64K standard swizzle.

### `SupportsRowMajorTexture`

Whether the texture layout supports row major texture.

### `IndexableSwizzlePatterns`

Whether the texture layout can choose any swizzle pattern for a subresource.