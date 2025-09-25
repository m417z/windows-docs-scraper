# IMFVideoSampleAllocator::SetDirectXManager

## Description

Specifies the Direct3D device manager for the video media sink to use.

## Parameters

### `pManager` [in]

Pointer to the **IUnknown** interface of the Direct3D device manager. The media sink queries this pointer for the [IDirect3DDeviceManager9](https://learn.microsoft.com/windows/desktop/api/dxva2api/nn-dxva2api-idirect3ddevicemanager9) interface.

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |

## Remarks

The media sink uses the Direct3D device manager to obtain a pointer to the Direct3D device, which it uses to allocate Direct3D surfaces. The device manager enables multiple objects in the pipeline (such as a video renderer and a video decoder) to share the same Direct3D device.

## See also

[IMFVideoSampleAllocator](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfvideosampleallocator)