# XAPOAlloc macro

## Syntax

```cpp
LPVOID XAPOAlloc(
    ULONG size
);
```

## Return value

Type: **LPVOID**

Allocated memory block; returns **NULL** if insufficient memory available.

## Description

Memory allocation macro used by IXAPO methods that must allocate arbitrary sized structures that are subsequently returned to the application.

## Parameters

### `size`

Size, in bytes, of the memory block to be allocated.

## Remarks

[XAPOFree](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapofree) and **XAPOAlloc** are memory allocation macros that allow one module to allocate memory and another to free it, by guaranteeing that the same heap manager is used regardless of differences between the build environments of the two modules.

| Xbox 360 |
| --- |
| [XAPOFree](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapofree) and **XAPOAlloc** resolve to **XMemAlloc** and **XMemFree** on Xbox 360. |

| Windows |
| --- |
| [XAPOFree](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-xapofree) and **XAPOAlloc** resolve to **CoTaskMemAlloc** and **CoTaskMemFree**. |

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Macros](https://learn.microsoft.com/windows/desktop/xaudio2/macros)