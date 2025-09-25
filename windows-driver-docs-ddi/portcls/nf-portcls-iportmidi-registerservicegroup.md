# IPortMidi::RegisterServiceGroup

## Description

The `RegisterServiceGroup` method registers the service group to be used for the [IPortMidi::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportmidi-notify) method.

## Parameters

### `ServiceGroup` [in]

Pointer to the miniport driver's [IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup) object that is being registered.

## Remarks

The *ServiceGroup* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

## See also

[IPortMidi](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iportmidi)

[IPortMidi::Notify](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-iportmidi-notify)

[IServiceGroup](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iservicegroup)