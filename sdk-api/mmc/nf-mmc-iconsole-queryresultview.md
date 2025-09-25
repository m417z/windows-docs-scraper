# IConsole::QueryResultView

## Description

Queries
[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole) for the result view object
[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer.

## Parameters

### `pUnknown` [out]

A pointer to the location of the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointer to the result view object.

## Return value

This method can return one of these values.

## Remarks

**QueryResultView** can be used when the result view is an OLE custom control (OCX) that implements the
[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface. The user should call
**QueryResultView** to get the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointer to the OCX. This is necessary because the Node Manager handles the creation of the OCX.

## See also

[IConsole](https://learn.microsoft.com/windows/desktop/api/mmc/nn-mmc-iconsole)