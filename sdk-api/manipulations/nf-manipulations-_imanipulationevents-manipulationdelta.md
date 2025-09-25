# _IManipulationEvents::ManipulationDelta

## Description

Handles events that happen when a manipulated object changes.

## Parameters

### `x` [in]

The origin x-coordinate in user-defined coordinates.

### `y` [in]

The origin y-coordinate in user-defined coordinates.

### `translationDeltaX` [in]

The translation change about the x-axis in user-defined coordinates since the last event.

### `translationDeltaY` [in]

The translation change about the y-axis in user-defined coordinates since the last event.

### `scaleDelta` [in]

The scale change since the previous event as a percentage of the previous scale.

### `expansionDelta` [in]

The expansion change since the previous event in user-defined coordinates.

### `rotationDelta` [in]

The rotation change since the previous event in radians.

### `cumulativeTranslationX` [in]

The translation about the x-axis since the beginning of the manipulation in user-defined coordinates.

### `cumulativeTranslationY` [in]

The translation about the y-axis since the beginning of the manipulation in user-defined coordinates.

### `cumulativeScale` [in]

The scale change since the beginning of the manipulation as a percentage of the original size.

### `cumulativeExpansion` [in]

The expansion change since the beginning of the manipulation in user-defined coordinates.

### `cumulativeRotation` [in]

The rotation change since the beginning of the manipulation in radians.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code.

## Remarks

Manipulation events are generated for both the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) and [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) interfaces.
If you are using the values from the [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure in calls to [ProcessMove](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processmove), the coordinates will be in
hundredths of a pixel.

**Note** When using inertia, calls to [IInertiaProcessor::Complete](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-complete) can force the current manipulation to be extrapolated resulting in large deltas being passed to the ManipulationCompleted event.
To address this issue, perform updates on the completed event in addition to the delta event.

#### Examples

The following code shows an implementation of the ManipulationDelta method.

```cpp
HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationDelta(
    /* [in] */ FLOAT x,
    /* [in] */ FLOAT y,
    /* [in] */ FLOAT translationDeltaX,
    /* [in] */ FLOAT translationDeltaY,
    /* [in] */ FLOAT scaleDelta,
    /* [in] */ FLOAT expansionDelta,
    /* [in] */ FLOAT rotationDelta,
    /* [in] */ FLOAT cumulativeTranslationX,
    /* [in] */ FLOAT cumulativeTranslationY,
    /* [in] */ FLOAT cumulativeScale,
    /* [in] */ FLOAT cumulativeExpansion,
    /* [in] */ FLOAT cumulativeRotation)
{
    m_cDeltaEventCount ++;

    // Place your code handler here to do any operations based on the manipulation.

    return S_OK;
}

```

## See also

[Adding Manipulation Support to Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/adding-manipulation-support-in-unmanaged-code)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/-imanipulationevents-methods)

[_IManipulationEvents](https://learn.microsoft.com/windows/win32/api/manipulations/nn-manipulations-_imanipulationevents)