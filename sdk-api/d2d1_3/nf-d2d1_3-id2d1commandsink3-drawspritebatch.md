# ID2D1CommandSink3::DrawSpriteBatch

## Description

Renders part or all of the given sprite batch to the device context using the specified drawing options.

## Parameters

### `spriteBatch` [in]

Type: **[ID2D1SpriteBatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1spritebatch)***

The sprite batch to draw.

### `startIndex`

Type: **UINT32**

The index of the first sprite in the sprite batch to draw.

### `spriteCount`

Type: **UINT32**

The number of sprites to draw.

### `bitmap` [in]

Type: **[ID2D1Bitmap](https://learn.microsoft.com/windows/desktop/api/d2d1/nn-d2d1-id2d1bitmap)***

The bitmap from which the sprites are to be sourced. Each sprite’s source rectangle refers to a portion of this bitmap.

### `interpolationMode`

Type: **[D2D1_BITMAP_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d2d1/ne-d2d1-d2d1_bitmap_interpolation_mode)**

The interpolation mode to use when drawing this sprite batch. This determines how Direct2D interpolates pixels within the drawn sprites if scaling is performed.

### `spriteOptions`

Type: **[D2D1_SPRITE_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d2d1_3/ne-d2d1_3-d2d1_sprite_options)**

The additional drawing options, if any, to be used for this sprite batch.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1CommandSink3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1commandsink3)