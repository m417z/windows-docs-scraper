# PFND3D10DDI_CHECKCOUNTERINFO callback function

## Description

The **CheckCounterInfo** function determines global information that is related to manipulating counters.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*pCounterInfo* [out]

A pointer to a [D3D10DDI_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_counter_info) structure that the driver populates with global information that is related to manipulating counters.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

If the user-mode display driver does not support any of the concepts that are represented in the members of the [D3D10DDI_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_counter_info) structure, it can populate the members of D3D10DDI_COUNTER_INFO with zeros.

The driver's **CheckCounterInfo** function cannot call the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set the D3DDDIERR_DEVICEREMOVED error code because **CheckCounterInfo** is a capability-check type of function. The driver must ensure that it has enough information after device creation to respond to a call to **CheckCounterInfo**, even in the presence of D3DDDIERR_DEVICEREMOVED. **CheckCounterInfo** should not encounter any errors. However, **CheckCounterInfo** might call **pfnSetErrorCb** for critical errors.

## See also

[D3D10DDI_COUNTER_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_counter_info)

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)