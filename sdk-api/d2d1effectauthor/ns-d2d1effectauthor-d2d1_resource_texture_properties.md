# D2D1_RESOURCE_TEXTURE_PROPERTIES structure

## Description

Defines a resource texture when the original resource texture is created.

## Members

### `extents`

The extents of the resource table in each dimension.

### `dimensions`

The number of dimensions in the resource texture. This must be a number from 1 to 3.

### `bufferPrecision`

The precision of the resource texture to create.

### `channelDepth`

The number of channels in the resource texture.

### `filter`

The filtering mode to use on the texture.

### `extendModes`

Specifies how pixel values beyond the extent of the texture will be sampled, in every dimension.

## See also

[ID2D1EffectContext::CreateResourceTexture](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createresourcetexture)