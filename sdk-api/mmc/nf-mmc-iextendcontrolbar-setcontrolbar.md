# IExtendControlbar::SetControlbar

## Description

The **IExtendControlbar::SetControlbar** method attaches or detaches a control bar.

## Parameters

### `pControlbar` [in]

A pointer to an
[IControlbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icontrolbar) interface on the control bar object to be set. A non-**NULL** value attaches a control bar; a **NULL** value detaches a control bar.

## Return value

This method can return one of these values.

## Remarks

As items are selected and deselected, snap-ins are activated and deactivated. When a snap-in is activated, the console calls
SetControlbar with a non-**NULL** pControlbar value. The snap-in should call AddRef on this IControlBar. The snap-in should also use this opportunity to attach controls. Similarly, when the snap-in is deactivated, the console calls
SetControlbar with a **NULL** pControlbar. The snap-in should then detach its controls and call Release on the saved IControlBar.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)