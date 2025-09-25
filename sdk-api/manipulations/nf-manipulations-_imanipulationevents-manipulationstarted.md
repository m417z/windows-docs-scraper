# _IManipulationEvents::ManipulationStarted

## Description

Handles the event for when manipulation or inertia begins.

## Parameters

### `x` [in]

The origin x-coordinate in user-defined coordinates.

### `y` [in]

The origin y-coordinate in user-defined coordinates.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an HRESULT error code.

## Remarks

Manipulation events are generated for both the [IInertiaProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-iinertiaprocessor) and [IManipulationProcessor](https://learn.microsoft.com/windows/desktop/api/manipulations/nn-manipulations-imanipulationprocessor) interfaces.
If you are using the values from the [TOUCHINPUT](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-touchinput) structure in calls to [ProcessDown](https://learn.microsoft.com/windows/desktop/api/manipulations/nf-manipulations-imanipulationprocessor-processdown), the coordinates will be in
hundredths of a pixel.

#### Examples

The following code shows an implementation of the ManipulationStarted method.

```cpp

HRESULT STDMETHODCALLTYPE CManipulationEventSink::ManipulationStarted(
    /* [in] */ FLOAT x,
    /* [in] */ FLOAT y)
{
    m_cStartedEventCount ++;

    // place your code handler here to do any operations based on the manipulation

    return S_OK;
}

```

## See also

[Adding Manipulation Support to Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/adding-manipulation-support-in-unmanaged-code)

[Handling Inertia in Unmanaged Code](https://learn.microsoft.com/windows/desktop/wintouch/handling-inertia-in-unmanaged-code)

[Methods](https://learn.microsoft.com/windows/desktop/wintouch/-imanipulationevents-methods)

[_IManipulationEvents](https://learn.microsoft.com/windows/win32/api/manipulations/nn-manipulations-_imanipulationevents)