## Description

Prevents a system-memory surface from being paged out while a bit block transfer (bitblt) operation that uses direct memory access (DMA) transfers to or from system memory is in progress.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CANTPAGELOCK
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_SURFACELOST

## Remarks

You must call **PageLock** to make use of DMA support. If you do not, the bitblt occurs by using software emulation.

The performance of the operating system can be negatively affected if too much memory is locked.

A lock count is maintained for each surface and is incremented each time that **PageLock** is called for that surface. The count is decremented when [IDirectDrawSurface7::PageUnlock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-pageunlock) is called. When the count reaches 0, the memory is unlocked, and can then be paged by the operating system.

**PageLock** works only on system-memory surfaces; it does not page-lock a display-memory surface or an emulated primary surface. If an application calls **PageLock** on a display memory surface, the method does nothing except return DD_OK.

**IDirectDrawSurface7::PageLock** was not implemented in the **IDirectDraw** interface version.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)

