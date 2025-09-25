# PFND3DWDDM2_0DDI_GETRESOURCELAYOUT callback function

## Description

The *pfnGetResourceLayout* callback function supports getting resource layout information.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource*

A resource handle.

### `SubresourceCount`

The subresource count.

### `unnamedParam4`

*Handle* [out]

A kernel handle.

### `unnamedParam5`

*TextureLayout* [out]

A pointer to a texture layout.

### `pMipLevelSwizzleTransition` [out]

A pointer to a MIP level swizzle transition.

### `unnamedParam7`

*SubresourceLayout* [out, optional]

A pointer to the subresource layout.