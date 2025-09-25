# WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT function

## Description

[Applies to KMDF only]

The **WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT** function initializes a [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure.

## Parameters

### `Header` [out]

A pointer to a driver-allocated WDF_CHILD_ADDRESS_DESCRIPTION_HEADER structure.

### `AddressDescriptionSize` [in]

The size, in bytes, of a driver-defined structure that contains device address information. For more information about specifying the size value, see [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header).

## Remarks

The **WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT** function zeros the specified [WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header) structure and sets the structure's **AddressDescriptionSize** member to the specified value.

For more information about child address descriptions, see [Dynamic Enumeration](https://learn.microsoft.com/windows-hardware/drivers/wdf/dynamic-enumeration).

#### Examples

For a code example that uses **WDF_CHILD_ADDRESS_DESCRIPTION_HEADER_INIT**, see [WdfChildListRetrieveAddressDescription](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/nf-wdfchildlist-wdfchildlistretrieveaddressdescription).

## See also

[WDF_CHILD_ADDRESS_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_address_description_header)