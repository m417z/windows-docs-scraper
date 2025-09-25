# PFND3DDDI_CREATEQUERY callback function

## Description

The **CreateQuery** function creates driver-side resources for a query that the Microsoft Direct3D runtime subsequently issues for processing.

## Parameters

### `hDevice`

A handle to the display device (graphics context).

### `unnamedParam2`

*pData* [in, out]

A pointer to a [D3DDDIARG_CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) structure that identifies the query.

## Return value

**CreateQuery** returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The query is successfully created. |
| **E_OUTOFMEMORY** | [CreateQuery]() could not allocate the required memory for it to complete. |

## Remarks

The Direct3D runtime calls the user-mode display driver's **CreateQuery** function with a query type to create resources for a query. The user-mode display driver creates the following resources for query types:

* BOOL for D3DDDIQUERYTYPE_EVENT. Before responding about an event, the driver must ensure that the graphics processing unit (GPU) is finished processing all of the operations that are related to the event. That is, the driver responds about an event after the issue end state occurs. The driver must always set the event's BOOL value to **TRUE** when responding.
* UINT for D3DDDIQUERYTYPE_OCCLUSION. The driver sets this UINT variable to the number of pixels for which the z-test passed for all of the primitives between the beginning and end states of the issue query. If the depth buffer is multisampled, the driver determines the number of pixels from the number of samples. However, if the display device is capable of z-test accuracy for each multisample, the conversion to number of pixels should generally be rounded up. An application can then check the occlusion result against 0, to effectively mean "fully occluded." Drivers that convert multisampled quantities to pixel quantities should detect render target multisampling changes and continue to compute the query results appropriately.
* A [D3DDDIDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddidevinfo_vcache) structure for D3DDDIQUERYTYPE_VCACHE. The driver responds after the issue end state occurs.

For more information about issue query states, see [D3DDDI_ISSUEQUERYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_issuequeryflags).

## See also

[D3DDDIARG_CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery)

[D3DDDIDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddidevinfo_vcache)

[D3DDDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicefuncs)

[D3DDDI_ISSUEQUERYFLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_issuequeryflags)