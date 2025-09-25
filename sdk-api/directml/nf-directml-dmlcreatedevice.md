## Description

Creates a DirectML device for a given Direct3D 12 device.

## Parameters

### `d3d12Device`

Type: **[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)***

A pointer to an [ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device) representing the Direct3D 12 device to create the DirectML device over. DirectML supports any D3D feature level, and Direct3D 12 devices created on any adapter, including WARP. However, not all features in DirectML may be available depending on the capabilities of the Direct3D 12 device. See [IDMLDevice::CheckFeatureSupport](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-idmldevice-checkfeaturesupport) for more info.

If the call to **DMLCreateDevice** is successful, then the DirectML device maintains a strong reference to the supplied Direct3D 12 device.

### `flags`

Type: **DML_CREATE_DEVICE_FLAGS**

A [DML_CREATE_DEVICE_FLAGS](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_create_device_flags) value specifying additional device creation options.

### `riid`

Type: **REFIID**

A reference to the globally unique identifier (GUID) of the interface that you wish to be returned in *device*. This is expected to be the GUID of [IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice).

### `ppv`

Type: \_COM\_Outptr\_opt\_ **void****

A pointer to a memory block that receives a pointer to the device. This is the address of a pointer to an [IDMLDevice](https://learn.microsoft.com/windows/win32/api/directml/nn-directml-idmldevice), representing the DirectML device created.

## Return value

Type: [**HRESULT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

If the function succeeds, it returns **S_OK**. Otherwise, it returns an [HRESULT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types) error code.

## Remarks

A newer version of this function, [DMLCreateDevice1](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-dmlcreatedevice1), was introduced in DirectML version 1.1.0. **DMLCreateDevice** is equivalent to calling **DMLCreateDevice1** and supplying a *minimumFeatureLevel* of [DML_FEATURE_LEVEL_1_0](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_feature_level).

## See also

* [DMLCreateDevice1 function](https://learn.microsoft.com/windows/win32/api/directml/nf-directml-dmlcreatedevice1)
* [DirectML version history](https://learn.microsoft.com/windows/ai/directml/dml-version-history)
* [Using the DirectML debug layer](https://learn.microsoft.com/windows/ai/directml/dml-debug-layer)