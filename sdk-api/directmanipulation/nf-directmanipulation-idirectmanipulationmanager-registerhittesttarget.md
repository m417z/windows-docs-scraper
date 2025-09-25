# IDirectManipulationManager::RegisterHitTestTarget

## Description

Registers a dedicated thread for hit testing.

## Parameters

### `window` [in]

The handle of the main app window (typically created from the UI thread).

### `hitTestWindow` [in, optional]

The handle of the window in which hit testing is registered (should be created from the hit testing thread). Pass in nullptr to unregister a previously registered hit-test target.

### `type` [in]

One of the values from [DIRECTMANIPULATION_HITTEST_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_hittest_type). Specifies whether the UI window or the hit testing window (or both) receives the hit testing [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) message , and in what order.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Hit testing is typically performed on the application UI thread. The application receives a [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) message on which hit-testing is performed. If a manipulation is required, [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) is called on one or more viewports. An application can use the **RegisterHitTestTarget** method to delegate this hit-testing responsibility to a separate hit-testing thread.

Once a dedicated hit-test target is successfully registered, [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages are processed on the hit-testing thread. If a manipulation, such as pan or zoom, is required, [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) is called from this thread.

If [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) is not called from the hit-testing thread, [WM_POINTERDOWN](https://learn.microsoft.com/previous-versions/windows/desktop/inputmsg/wm-pointerdown) messages may be processed on the UI thread, depending on the [DIRECTMANIPULATION_HITTEST_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/ne-directmanipulation-directmanipulation_hittest_type) specified during registration.

If [SetContact](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationviewport-setcontact) is not called by either the hit-test thread or the UI thread, [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal) ignores the input which is then handled on the UI thread.

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)