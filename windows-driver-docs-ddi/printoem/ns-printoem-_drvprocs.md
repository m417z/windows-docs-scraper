## Description

The **DRVPROCS** structure is obsolete and is not used with the COM interfaces for Microsoft printer drivers.

The structure contains the addresses of helper functions that are provided to rendering plug-ins by Microsoft printer drivers.

All of the functions pointed to by members of this structure are obsolete. For more information about each, see the following topics:

[**DrvWriteSpoolBuf**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvwritespoolbuf)

[**DrvXMoveTo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvxmoveto)

[**DrvYMoveTo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvymoveto)

[**DrvGetDriverSetting**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvgetdriversetting)

[**DrvGetStandardVariable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvgetstandardvariable) (for information about BGetStandardVariable)

[**DrvUnidriverTextOut**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvunidrivertextout)

[**DrvWriteAbortBuf**](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfn_drvwriteabortbuf)

## Members

### `DrvWriteSpoolBuf`

Defines the **PFN_DrvWriteSpoolBuf** member **DrvWriteSpoolBuf**.

### `DrvXMoveTo`

Defines the **PFN_DrvXMoveTo** member **DrvXMoveTo**.

### `DrvYMoveTo`

Defines the **PFN_DrvYMoveTo** member **DrvYMoveTo**.

### `DrvGetDriverSetting`

Defines the **PFN_DrvGetDriverSetting** member **DrvGetDriverSetting**.

### `BGetStandardVariable`

Defines the **PFN_DrvGetStandardVariable** member **BGetStandardVariable**.

### `DrvUnidriverTextOut`

Defines the **PFN_DrvUnidriverTextOut** member **DrvUnidriverTextOut**.

### `DrvWriteAbortBuf`

Defines the **PFN_DrvWriteAbortBuf** member **DrvWriteAbortBuf**.