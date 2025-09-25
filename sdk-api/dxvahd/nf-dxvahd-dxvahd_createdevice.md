# DXVAHD_CreateDevice function

## Description

Creates a Microsoft DirectX Video Acceleration High Definition (DXVA-HD) device.

## Parameters

### `pD3DDevice` [in]

A pointer to the [IDirect3DDevice9Ex](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex) interface of a Direct3D 9 device.

### `pContentDesc` [in]

A pointer to a [DXVAHD_CONTENT_DESC](https://learn.microsoft.com/windows/desktop/api/dxvahd/ns-dxvahd-dxvahd_content_desc) structure that describes the video content. The driver uses this information as a hint when it creates the device.

### `Usage` [in]

A member of the [DXVAHD_DEVICE_USAGE](https://learn.microsoft.com/windows/desktop/api/dxvahd/ne-dxvahd-dxvahd_device_usage) enumeration, describing how the device will be used. The value indicates the desired trade-off between speed and video quality. The driver uses this flag as a hint when it creates the device.

### `pPlugin` [in]

A pointer to an initialization function for a software device. Set this pointer if you are using a software plug-in device. Otherwise, set this parameter to **NULL**. If the value is **NULL**, the driver creates the DXVA-HD device.

The function pointer type is [PDXVAHDSW_Plugin](https://learn.microsoft.com/windows/desktop/api/dxvahd/nc-dxvahd-pdxvahdsw_plugin).

### `ppDevice` [out]

Receives a pointer to the [IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device) interface. The caller must release the interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_NOINTERFACE** | The Direct3D device does not support DXVA-HD. |

## Remarks

Use the [IDXVAHD_Device](https://learn.microsoft.com/windows/desktop/api/dxvahd/nn-dxvahd-idxvahd_device) interface to get the device capabilities, create the video processor, and allocate video surfaces.

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)