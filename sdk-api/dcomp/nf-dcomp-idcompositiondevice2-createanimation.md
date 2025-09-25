# IDCompositionDevice2::CreateAnimation

## Description

Creates an animation object that is used to animate one or more scalar properties of one or more Microsoft DirectComposition objects.

## Parameters

### `animation` [out]

Type: **[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)****

The new animation object. This parameter must not be NULL.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

A number of DirectComposition object properties can have an animation object as the value of the property. When a property has an animation object as its value, DirectComposition redraws the visual at the refresh rate to reflect the changing value of the property that is being animated.

A newly created animation object does not have any animation segments associated with it. An application must use the methods of the [IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation) interface to build an animation function before setting the animation object as the property of another DirectComposition object.

## See also

[IDCompositionDevice2](https://learn.microsoft.com/windows/desktop/api/dcomp/nn-dcomp-idcompositiondevice2)