# IDirectManipulationManager::GetUpdateManager

## Description

Gets a pointer to an [IDirectManipulationUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationupdatemanager) object that receives compositor updates.

## Parameters

### `riid` [in]

IID to the interface.

### `object` [out, retval]

Pointer to the new [IDirectManipulationUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationupdatemanager) object.

## Return value

If the method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

For the compositor to respond to update events from [Direct Manipulation](https://learn.microsoft.com/previous-versions/windows/desktop/directmanipulation/direct-manipulation-portal), you must associate [IDirectManipulationUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationupdatemanager) to an [IDirectManipulationCompositor](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationcompositor) object during initialization. Use **GetUpdateManager** to obtain a pointer to a **IDirectManipulationUpdateManager** object. Pass this pointer to the compositor using the [SetUpdateManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nf-directmanipulation-idirectmanipulationcompositor-setupdatemanager) method.

## See also

[IDirectManipulationManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/directmanipulation/nn-directmanipulation-idirectmanipulationmanager)