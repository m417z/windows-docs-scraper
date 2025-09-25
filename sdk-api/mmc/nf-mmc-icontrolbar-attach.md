# IControlbar::Attach

## Description

The **IControlbar::Attach** method allows the snap-in to associate a control with a control bar.

## Parameters

### `nType` [in]

A value that specifies the type of control to be associated with the control bar, taken from the
[MMC_CONTROL_TYPE](https://learn.microsoft.com/windows/desktop/api/mmc/ne-mmc-mmc_control_type) enumeration.

### `lpUnknown` [in]

A pointer to the IUnknown interface on the control object to be inserted.

## Return value

This method can return one of these values.

## Remarks

Although COMBOBOXBAR appears in Mmc.idl in connection with the nType parameter, it is not implemented.

## See also

[IToolbar](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-itoolbar)