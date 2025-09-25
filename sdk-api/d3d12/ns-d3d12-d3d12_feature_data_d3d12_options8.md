## Description

Indicates whether or not unaligned block-compressed textures are supported.

## Members

### `UnalignedBlockTexturesSupported`

Type: \_Out\_ **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

Indicates whether or not unaligned block-compressed textures are supported.

If `false`, then Direct3D 12 requires that the dimensions of the top-level mip of a block-compressed texture are aligned to multiples of 4 (such alignment requirements do not apply to less-detailed mips). If `true`, then no such alignment requirement applies to any mip level of a block-compressed texture.

## Remarks

## See also