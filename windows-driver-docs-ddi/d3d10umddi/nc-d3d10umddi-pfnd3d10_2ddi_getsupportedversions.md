# PFND3D10_2DDI_GETSUPPORTEDVERSIONS callback function

## Description

The *GetSupportedVersions* function queries for the Direct3D interface versions that the driver supports.

## Parameters

### `unnamedParam1`

*hAdapter* [in]

A handle that identifies the graphics adapter.

### `puEntries`

A pointer to a variable that, on input, contains the number of entries that the *pSupportedDDIInterfaceVersions* array should return and, on output, the number of entries that the *pSupportedDDIInterfaceVersions* array actually returns.

### `pSupportedDDIInterfaceVersions`

A pointer to a block of memory that receives the array of Direct3D interface versions that the driver supports.

## Return value

*GetSupportedVersions* returns one of the following values:

| **Return code** | **Description** |
|:--|:--|
| **S_OK** | The capabilities are successfully retrieved. |
| **E_OUTOFMEMORY** | GetSupportedVersions could not allocate memory that is required for it to complete. |

## Remarks

When the Direct3D runtime calls the driver's [OpenAdapter10_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter) function, the **Interface** and **Version** members of the [D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter) structure contain the DDI version that the runtime uses to instantiate the driver. The driver can completely ignore these members. The driver can instead return capabilities and version information out through its *GetSupportedVersions* function.

## See also

[D3D10DDIARG_OPENADAPTER](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_openadapter)

[D3D10_2DDI_ADAPTERFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10_2ddi_adapterfuncs)

[OpenAdapter10_2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_openadapter)