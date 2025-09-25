# PFND3D10DDI_RESOURCEMAP callback function

## Description

The *ResourceMap* function maps a subresource of a resource.

## Parameters

### `unnamedParam1`

*hDevice* [in]

A handle to the display device (graphics context).

### `unnamedParam2`

*hResource* [in]

A handle to the resource to map.

### `unnamedParam3`

*Subresource* [in]

An index that indicates the subresource to map.

### `unnamedParam4`

*DDIMap* [in]

A [D3D10_DDI_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map)-typed value that indicates the access level to map the subresource to.

### `unnamedParam5`

*Flags* [in]

A [D3D10_DDI_MAP_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map_flag)-typed value that indicates how to map the subresource.

### `unnamedParam6`

*pMappedSubResource* [out]

A pointer to a [D3D10DDI_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_mapped_subresource) structure that receives the information about the mapped subresource.

## Remarks

The driver can use the [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) callback function to set an error code.

The driver can call [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to set the D3DDDIERR_DEVICEREMOVED error code.

Typically, immediately after the runtime receives the D3DDDIERR_DEVICEREMOVED error code, the runtime will no longer call into the user-mode display driver for much (other than for unbinding, destruction, and other cleanup operations).

Typically, each call to the user-mode display driver's *ResourceMap* function is accompanied with a call to the driver's [ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap) function; however, after the runtime receives the D3DDDIERR_DEVICEREMOVED error code, it will not call *ResourceUnmap*.

If the runtime passed the D3D10_DDI_MAP_FLAG_DONOTWAIT flag in the *Flags* parameter, the driver can call [pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb) to set the DXGI_DDI_ERR_WASSTILLDRAWING error code.

The driver can implement one pair of *ResourceMap* and *ResourceUnmap* functions that can contain **switch** statements to process various functionalities. That is, the driver can implement one *ResourceMap*-*ResourceUnmap* pair and can set the following members of the [D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs) structure to point to this implementation pair:

* pfnDynamicIABufferMapDiscard-pfnDynamicIABufferUnmap

* pfnDynamicIABufferMapNoOverwrite-pfnDynamicIABufferUnmap

* pfnDynamicConstantBufferMapDiscard-pfnDynamicConstantBufferUnmap

* pfnDynamicResourceMapDiscard-pfnDynamicResourceUnmap

* pfnStagingResourceMap-pfnStagingResourceUnmap

However, to improve performance, the driver can implement separate map-unmap function pairs. The Microsoft Direct3D runtime calls the appropriate map-unmap function pair depending on the resource type (for example, a buffer or texture) and the type of [D3D10_DDI_RESOURCE_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage), [D3D10_DDI_RESOURCE_BIND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag), and [D3D10_DDI_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map) values that are specified when the resource is created and mapped.

> [!NOTE]
> If the resource type to map and unmap is a buffer, the Direct3D runtime sets the *Subresource* parameter to zero.\
Although the Direct3D runtime typically calls the **pfnDynamicResourceMapDiscard**-**pfnDynamicResourceUnmap** function pair for dynamic textures, the runtime also calls this function pair for dynamic buffers that were created with the D3D10_DDI_BIND_SHADER_RESOURCE bind flag set.

The following example code shows the values that are set when the Direct3D runtime calls specific map or unmap function:

```cpp
//-----------------------------------------------
void APIENTRY UMDevice::DynamicIABufferMapNoOverwrite_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.ResourceDimension == D3D10DDIRESOURCE_BUFFER &&
        pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        (pResource->m_DDICreateResource.BindFlags & (D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        !(pResource->m_DDICreateResource.BindFlags & ~(D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        Subresource == 0 &&
        MapType == D3D10_DDI_MAP_WRITE_NOOVERWRITE &&
        MapFlags == 0 );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicIABufferMapDiscard_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.ResourceDimension == D3D10DDIRESOURCE_BUFFER &&
        pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        (pResource->m_DDICreateResource.BindFlags & (D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        !(pResource->m_DDICreateResource.BindFlags & ~(D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        Subresource == 0 &&
        MapType == D3D10_DDI_MAP_WRITE_DISCARD &&
        MapFlags == 0 );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicIABufferUnmap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.ResourceDimension == D3D10DDIRESOURCE_BUFFER &&
        pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        (pResource->m_DDICreateResource.BindFlags & (D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        !(pResource->m_DDICreateResource.BindFlags & ~(D3D10_DDI_BIND_VERTEX_BUFFER | D3D10_DDI_BIND_INDEX_BUFFER)) &&
        Subresource == 0 );

    pResource->Unmap( Subresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicConstantBufferMapDiscard_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.ResourceDimension == D3D10DDIRESOURCE_BUFFER &&
        pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        (pResource->m_DDICreateResource.BindFlags & D3D10_DDI_BIND_CONSTANT_BUFFER) &&
        !(pResource->m_DDICreateResource.BindFlags & ~D3D10_DDI_BIND_CONSTANT_BUFFER) &&
        Subresource == 0 &&
        MapType == D3D10_DDI_MAP_WRITE_DISCARD &&
        MapFlags == 0 );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicConstantBufferUnmap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.ResourceDimension == D3D10DDIRESOURCE_BUFFER &&
        pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        (pResource->m_DDICreateResource.BindFlags & D3D10_DDI_BIND_CONSTANT_BUFFER) &&
        !(pResource->m_DDICreateResource.BindFlags & ~D3D10_DDI_BIND_CONSTANT_BUFFER) &&
        Subresource == 0 );

    pResource->Unmap( Subresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicResourceMapDiscard_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        pResource->m_DDICreateResource.Subresources == 1 &&
        Subresource == 0 &&
        MapType == D3D10_DDI_MAP_WRITE_DISCARD &&
        MapFlags == 0 );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::DynamicResourceUnmap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_DYNAMIC &&
        pResource->m_DDICreateResource.Subresources == 1 &&
        Subresource == 0 );

    pResource->Unmap( Subresource );
}

//------------------------------------------------
void APIENTRY UMDevice::StagingResourceMap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_STAGING &&
        (MapType == D3D10_DDI_MAP_READ || MapType == D3D10_DDI_MAP_WRITE || MapType == D3D10_DDI_MAP_READWRITE) );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::StagingResourceUnmap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage == D3D10_DDI_USAGE_STAGING );

    pResource->Unmap( Subresource );
}

//------------------------------------------------
void APIENTRY UMDevice::ResourceMap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource,
    D3D10_DDI_MAP MapType,
    UINT MapFlags,
    D3D10DDI_MAPPED_SUBRESOURCE* pMappedSubresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage != D3D10_DDI_USAGE_DYNAMIC &&
        pResource->m_DDICreateResource.Usage != D3D10_DDI_USAGE_STAGING );

    // Generally true; but allow last second change:
    assert( false );

    pResource->Map( Subresource, MapType, MapFlags, pMappedSubresource );
}

//------------------------------------------------
void APIENTRY UMDevice::ResourceUnmap_Default(
    D3D10DDI_HDEVICE hDevice,
    D3D10DDI_HRESOURCE hResource,
    UINT Subresource )
{
    UMDevice* pThis = UMDevice::CastFrom( hDevice );
    UMResource* pResource = UMResource::CastFrom( hResource );

    assert( pResource->m_DDICreateResource.Usage != D3D10_DDI
_USAGE_DYNAMIC &&
        pResource->m_DDICreateResource.Usage != D3D10_DDI_USAGE_STAGING );

    // Generally true; but allow last second change:
    assert( false );

    pResource->Unmap( Subresource );
}
```

### Restrictions on input values

For Windows Display Driver Model (WDDM) 1.3 and later drivers, the Microsoft Direct3D runtime supplies a restricted set of input values used by this function. For a list of all restricted values, see [Direct3D rendering performance improvements](https://learn.microsoft.com/windows-hardware/drivers/display/direct3d-rendering-performance-improvements).

## See also

[D3D10DDI_DEVICEFUNCS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_devicefuncs)

[D3D10DDI_MAPPED_SUBRESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddi_mapped_subresource)

[D3D10_DDI_MAP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map)

[D3D10_DDI_MAP_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_map_flag)

[D3D10_DDI_RESOURCE_BIND_FLAG](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_bind_flag)

[D3D10_DDI_RESOURCE_USAGE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ne-d3d10umddi-d3d10_ddi_resource_usage)

[ResourceUnmap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceunmap)

[pfnSetErrorCb](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_seterror_cb)