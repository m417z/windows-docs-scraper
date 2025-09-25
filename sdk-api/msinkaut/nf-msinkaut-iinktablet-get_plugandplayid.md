# IInkTablet::get_PlugAndPlayId

## Description

Gets a string representation of the Plug and Play identifier of the [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object.

This property is read-only.

## Parameters

## Remarks

The property value is based upon the [HIDD_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/hidsdi/ns-hidsdi-_hidd_attributes)**ProductID** member. The manufacturer of the tablet device is responsible for adding this string. The property value is empty if the tablet device does not have an identifier.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: WM_ACTIVATE, WM_ACTIVATEAPP, WMNCACTIVATE, WM_PAINT; WM_SYSCOMMAND if **wParam** is set to SC_HOTKEY or SC_TASKLIST; and WM_SYSKEYDOWN (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[IInkStrokeDisp](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkstrokedisp)

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[InkTablets](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85))