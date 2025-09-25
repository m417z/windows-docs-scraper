# _D3DHAL_CALLBACKS3 structure

## Description

D3DHAL_CALLBACKS3 is one of several callback structures that describe the Direct3D support provided by the driver.

## Members

### `dwSize`

Specifies the size in bytes of this structure.

### `dwFlags`

Indicates the callbacks associated with this structure that the driver has implemented. For every bit the driver sets in **dwFlags**, the driver must initialize the corresponding function pointer member of this structure. This member can be the bitwise-OR of one or more of the following flags:

| **Flag** | **Meaning** |
|:--|:--|
| D3DHAL3_CB32_CLEAR2 | Not used in DirectX 7.0 and later versions. |
| D3DHAL3_CB32_DRAWPRIMITIVES2 | The DrawPrimitives2member points to a driver-implemented [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback. |
| D3DHAL3_CB32_RESERVED | Not used in DirectX 7.0 and later versions. |
| D3DHAL3_CB32_VALIDATETEXTURESTAGESTATE | The ValidateTextureStageStatemember points to a driver-implemented [D3dValidateTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_validatetexturestagestatecb) callback. |

### `Clear2`

Must be set to **NULL**. This was a pointer to the driver-supplied **D3dClear2** callback that is no longer used for DirectX 7.0 and beyond. Instead the driver should respond to the D3DDP2OP_CLEAR command stream token in its implementation of [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb).

### `lpvReserved`

Specifies a reserved field and must be set to **NULL** in a Windows 2000 and later driver.

### `ValidateTextureStageState`

Points to the driver-supplied [D3dValidateTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_validatetexturestagestatecb) callback, or **NULL**. Drivers that support multitexturing must implement the callback that this member points to.

### `DrawPrimitives2`

Points to the driver-supplied [D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb) callback. A driver must implement the callback that this member points to.

## Remarks

The driver allocates this structure and sets appropriate values in all members. The driver's [DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo) function returns a pointer to this structure when that function is called with the GUID_D3DCallbacks3 GUID.

## See also

D3DDP2OP_CLEAR

[D3DHAL_CALLBACKS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/ns-d3dhal-_d3dhal_callbacks)

[D3dDrawPrimitives2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_drawprimitives2cb)

[D3dValidateTextureStageState](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dhal/nc-d3dhal-lpd3dhal_validatetexturestagestatecb)

[DdGetDriverInfo](https://learn.microsoft.com/windows/win32/api/ddrawint/nc-ddrawint-pdd_getdriverinfo)