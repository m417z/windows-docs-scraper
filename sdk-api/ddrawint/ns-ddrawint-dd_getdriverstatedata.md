# DD_GETDRIVERSTATEDATA structure

## Description

The DD_GETDRIVERSTATEDATA structure describes the state of the driver.

## Members

### `dwFlags`

Specifies the set of flags to indicate the data requested. This parameter can be set to one of the following flags:

| Flag | Meaning |
| --- | --- |
| D3DDEVINFOID_D3DTEXTUREMANAGER | Requests texture-management information performed by the Direct3D runtime in a D3DDEVINFO_TEXTUREMANAGER structure. |
| D3DDEVINFOID_TEXTUREMANAGER | Requests texture-management information performed by either the driver or the Direct3D runtime in a D3DDEVINFO_TEXTUREMANAGER structure. |
| D3DDEVINFOID_TEXTURING | Requests texture-activity information of the application in a D3DDEVINFO_TEXTURING structure. |
| D3DDEVINFOID_VCACHE | DirectX 8.1 versions only<br><br>Requests vertex-cache information in a D3DDEVINFO_VCACHE structure. |

### `lpDD`

Points to a [DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global) structure describing the device.

### `dwhContext`

Specifies the ID of the context that information is being requested for.

### `lpdwStates`

Points to the Direct3D driver state data to be filled in by the driver. If, for example, D3DDEVINFOID_VCACHE is specified in the **dwFlags** member, the driver points the **lpdwStates** member to a D3DDEVINFO_VCACHE structure that contains vertex-cache information.

### `dwLength`

Specifies the length, in bytes, of the state data to be filled in by the driver.

### `ddRVal`

Specifies the location where the driver writes the return value of the [D3dGetDriverState](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverstate) callback. A return code of D3D_OK indicates success. For more information, see [Return Codes for Direct3D Driver Callbacks](https://learn.microsoft.com/windows-hardware/drivers/display/return-codes-for-direct3d-driver-callbacks).

## Remarks

Applications can use the **IDirect3DDevice7::GetInfo** method and specify the D3DDEVINFOID_D3DTEXTUREMANAGER, D3DDEVINFOID_TEXTUREMANAGER, and D3DDEVINFOID_TEXTURING flags to retrieve texturing information. For more information about this method and the structures related to these flags, see the DirectX SDK documentation. The runtime then passes these flags to the driver.

**DirectX 8.1 versions only.**The Direct3D runtime specifies the D3DDEVINFOID_VCACHE flag in the **dwFlags** member to retrieve vertex-cache information from the driver specified at the **lpDD** member. The driver specifies this information in a D3DDEVINFO_VCACHE structure and returns it at the **lpdwStates** member.

**DirectX 9.0 and later versions only.** The Direct3D runtime asynchronously queries the driver for vertex-cache information by using the D3DDP2OP_CREATEQUERY and D3DDP2OP_ISSUEQUERY commands and the D3DQUERYTYPE_VCACHE query type in calls to the driver's [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback. For more information, see [D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3d9types/ns-d3d9types-_d3ddevinfo_vcache).

**Note** The D3DDEVINFOID_VCACHE flag is defined in d3dhal.h; the other flags that can be set in **dwFlags** are defined in d3dtypes.h.

## See also

[D3DDEVINFO_VCACHE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3d9types/ns-d3d9types-_d3ddevinfo_vcache)

D3DDP2OP_CREATEQUERY

D3DDP2OP_ISSUEQUERY

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[D3dGetDriverState](https://learn.microsoft.com/windows/desktop/api/ddrawint/nc-ddrawint-pdd_getdriverstate)

[DD_DIRECTDRAW_GLOBAL](https://learn.microsoft.com/windows/desktop/api/ddrawint/ns-ddrawint-dd_directdraw_global)