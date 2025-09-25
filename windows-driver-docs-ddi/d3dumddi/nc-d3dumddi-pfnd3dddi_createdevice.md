# PFND3DDDI_CREATEDEVICE callback function

## Description

The **CreateDevice** function creates a graphics context that is referenced in subsequent calls.

## Parameters

### `hAdapter`

A handle that identifies the graphics adapter.

### `unnamedParam2`

*pCreateData* [in, out]

A pointer to a [D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice) structure. On input, this structure contains information that the driver can use. On output, the driver specifies information in the structure that the Microsoft Direct3D runtime can use.

## Return value

**CreateDevice** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The graphics context is successfully created. |
| **E_OUTOFMEMORY** | [CreateDevice]() could not allocate the memory that was required for it to complete. |

## Remarks

A display device is a graphics context that is used to hold a collection of rendering state. Multiple devices can be created by the same process on a given adapter. Note that the number of display devices that can simultaneously exist is limited only by available system memory. That is, a driver cannot hardcode a maximum device limit.

Generally, devices are independent of each other, so that resources that are created in one device cannot be referenced or accessed by resources that are created in another. However, cross-process resources are an exception to this rule.

When the Direct3D runtime calls **CreateDevice** to create a device, the runtime does not create a default graphics processing unit (GPU) context thread of execution for the device. The driver must explicitly call the [pfnCreateContextCb](https://learn.microsoft.com/previous-versions/ff568895(v=vs.85)) function to create one or more contexts as required.

## See also

[D3DDDIARG_CREATEDEVICE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createdevice)

[D3DDDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_adapterfuncs)

[DestroyDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_destroydevice)