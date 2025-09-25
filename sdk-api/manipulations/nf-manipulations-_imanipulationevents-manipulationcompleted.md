# _IManipulationEvents::ManipulationCompleted

## Description

Handles the event when manipulation or inertia finishes.

## Parameters

### `x` [in]

The origin x-coordinate in user-defined coordinates.

### `y` [in]

The origin y-coordinate in user-defined coordinates.

### `cumulativeTranslationX` [in]

The total translation about the x-axis since the beginning of the manipulation in user-defined coordinates.

### `cumulativeTranslationY` [in]

The total translation about the y-axis since the beginning of the manipulation in user-defined coordinates.

### `cumulativeScale` [in]

The total scale change since the beginning of the manipulation as a percentage of the original size.

### `cumulativeExpansion` [in]

The total expansion change since the beginning of the manipulation in user-defined coordinates.

### `cumulativeRotation` [in]

The total rotation change since the beginning of the manipulation in radians.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code.

## Remarks

Manipulation events are generated for both the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) and [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) interfaces.
If you are using the values from the [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure in calls to [ProcessUp](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processup), the coordinates will be in
hundredths of a pixel.

**Note** When using inertia, calls to [IInertiaProcessor::Complete](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-iinertiaprocessor-complete) can force the current manipulation to be extrapolated resulting in large deltas being passed to the ManipulationCompleted event.
To address this issue, perform updates on the completed event in addition to the delta event.

#### Examples

The following code shows an implementation of the ManipulationCompleted method.

```cpp

HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationCompleted(
    /* [in] */ FLOAT x,
    /* [in] */ FLOAT y,
    /* [in] */ FLOAT cumulativeTranslationX,
    /* [in] */ FLOAT cumulativeTranslationY,
    /* [in] */ FLOAT cumulativeScale,
    /* [in] */ FLOAT cumulativeExpansion,
    /* [in] */ FLOAT cumulativeRotation)
{
    m_cCompletedEventCount ++;

    m_fX = x;
    m_fY = y;
    m_fCumulativeTranslationX = cumulativeTranslationX;
    m_fCumulativeTranslationY = cumulativeTranslationY;
    m_fCumulativeScale = cumulativeScale;
    m_fCumulativeExpansion = cumulativeExpansion;
    m_fCumulativeRotation = cumulativeRotation;

    // Place your code handler here to do any operations based on the manipulation.

    return S_OK;
}

```

## See also

[Adding Manipulation Support to Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/adding-manipulation-support-in-unmanaged-code)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/-imanipulationevents-methods)

[_IManipulationEvents](https://learn.microsoft.com/windows/win32/api/manipulations/nn-manipulations-_imanipulationevents)