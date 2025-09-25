# IDCompositionAnimation::SetAbsoluteBeginTime

## Description

Sets the absolute time at which the animation function starts.

## Parameters

### `beginTime` [in]

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)**

The starting time for this animation.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the function succeeds, it returns S_OK. Otherwise, it returns an **HRESULT** error code. See [DirectComposition Error Codes](https://learn.microsoft.com/windows/desktop/directcomp/directcomposition-error-codes) for a list of error codes.

## Remarks

By default, an animation function starts when the first frame of the animation takes effect. For example, if an application creates a simple animation function with a single primitive at offset zero, associates the animation with some property, and then calls the [IDCompositionDevice::Commit](https://learn.microsoft.com/windows/desktop/api/dcomp/nf-dcomp-idcompositiondevice-commit) method, the first frame that includes the commit samples the animation at offset zero for the first primitive.

This implies that the actual default start time of all animations varies depending on the time between when the application creates the animation and calls **Commit**, to the time it takes the composition engine to pick up the committed changes. The application can use the **SetAbsoluteBeginTime** method to exercise finer control over the starting time of an animation.

This method does not control when animations take effect; it only affects how animations are sampled after they start. If the application specifies the exact time of the next frame as the absolute begin time, the result is the same as not calling this method at all. If the specified begin time is different from the time of the next frame, the result is one of following:

* If the specified time is later than the next frame time, the animation start is delayed until the specified begin time.
* If the specified time is earlier than the next frame time, the beginning of the animation is dropped and sampling starts into the animation function.

## See also

[IDCompositionAnimation](https://learn.microsoft.com/windows/desktop/api/dcompanimation/nn-dcompanimation-idcompositionanimation)