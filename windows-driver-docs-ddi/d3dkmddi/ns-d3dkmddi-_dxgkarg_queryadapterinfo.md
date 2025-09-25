# DXGKARG_QUERYADAPTERINFO structure

## Description

The **DXGKARG_QUERYADAPTERINFO** structure contains parameters for a [**DxgkDdiQueryadapterinfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo) query.

## Members

### `Type` [in]

A [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)-typed value that indicates the type of information to retrieve. This value determines what **pInputData** and **pOutputData** point to.

### `pInputData` [in]

A pointer to input information for the query. The following table describes the input buffer for **Type** values requiring input. Other types don't require input, so **pInputData** is NULL.

| Value of **Type** | Contents of **pInputData** |
| --- | --- |
| DXGKQAITYPE_UMDRIVERPRIVATE | A proprietary buffer that contains information about the query. |
| DXGKQAITYPE_QUERYSEGMENT | A [**DXGK_QUERYSEGMENTIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_querysegmentin) structure. |
| DXGKQAITYPE_POWERCOMPONENTINFO | Buffer containing the power component index. |
| DXGKQAITYPE_DIRTYBITTRACKINGSEGMENTCAPS | Buffer containing the driver's segment ID. The driver should fill out the output caps for this particular segment. |
| DXGKQAITYPE_SCATTER_RESERVE | A [**DXGK_QUERYSCATTERRESERVEIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-dxgk_queryscatterreservein) structure. |
| DXGKQAITYPE_PAGINGPROCESSGPUVASIZE | A UNIT value that specifies the physical adapter index in an LDA configuration. It's set to zero for non-LDA configurations. |

### `InputDataSize` [in]

The size, in bytes, of the input data that **pInputData** points to.

### `pOutputData` [out]

A pointer to an output buffer that the display miniport driver fills with the required information. See [**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype) for the type of structure that **pOutputData** points to.

### `OutputDataSize` [in]

The size, in bytes, of the output data that **pOutputData** points to.

### `Flags` [in]

A set of [**DXGK_QUERYADAPTERINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_queryadapterinfoflags)-typed flags that indicates the query of graphics information. Supported starting with Windows 10, version 1803 (WDDM 2.4).

### `hKmdProcessHandle` [in]

A handle, return by the KMD from [**DxgkDdiCreateProcess**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_createprocess). The driver must check the value for NULL. Note that **hKmdProcessHandle** is created when the first DXG device is created for the adapter, and destroyed when the last adapter handle in the process is closed.

## See also

[**DXGK_DRIVERCAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_drivercaps)

[**DXGK_QUERYADAPTERINFOFLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ns-d3dkmddi-_dxgk_queryadapterinfoflags)

[**DXGK_QUERYADAPTERINFOTYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/ne-d3dkmddi-_dxgk_queryadapterinfotype)

[**DxgkDdiQueryAdapterInfo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_queryadapterinfo)