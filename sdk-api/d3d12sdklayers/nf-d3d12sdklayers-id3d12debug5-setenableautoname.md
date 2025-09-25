## Description

Configures the auto-naming of objects.

## Parameters

### `Enable`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

`true` to enable auto-naming; `false` to disable auto-naming.

## Remarks

By default, objects are not named unless you use [ID3D12Object::SetName](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setname) or [ID3D12Object::SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setprivatedata) to assign a name.

It's a best practice to name all of your Direct3D 12 objects; at least in debug builds. Failing that, you might find it convenient to allow automatic name assignment in order to cover the gaps. Direct3D 12 objects created with auto-name enabled are automatically assigned a name, which is used for debug layer output and for DRED page fault data.

So as not to create a dependency on a specific auto-naming format, you can't retrieve the auto-name strings by using ID3D12Object::GetName or [ID3D12Object::GetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-getprivatedata). But, to generate a unique name string, Direct3D 12 uses the locally-unique identifier (LUID) assigned to every **ID3D12DeviceChild** object at create time. You can retrieve that LUID by using **ID3D12Object::GetPrivateData** with the **REFGUID** value *WKPDID_D3D12UniqueObjectId*. You might find that useful for your own object-naming schemas.

When debugging existing software, you can control auto-naming by using the *D3DConfig* graphics tools utility and the command `d3dconfig.exe device auto-debug-name=forced-on`.

Any object given a name using [ID3D12Object::SetName](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setname) or [ID3D12Object::SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12object-setprivatedata) uses the assigned name instead of the auto-name.

## See also

* [ID3D12Debug5](https://learn.microsoft.com/windows/win32/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug5)