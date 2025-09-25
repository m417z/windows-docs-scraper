# D3D12DDIARG_CREATEDEVICE_0003 structure

## Description

The **D3D12DDIARG_CREATEDEVICE_0003** structure describes the display device to create.

## Members

### `hRTDevice` [in]

A handle to the display device (graphics context) that specifies the handle that the driver should use when it calls back into the Direct3D runtime.

### `Interface` [in]

The Direct3D interface version.

### `Version` [in]

A UINT value that the driver can use to identify when the Direct3D runtime was built (the runtime version).

### `pKTCallbacks`

A pointer to a [**D3DDDI_DEVICECALLBACKS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddi_devicecallbacks) structure that contains a table of Direct3D runtime callback functions that the driver can use to access kernel services.

### `hDrvDevice`

 A handle to the display device (graphics context) that the Direct3D runtime uses in subsequent driver calls to identify the display device.

### `p12UMCallbacks`

 A pointer to a D3D12DDI_CORELAYER_DEVICECALLBACKS_0003 structure that contains a table of Direct3D runtime callback functions that the driver can use to access core user-mode runtime functionality.

### `p12UMCallbacks_0022`

A pointer to a [D3D12DDI_CORELAYER_DEVICECALLBACKS_0022](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0022) structure that contains a table of Direct3D runtime callback functions that the driver can use to access core user-mode runtime functionality.

### `p12UMCallbacks_0050`

A pointer to a [D3D12DDI_CORELAYER_DEVICECALLBACKS_0050](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0050) structure that contains a table of Direct3D runtime callback functions that the driver can use to access core user-mode runtime functionality.

### `p12UMCallbacks_0062`

A pointer to a [D3D12DDI_CORELAYER_DEVICECALLBACKS_0062](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_corelayer_devicecallbacks_0062) structure that contains a table of Direct3D runtime callback functions that the driver can use to access core user-mode runtime functionality.

### `Flags`

Flag values that identify how to create the display device.

## See also

[**PFND3D12DDI_CREATEDEVICE_0003**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_createdevice_0003)