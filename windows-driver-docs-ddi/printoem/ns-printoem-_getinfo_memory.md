## Description

The **GETINFO_MEMORY** structure is used as input to the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Members

### `dwSize`

Specifies the size, in bytes, of the **GETINFO_MEMORY** structure. Supplied by the [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) caller.

### `dwRemainingMemory`

Specifies the amount, in bytes, of currently available printer memory. Supplied by Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## Remarks

To obtain Unidrv's calculation of the amount of printer memory currently available, a rendering plug-in can supply the address of a **GETINFO_MEMORY** structure when calling Unidrv's [UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo) callback function.

## See also

[UNIFONTOBJ_GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/printoem/nc-printoem-pfngetinfo)