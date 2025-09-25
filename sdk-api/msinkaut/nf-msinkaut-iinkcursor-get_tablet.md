# IInkCursor::get_Tablet

## Description

Gets either the [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object to which a cursor belongs or the **IInkTablet** object that an object or control is currently using to collect input.

This property is read-only.

## Parameters

## Remarks

For an object or control that collects ink, this property is valid only when the object or control is collecting ink from just one tablet. Accessing this property for an object or control that is collecting ink from all tablets generates an exception.

Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[Id Property](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcursorbutton-get_id)

[InkCursor Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor)

[SetAllTabletsMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setalltabletsmode)

[SetSingleTabletIntegratedMode Method](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkcollector-setsingletabletintegratedmode)