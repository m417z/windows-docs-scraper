# IInkTablet::get_MaximumInputRectangle

## Description

Gets the maximum input rectangle, in tablet device coordinates that the [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object supports.

This property is read-only.

## Parameters

## Remarks

The rectangle returned by the **MaximumInputRectangle** property specifies the maximum allowable space in which ink can be drawn.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: WM_ACTIVATE, WM_ACTIVATEAPP, WMNCACTIVATE, WM_PAINT; WM_SYSCOMMAND if **wParam** is set to SC_HOTKEY or SC_TASKLIST; and WM_SYSKEYDOWN (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[InkRectangle Class](https://learn.microsoft.com/windows/desktop/tablet/inkrectangle-class)