# _DXGK_MONITORDESCRIPTORSET_INTERFACE structure

## Description

The DXGK_MONITORDESCRIPTORSET_INTERFACE structure contains pointers to functions that belong to the Monitor descriptor set interface, which is implemented by the [video present network (VidPN) manager](https://learn.microsoft.com/windows-hardware/drivers/display/vidpn-objects-and-interfaces).

## Members

### `pfnGetNumDescriptors`

A pointer to the [pfnGetNumDescriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_getnumdescriptors) function.

### `pfnAcquireFirstDescriptorInfo`

A pointer to the [pfnAcquireFirstDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirefirstdescriptorinfo) function.

### `pfnAcquireNextDescriptorInfo`

A pointer to the [pfnAcquireNextDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirenextdescriptorinfo) function.

### `pfnReleaseDescriptorInfo`

A pointer to the [pfnReleaseDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_releasedescriptorinfo) function.

## See also

[pfnAcquireFirstDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirefirstdescriptorinfo)

[pfnAcquireNextDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_acquirenextdescriptorinfo)

[pfnGetNumDescriptors](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_getnumdescriptors)

[pfnReleaseDescriptorInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmddi/nc-d3dkmddi-dxgkddi_monitordescriptorset_releasedescriptorinfo)