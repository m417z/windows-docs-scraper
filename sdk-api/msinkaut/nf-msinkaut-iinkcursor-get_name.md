# IInkCursor::get_Name

## Description

Gets the name of the object.

This property is read-only.

## Parameters

## Remarks

Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[InkCursor Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinkcursor)