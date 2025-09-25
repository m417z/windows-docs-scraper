## Description

The **BdaPropertyGetPinControl** function retrieves either the identifier or type of a pin.

## Parameters

### `Irp` [in]

Points to the IRP for the request to retrieve pin information. The BDA minidriver receives this IRP with either the [KSPROPERTY_BDA_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-id) or [KSPROPERTY_BDA_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-type) request.

### `Property` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

### `pulProperty` [out, optional]

Points to a variable that receives either the identifier or type of a pin.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A BDA minidriver calls the **BdaPropertyGetPinControl** function to retrieve either the identifier or type of a pin after the minidriver receives either a [KSPROPERTY_BDA_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-id) or [KSPROPERTY_BDA_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-type) request of the [KSPROPSETID_BdaPinControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdapincontrol) property set. Most BDA minidrivers can define pin-automation tables so that those minidrivers dispatch the **BdaPropertyGetPinControl** function directly, without intercepting this request using an internal get-handler ([KStrGetPropertyHandler](https://learn.microsoft.com/previous-versions/ff567177(v=vs.85))).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_PIN_ID](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-id)

[KSPROPERTY_BDA_PIN_TYPE](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-pin-type)

[KSPROPSETID_BdaPinControl](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdapincontrol)