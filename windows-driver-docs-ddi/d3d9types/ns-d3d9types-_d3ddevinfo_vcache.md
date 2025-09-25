# _D3DDEVINFO_VCACHE structure

## Description

 DirectX 8.1 and later versions only.

The D3DDEVINFO_VCACHE structure describes vertex-cache information of a device.

## Members

### `Pattern`

Specifies the bit pattern. The driver must specify the bit pattern as the CACH four-character code (FOURCC) value. The driver can use the MAKEFOURCC macro as follows to specify the FOURCC value as CACH:

```cpp
MAKEFOURCC('C', 'A', 'C', 'H');
```

### `OptMethod`

Specifies the method of mesh optimization. The driver can use one of the following values to specify the mesh optimization that it uses:

|Value|Meaning|
|--- |--- |
|D3DXMESHOPT_STRIPREORDER (0)|Longest strips optimization|
|D3DXMESHOPT_VCACHE (1)|Vertex-cache based optimization|

### `CacheSize`

Specifies the effective size, in entries, for which the driver optimizes the vertex cache. The actual cache size is not required to be the size specified in **CacheSize** because in most cases the actual cache size turns out to be larger. The driver only specifies an optimized size in **CacheSize** if it also specifies D3DXMESHOPT_VCACHE in the **OptMethod** member.

### `MagicNumber`

Specifies the number that should be used as part of a trial-and-error procedure when determining when to restart the strips list. This number can be set from 1 to the value in the **CacheSize** member. Typically, the best values are near **CacheSize**/2.

## Remarks

**DirectX 8.1 versions only.** The Direct3D runtime calls a driver's [D3dGetDriverState](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverstate) function to obtain vertex-cache information from the driver. In this **D3dGetDriverState** call, the runtime specifies the D3DDEVINFOID_VCACHE flag in the **dwFlags** member of the DD_GETDRIVERSTATEDATA structure that the runtime passes. The driver specifies vertex-cache information in a D3DDEVINFO_VCACHE structure and returns it at the **lpdwStates** member of DD_GETDRIVERSTATEDATA.

**DirectX 9.0 and later versions only.** The Direct3D runtime specifies D3DDP2OP_CREATEQUERY and D3DDP2OP_ISSUEQUERY commands in calls to the driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback to create driver-side resources for the query and then to asynchronously query the driver for vertex-cache information. In the call with the D3DDP2OP_CREATEQUERY command, the runtime specifies the D3DQUERYTYPE_VCACHE query type in the **QueryType** member of the [D3DHAL_DP2CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createquery) structure.

When the driver completes a vertex-cache query, the driver sets the total size of the response buffer in the dwErrorOffset member of the [D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data) structure and sets the **ddrval** member of D3DHAL_DRAWPRIMITIVES2DATA to D3D_OK for successful completion. The driver also overwrites the incoming command buffer with the outgoing response buffer. This response buffer contains a [D3DHAL_DP2RESPONSEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2responsequery) structure that identifies a response for the vertex-cache query. This D3DHAL_DP2RESPONSEQUERY is followed by the vertex-cache data in the D3DDEVINFO_VCACHE structure.

## See also

D3DDP2OP_CREATEQUERY

D3DDP2OP_ISSUEQUERY

[D3DHAL_DP2CREATEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2createquery)

[D3DHAL_DP2RESPONSEQUERY](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_dp2responsequery)

[D3DHAL_DRAWPRIMITIVES2DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_drawprimitives2data)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[D3dGetDriverState](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverstate)