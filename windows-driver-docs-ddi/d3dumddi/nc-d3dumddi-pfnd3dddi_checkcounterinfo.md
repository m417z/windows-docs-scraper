# PFND3DDDI_CHECKCOUNTERINFO callback function

## Description

Called by the Microsoft Direct3D runtime to determine global information that's related to manipulating counters. Must be implemented by Windows Display Driver Model (WDDM) 1.3 and later user-mode display drivers.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pCounterInfo* [out]

A pointer to a [D3DDDIARG_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_counter_info) structure that the driver populates with global information that's related to manipulating counters.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code. For more information about setting error codes, see the following Remarks section.

This function should behave similarly to the [CheckCounterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo) function that supports Microsoft Direct3D 10 and later.

If the user-mode display driver does not support any of the concepts that are represented in the members of the [D3DDDIARG_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_counter_info) structure, it can populate the members of **D3DDDIARG_COUNTER_INFO** with zeros.

The driver's *pfnCheckCounterInfo* function cannot call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the **D3DDDIERR_DEVICEREMOVED** error code because *pfnCheckCounterInfo* is a capability-check type of function. The driver must ensure that it has enough information after device creation to respond to a call to *pfnCheckCounterInfo*, even in the presence of **D3DDDIERR_DEVICEREMOVED**. *pfnCheckCounterInfo* should not encounter any errors. However, *pfnCheckCounterInfo* might call **pfnSetErrorCb** for critical errors.

## See also

[CheckCounterInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_checkcounterinfo)

[D3DDDIARG_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-d3dddiarg_counter_info)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)