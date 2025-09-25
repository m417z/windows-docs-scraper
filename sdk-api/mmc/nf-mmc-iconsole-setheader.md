# IConsole::SetHeader

## Description

**Note** The **IConsole::SetHeader** method is obsolete in MMC version 1.1 and later. It is no longer required by snap-ins. However, the method can still safely be used by snap-ins that already call it.

Sets the header interface to use for this instance of
[IComponent](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-icomponent). This is used only by instances of
**IComponent**.

## Parameters

### `pHeader` [in]

A pointer to the
**IHeaderCtrl** interface.

## Return value

This method can return one of these values.

## Remarks

The snap-in must instruct the console to release the
**IHeaderCtrl** interface by calling **IConsole::SetHeader**(NULL).

The best time to release the
**IHeaderCtrl** interface is during a call to
[IComponent::Destroy](https://learn.microsoft.com/windows/desktop/api/mmc/nf-mmc-icomponent-destroy).

## See also

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)