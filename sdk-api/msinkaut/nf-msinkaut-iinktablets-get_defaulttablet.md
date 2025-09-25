# IInkTablets::get_DefaultTablet

## Description

Gets the default tablet within the set of available tablets.

This property is read-only.

## Parameters

## Remarks

The platform determines the default [IInkTablet](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet) object in the following order:

* If the system has a digitizer integrated with the display device, this integrated digitizer is considered the default tablet, even if other digitizing tablets are installed.
* If more than one digitizing tablet is installed in the system, the first one encountered during initialization is considered the default tablet.
* If only one digitizing tablet is installed in the system, it is considered the default tablet.
* If no digitizing tablets are installed in the system but there are other pointing devices (such as a mouse or a touch pad) installed that generate mouse messages, those devices in aggregate are considered to be the default tablet.
* If no digitizing tablets and no pointing devices are installed in the system, no default tablet can be returned.

**Note** Accessing this property within certain message handlers can result in the underlying function being re-entered, causing unexpected results. Take care to avoid a reentrant call when handling any of the following messages: **WM_ACTIVATE**, **WM_ACTIVATEAPP**, **WM_NCACTIVATE**, **WM_PAINT**; **WM_SYSCOMMAND** if *wParam* is set to SC_HOTKEY or SC_TASKLIST; and **WM_SYSKEYDOWN** (when processing Alt-Tab or Alt-Esc key combinations). This is an issue with single-threaded apartment model applications.

## See also

[IInkTablet Interface](https://learn.microsoft.com/windows/desktop/api/msinkaut/nn-msinkaut-iinktablet)

[IInkTablets](https://learn.microsoft.com/windows/win32/api/msinkaut/nn-msinkaut-iinktablets)

[InkTablets Collection](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms704832(v=vs.85))