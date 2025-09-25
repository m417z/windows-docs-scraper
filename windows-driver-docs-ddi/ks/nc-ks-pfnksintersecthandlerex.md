# PFNKSINTERSECTHANDLEREX callback function

## Description

AVStream calls a minidriver's *AVStrMiniIntersectHandlerEx* routine to determine the highest quality intersection of two data ranges.

## Parameters

### `Context` [in]

Pointer to the **Context** member of the corresponding [KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter) structure.

### `Irp` [in]

Pointer to the [IRP](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp) containing the intersection request.

### `Pin` [in]

Pointer to a structure of type [KSP_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_pin) that was passed in the intersection property request.

### `DataRange` [in]

Pointer to an array of [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures.

### `MatchingDataRange` [in]

Pointer to an array of [KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85)) structures to match to *DataRange*.

### `DataBufferSize` [in]

Specifies a value of type ULONG that contains the size of the data buffer.

### `Data` [out]

Pointer to an optional data buffer in which the minidriver outputs the intersection.

### `DataSize` [out]

Pointer to a value of type ULONG specifying the size of the data buffer.

## Return value

If the callback finds a match, return STATUS_SUCCESS. Otherwise return STATUS_NO_MATCH.

## Remarks

The minidriver specifies this routine's address in the **IntersectHandler** member of a [KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) structure.

## See also

[KSDATARANGE](https://learn.microsoft.com/previous-versions/ff561658(v=vs.85))

[KSFILTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter)

[KSPIN_DESCRIPTOR_EX](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[KSPROPERTY_PIN_DATAINTERSECTION](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-pin-dataintersection)

[KSP_PIN](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksp_pin)

[KsPinDataIntersectionEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspindataintersectionex)