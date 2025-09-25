# IInkTablet::get_HardwareCapabilities

## Description

Gets a bitmask that defines the hardware capabilities of the tablet, such as whether a cursor must be in physical contact with the tablet to report its position.

This property is read-only.

## Parameters

## Remarks

For a complete list of hardware capability values that you can use, see the [TabletHardwareCapabilities](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tablethardwarecapabilities) enumeration type.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: WM_ACTIVATE, WM_ACTIVATEAPP, WMNCACTIVATE, WM_PAINT; WM_SYSCOMMAND if **wParam** is set to SC_HOTKEY or SC_TASKLIST; and WM_SYSKEYDOWN (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[TabletHardwareCapabilities Enumeration](https://learn.microsoft.com/windows/desktop/api/msinkaut/ne-msinkaut-tablethardwarecapabilities)