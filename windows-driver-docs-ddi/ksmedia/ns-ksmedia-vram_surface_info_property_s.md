# VRAM_SURFACE_INFO_PROPERTY_S structure

## Description

The VRAM_SURFACE_INFO_PROPERTY_S structure describes property items in the KSPROPSETID_VramCapture property set.

## Members

### `Property`

This member specifies an initialized [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure that describes the property set, property ID, and request type.

### `pVramSurfaceInfo`

This member specifies a pointer to a structure of type [VRAM_SURFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-vram_surface_info).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[VRAM_SURFACE_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-vram_surface_info)