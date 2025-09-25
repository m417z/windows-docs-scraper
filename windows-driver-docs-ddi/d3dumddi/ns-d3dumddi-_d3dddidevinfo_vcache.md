# _D3DDDIDEVINFO_VCACHE structure

## Description

The D3DDDIDEVINFO_VCACHE structure describes the vertex-cache information of a device.

## Members

### `Pattern` [out]

The bit pattern. The driver must specify the bit pattern as a CACH four-character code (FOURCC) value. The driver can use the following MAKEFOURCC macro to specify the FOURCC value as CACH:

```cpp
MAKEFOURCC('C', 'A', 'C', 'H');
```

### `OptMethod` [out]

The method of mesh optimization. The driver can use one of the following values to specify the mesh optimization that it uses.

| **Value** | **Meaning** |
|:--|:--|
| D3DXMESHOPT_STRIPREORDER (0) | Longest strips optimization |
| D3DXMESHOPT_VCACHE (1) | Vertex-cache-based optimization |

### `CacheSize` [out]

The effective size, in entries, that the driver optimizes the vertex cache for. The actual cache size is not required to be the size that is specified in **CacheSize** because the actual cache size is larger in most situations. The driver specifies an optimized size in **CacheSize** only if it also specifies D3DXMESHOPT_VCACHE in the **OptMethod** member.

### `MagicNumber` [out]

The number that should be used as part of a trial-and-error procedure when determining when to restart the strips list. This number can be from 1 to the value that is specified in the **CacheSize** member. Typically, the best values are near **CacheSize**/2. The driver specifies a number in **MagicNumber** only if it also specifies D3DXMESHOPT_VCACHE in the **OptMethod** member.

## Remarks

**Direct3D runtime version 9.0 and later.** The Microsoft Direct3D runtime calls the driver's [CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery) function to create driver-side resources for the vertex-cache query. In this **CreateQuery** call, the runtime specifies the D3DDDIQUERYTYPE_VCACHE query type in the **QueryType** member of the [D3DDDIARG_CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery) structure. The driver should allocate a D3DDDIDEVINFO_VCACHE structure. The runtime then calls the driver's [IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery) function to process the vertex-cache query. The driver should insert a graphics processing unit (GPU) instruction to write the vertex-cache data to an allocation. To retrieve the vertex-cache information from the driver, the runtime calls the driver's [GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata) function. In this **GetQueryData** call, the driver should lock the allocation and return the vertex-cache data at the **pData** member of the [D3DDDIARG_GETQUERYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getquerydata) structure that is pointed to by the *pData* parameter.

**Direct3D runtime version 8.1 only.** The Direct3D runtime calls the driver's [GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo) function to obtain vertex-cache information from the driver. In this **GetInfo** call, the runtime passes the D3DDDIDEVINFOID_VCACHE flag in the *DevInfoID* parameter. The driver specifies vertex-cache information in a D3DDDIDEVINFO_VCACHE structure and returns it at the *pDevInfoStruct* parameter.

## See also

[CreateQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_createquery)

[D3DDDIARG_CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_createquery)

[D3DDDIARG_GETQUERYDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getquerydata)

[GetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfinterrupt-getinfo)

[GetQueryData](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getquerydata)

[IssueQuery](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_issuequery)