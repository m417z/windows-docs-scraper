## Description

Unlocks a system-memory surface, which then allows it to be paged out.

## Parameters

### `unnamedParam1` [in]

Currently not used and must be set to 0.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_CANTPAGEUNLOCK
* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTPAGELOCKED
* DDERR_SURFACELOST

## Remarks

A lock count is maintained for each surface and is incremented each time that [IDirectDrawSurface7::PageLock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-pagelock) is called for that surface. The count is decremented when **PageUnlock** is called. When the count reaches 0, the memory is unlocked, and can then be paged by the operating system.

**PageUnlock** works only on system-memory surfaces; it does not page-unlock a display-memory surface or an emulated primary surface. If an application calls **PageUnlock** on a display memory surface, the method does nothing except return DD_OK.

**IDirectDrawSurface7::PageUnlock** was not implemented in the **IDirectDraw** interface version.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)