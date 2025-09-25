# IDirectDrawSurface7::UpdateOverlayZOrder

## Description

Sets the z-order of an overlay.

## Parameters

### `unnamedParam1` [in]

One of the following flags that determines the z-order of the overlay:

#### DDOVERZ_INSERTINBACKOF

Inserts this overlay in the overlay chain behind the reference overlay.

#### DDOVERZ_INSERTINFRONTOF

Inserts this overlay in the overlay chain in front of the reference overlay.

#### DDOVERZ_MOVEBACKWARD

Moves this overlay one position backward in the overlay chain.

#### DDOVERZ_MOVEFORWARD

Moves this overlay one position forward in the overlay chain.

#### DDOVERZ_SENDTOBACK

Moves this overlay to the back of the overlay chain.

#### DDOVERZ_SENDTOFRONT

Moves this overlay to the front of the overlay chain.

### `unnamedParam2` [in]

A pointer to the [IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7) interface for the DirectDraw surface to be used as a relative position in the overlay chain. This parameter is needed only for the DDOVERZ_INSERTINBACKOF and DDOVERZ_INSERTINFRONTOF flags.

## Return value

If the method succeeds, the return value is DD_OK.

If it fails, the method can return one of the following error values:

* DDERR_INVALIDOBJECT
* DDERR_INVALIDPARAMS
* DDERR_NOTAOVERLAYSURFACE

## Remarks

## See also

[IDirectDrawSurface7](https://learn.microsoft.com/windows/desktop/api/ddraw/nn-ddraw-idirectdrawsurface7)