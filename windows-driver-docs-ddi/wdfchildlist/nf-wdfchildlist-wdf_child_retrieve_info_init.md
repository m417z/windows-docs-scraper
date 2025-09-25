# WDF_CHILD_RETRIEVE_INFO_INIT function

## Description

[Applies to KMDF only]

The **WDF_CHILD_RETRIEVE_INFO_INIT** function initializes a [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

## Parameters

### `Info` [out]

A pointer to a driver-supplied [WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info) structure.

### `IdentificationDescription` [in]

A pointer to a driver-supplied [WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header) structure.

## See also

[WDF_CHILD_IDENTIFICATION_DESCRIPTION_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_identification_description_header)

[WDF_CHILD_RETRIEVE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfchildlist/ns-wdfchildlist-_wdf_child_retrieve_info)