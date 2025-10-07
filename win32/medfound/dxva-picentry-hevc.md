# DXVA\_PicEntry\_HEVC structure

Specifies a reference to an uncompressed surface.

## Members

**Index7Bits**

An index that identifies an uncompressed surface .

**AssociatedFlag**

Optional 1-bit flag associated with the surface. The meaning of the flag depends on the context. For example, it can specify whether the reference frame is a long-term reference or a short-term reference.

**bPicEntry**

Accesses the entire 8 bits of the union.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 8.1 \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2012 R2 \[desktop apps only\]<br> |
| Header<br> | Dxva.h |

## See also

[Media Foundation Structures](https://learn.microsoft.com/windows/win32/medfound/media-foundation-structures)

