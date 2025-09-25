# KsPinPropertyHandler function

## Description

The **KsPinPropertyHandler** function performs standard handling of the static members of **the** [KSPROPSETID_Pin](https://learn.microsoft.com/windows-hardware/drivers/stream/kspropsetid-pin) property set. This handling does not include [KSPROPERTY_PIN_CINSTANCES](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-cinstances) or [KSPROPERTY_PIN_DATAINTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataintersection).

## Parameters

### `Irp` [in]

Specifies the IRP handling the connection request.

### `Property` [in]

Specifies the specific property information.

### `Data` [in, out]

Specifies the data parameter mapped to a system address. This is the same parameter passed to a property handler through a [KsPropertyHandler](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspropertyhandler) callback.

### `DescriptorsCount` [in]

Specifies the number of pin descriptors being passed.

### `Descriptor` [in]

Specifies the pointer to the list of pin descriptors.

## Return value

The **KsPinPropertyHandler** function returns STATUS_SUCCESS or an error specific to the property being handled. The function fills in the IO_STATUS_BLOCK.Information field of the PIRP.IoStatus element within the IRP. It does not set the IO_STATUS_BLOCK.Status field nor complete the IRP.

## Remarks

Do not use the **KsPinPropertyHandler** function to define a pin property set; a pin property set can be more easily defined using the DEFINE_KSPROPERY_PINSET macro.