# ID2D1DeviceContext3::CreateSpriteBatch

## Description

Creates a new, empty sprite batch. After creating a sprite batch, use [ID2D1SpriteBatch::AddSprites](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nf-d2d1_3-id2d1spritebatch-addsprites)
to add sprites to it, then use [ID2D1DeviceContext3::DrawSpriteBatch](https://learn.microsoft.com/windows/win32/api/d2d1_3/nf-d2d1_3-id2d1devicecontext3-drawspritebatch(id2d1spritebatch_id2d1bitmap_d2d1_bitmap_interpolation_mode_d2d1_sprite_options)) to draw it.

## Parameters

### `spriteBatch` [out]

Type: **[ID2D1SpriteBatch](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1spritebatch)****

When this method returns, contains a pointer to a new, empty sprite batch to be populated by the app.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[ID2D1DeviceContext3](https://learn.microsoft.com/windows/desktop/api/d2d1_3/nn-d2d1_3-id2d1devicecontext3)