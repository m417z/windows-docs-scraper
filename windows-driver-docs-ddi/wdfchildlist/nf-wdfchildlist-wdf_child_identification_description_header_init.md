# WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT function

## Description

[Applies to KMDF only]

The **WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT** function initializes a [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure.

## Parameters

### `Header` [out]

A pointer to a driver-allocated WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER structure.

### `IdentificationDescriptionSize` [in]

The size, in bytes, of a driver-defined structure that contains device identification information. For more information about specifying the size value, see [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header).

## Remarks

The **WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT** function zeros the specified [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure and sets the structure's **IdentificationDescriptionSize** member to the specified value.

For more information about child identification descriptions, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER_INIT**, see [WdfChildListAddOrUpdateChildDescriptionAsPresent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistaddorupdatechilddescriptionaspresent).

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)