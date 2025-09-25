# _CHANGER_INITIALIZE_ELEMENT_STATUS structure

## Description

The CHANGER_INITIALIZE_ELEMENT_STATUS structure is used in conjunction with the [IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_initialize_element_status) request to initialize the status of all elements or of a specified number of elements of a particular type.

## Members

### `ElementList`

Contains a structure of type [CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list) that specifies the element type and the number of elements. If the **Features0** member of the [GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters) structure is set to CHANGER_INIT_ELEM_STAT_WITH_RANGE, the changer supports initializing a range of elements. In this case, the element type can be **ChangerTransport**, **ChangerSlot**, **ChangerDrive**, or **ChangerIEPort** and **ElementList** can specify a number of elements to initialize. Otherwise, the element type must be **AllElements** and the number of elements is ignored.

### `BarCodeScan`

Instructs the changer driver, when **TRUE**, to initialize elements by scanning bar codes. When **FALSE**, the changer driver takes no action. This member is applicable only if the **Features0** member of GET_CHANGER_PARAMETERS is set to CHANGER_BAR_CODE_SCANNER_INSTALLED. If the changer has nonvolatile RAM, a bar code scan can serve as an optimization.

## See also

[CHANGER_ELEMENT_LIST](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_changer_element_list)

[ChangerInitializeElementStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/mcd/nf-mcd-changerinitializeelementstatus)

[GET_CHANGER_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ns-ntddchgr-_get_changer_parameters)

[IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddchgr/ni-ntddchgr-ioctl_changer_initialize_element_status)