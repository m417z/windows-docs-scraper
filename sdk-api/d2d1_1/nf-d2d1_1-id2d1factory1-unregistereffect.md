# ID2D1Factory1::UnregisterEffect

## Description

Unregisters an effect within the factory instance that corresponds to the *classId* provided.

## Parameters

### `classId` [in]

Type: **REFCLSID**

The identifier of the effect to be unregistered.

## Return value

Type: **HRESULT**

D2DERR_EFFECT_IS_NOT_REGISTERED if the effect is not registered, S_OK otherwise.

## Remarks

In order for the effect to be fully unloaded, you must call **UnregisterEffect** the same number of times that you have registered the effect.

The **UnregisterEffect** method unregisters only those effects that are registered on the same factory. It cannot be used to unregister a built-in effect.

## See also

[ID2D1Factory1](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1factory1)

[ID2D1Factory1::RegisterEffect](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nf-d2d1_1-id2d1factory1-registereffectfromstring)