# IDirectDrawSurface7::Lock

## Description

Obtains a pointer to the surface memory.

## Parameters

### `unnamedParam1` [in]

A pointer to a **RECT** structure that identifies the region of the surface that is being locked. If this parameter is NULL, the entire surface is locked.

### `unnamedParam2` [in, out]

A pointer to a [DDSURFACEDESC2](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff550340(v=vs.85)) structure that describes relevant details about the surface and that receives information about the surface.

### `unnamedParam3` [in]

A combination of flags that determine how to lock the surface. The following flags are defined:

#### DDLOCK_DONOTWAIT

On [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interfaces, the default is DDLOCK_WAIT. If you want to override the default and use time when the accelerator is busy (as denoted by the DDERR_WASSTILLDRAWING return value), use DDLOCK_DONOTWAIT.

#### DDLOCK_EVENT

Not currently implemented.

#### DDLOCK_NOOVERWRITE

New for DirectX 7.0. Used only with Direct3D vertex-buffer locks. Indicates that no vertices that were referred to in a draw operation since the start of the frame (or the last lock without this flag) are modified during the lock. This can be useful when you want only to append data to the vertex buffer.

#### DDLOCK_NOSYSLOCK

Do not take the Win16Mutex (also known as Win16Lock). This flag is ignored when locking the primary surface.

#### DDLOCK_DISCARDCONTENTS

New for DirectX 7.0. Used only with Direct3D vertex-buffer locks. Indicates that no assumptions are made about the contents of the vertex buffer during this lock. This enables Direct3D or the driver to provide an alternative memory area as the vertex buffer. This is useful when you plan to clear the contents of the vertex buffer and fill in new data.

#### DDLOCK_OKTOSWAP

This flag is obsolete and was replaced by the DDLOCK_DISCARDCONTENTS flag.

#### DDLOCK_READONLY

Indicates that the surface being locked can only be read.

#### DDLOCK_SURFACEMEMORYPTR

Indicates that a valid memory pointer to the top of the specified rectangle should be returned. If no rectangle is specified, a pointer to the top of the surface is returned. This is the default.

#### DDLOCK_WAIT

If a lock cannot be obtained because a bit block transfer (bitblt) operation is in progress, **Lock** retries until a lock is obtained or another error occurs, such as DDERR_SURFACEBUSY.

#### DDLOCK_WRITEONLY

Indicates that the surface being locked is write-enabled.

### `unnamedParam4` [in]

Handle of the event. This parameter is not currently used and must be set to NULL.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_OUTOFMEMORY
* DDERR_SURFACEBUSY
* DDERR_SURFACELOST
* DDERR_WASSTILLDRAWING

## Remarks

In [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7), the default behavior of **Lock** is to wait for the accelerator to finish. Therefore, under default conditions, **Lock** never returns DDERR_WASSTILLDRAWING. If you want to see the error codes and not wait until the bitblt operation succeeds, use the DDLOCK_DONOTWAIT flag.

After retrieving a surface memory pointer, you can access the surface memory until a corresponding [IDirectDrawSurface7::Unlock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-unlock) method is called. When the surface is unlocked, the pointer to the surface memory is invalid.

Do not call DirectDraw bitblt functions to bitblt from a locked region of a surface. If you do, the bitblt returns either DDERR_SURFACEBUSY or DDERR_LOCKEDSURFACES. GDI blit functions also silently fail when used on a locked video memory surface.

Unless you include the DDLOCK_NOSYSLOCK flag, **Lock** causes DirectDraw to hold the Win16Mutex (also known as Win16Lock) until you call the [IDirectDrawSurface7::Unlock](https://learn.microsoft.com/windows/desktop/api/ddraw/nf-ddraw-idirectdrawsurface7-unlock) method. GUI debuggers cannot operate while the Win16Mutex is held.

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)