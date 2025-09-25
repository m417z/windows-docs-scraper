# IPinName::GetPinName

## Description

The `GetPinName` method retrieves the friendly name of an audio endpoint. For more information about Pins, see [Filter, Pin, and Node Properties](https://learn.microsoft.com/windows-hardware/drivers/audio/filter--pin--and-node-properties).

## Parameters

### `Irp` [in]

Specifies a pointer to an I/O request packet (IRP) structure. For more information about IRPs, see [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) and [I/O request packets](https://learn.microsoft.com/windows-hardware/drivers/gettingstarted/i-o-request-packets).

### `Pin` [in]

Specifies a pointer to the underlying kernel streaming (KS) pin.

### `Data` [out]

Specifies a pointer to the buffer that holds the data for the `GetPinName` method.

## Return value

The `GetPinName` method returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

If a client needs the current pin name of an endpoint, but has determined that the miniport driver does not support the `GetPinName` method, the client uses the friendly name of the topology bridge pin. For more information about pin categories and friendly names, see [Pin Category Property](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-category-property) and [Friendly Names for Audio Endpoint Devices](https://learn.microsoft.com/windows-hardware/drivers/audio/friendly-names-for-audio-endpoint-devices).

For more information about

**Note** In Windows 7, the user-mode audio stack does not support customization of the Speakers endpoint name. So in Windows 7, the `GetPinName` method only works with endpoints that do not have the Speakers friendly name. The following list shows the KS node type categories that are assigned the Speakers friendly name:

KSNODETYPE_SPEAKER

KSNODETYPE_DESKTOP_SPEAKER

KSNODETYPE_ROOM_SPEAKER

KSNODETYPE_LOW_FREQUENCY_EFFECTS_SPEAKER

## See also

[Friendly Names for Audio Endpoint Devices](https://learn.microsoft.com/windows-hardware/drivers/audio/friendly-names-for-audio-endpoint-devices)

[IPinName](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-ipinname)

[Filter, Pin, and Node Properties](https://learn.microsoft.com/windows-hardware/drivers/audio/filter--pin--and-node-properties)

[Pin Factories](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-factories)

[Pin Category Property](https://learn.microsoft.com/windows-hardware/drivers/audio/pin-category-property)

[KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin)

[I/O request packets](https://learn.microsoft.com/windows-hardware/drivers/gettingstarted/i-o-request-packets)