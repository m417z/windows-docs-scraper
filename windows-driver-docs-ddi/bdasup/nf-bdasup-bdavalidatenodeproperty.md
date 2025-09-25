## Description

The **BdaValidateNodeProperty** function validates that a node property request is associated with a specific pin.

## Parameters

### `pIrp` [in]

Points to the IRP for the request to validate that the current pin controls the node property at *pProperty*. The BDA minidriver can receive this IRP with the [KSPROPERTY_BDA_RF_TUNER_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-rf-tuner-frequency) or [KSPROPERTY_BDA_AUTODEMODULATE_START](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-autodemodulate-start) request.

### `pProperty` [in]

Points to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property and request type of the property request.

## Return value

Returns STATUS_SUCCESS or an appropriate error code.

## Remarks

A pin method in a BDA minidriver calls the **BdaValidateNodeProperty** function to validate that the pin controls a specific node property after the minidriver receives the node property request from the network provider. This node property request can be, for example, a [KSPROPERTY_BDA_RF_TUNER_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-rf-tuner-frequency) request of the [KSPROPSETID_BdaFrequencyFilter](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdafrequencyfilter) property set or a [KSPROPERTY_BDA_AUTODEMODULATE_START](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-autodemodulate-start) request of the [KSPROPSETID_BdaAutodemodulate](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdaautodemodulate) property set. These property sets manipulate tuner and demodulator nodes. After successfully calling **BdaValidateNodeProperty**, the minidriver obtains a pointer to the BDA filter from the passed IRP so that the minidriver can perform an operation on the particular node.

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_BDA_AUTODEMODULATE_START](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-autodemodulate-start)

[KSPROPERTY_BDA_RF_TUNER_FREQUENCY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-bda-rf-tuner-frequency)

[KSPROPSETID_BdaAutodemodulate](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdaautodemodulate)

[KSPROPSETID_BdaFrequencyFilter](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-bdafrequencyfilter)