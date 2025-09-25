# D3D10_DDI_RESOURCE_USAGE enumeration

## Description

The D3D10_DDI_RESOURCE_USAGE enumeration type contains values that identify how a resource is used.

## Constants

### `D3D10_DDI_USAGE_DEFAULT`

The resource is used at the highest level. An application cannot map to default resources. The resources can be bound to the graphics pipeline and used as copy destinations and sources. The Microsoft Direct3D runtime can call only the [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) function to update the contents directly with the CPU.

### `D3D10_DDI_USAGE_IMMUTABLE`

The resource is immutable and cannot be mapped or copied to. The resource can be bound to the pipeline and copied from. The Direct3D runtime cannot call [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup) to update the contents; therefore, the contents of the resource are provided at creation time.

### `D3D10_DDI_USAGE_DYNAMIC`

The resource is dynamic and should be resident in non-local video memory. The resource can also be mapped. However, when the resource is mapped, the CPU can only write (and not read) to the resource. Therefore, when mapped, the Direct3D runtime must use the D3D10_DDI_MAP_WRITE_DISCARD or D3D10_DDI_MAP_WRITE_NOOVERWRITE access level in a call to the [ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap) function. Because this resource can be mapped, the runtime cannot call [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup).

### `D3D10_DDI_USAGE_STAGING`

The resource is a staging resource, which the user-mode display driver should allocate as system memory. The driver allocates system memory to ensure the proper alignment and pitch to enable DMA access to such a region of memory. Staging can be mapped by the application but cannot be bound to the 3-D graphics pipeline. However, staging resources are frequently used to copy between other non-mappable resources. Because this resource can be mapped, the runtime cannot call [ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup).

## See also

[D3D10DDIARG_CREATERESOURCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/ns-d3d10umddi-d3d10ddiarg_createresource)

[ResourceMap](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourcemap)

[ResourceUpdateSubresourceUP](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d10umddi/nc-d3d10umddi-pfnd3d10ddi_resourceupdatesubresourceup)