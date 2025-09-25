# IMenuButton::AddButton

## Description

The **IMenuButton::AddButton** method enables a user to add a button to the MMC menu bar for a particular view.

## Parameters

### `idCommand` [in]

A value that specifies a user-supplied value that uniquely identifies the button to be added to the menu bar.

### `lpButtonText` [in]

A pointer to the text value (a null-terminated string) to be displayed on the button.

### `lpTooltipText` [in]

A pointer to the text value (a null-terminated string) to be displayed when the user places the mouse pointer on the button.

## Return value

This method can return one of these values.

## Remarks

Buttons added to the MMC menu bar for a particular view are always appended to the buttons already present. The initial state of any menu button is hidden and disabled.

When the snap-in loses the focus, these buttons are automatically removed from the menu bar. As a result, they must be added each time the snap-in gets the focus.

This method can be called by primary or extension snap-ins.

## See also

[IMenuButton](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-imenubutton)