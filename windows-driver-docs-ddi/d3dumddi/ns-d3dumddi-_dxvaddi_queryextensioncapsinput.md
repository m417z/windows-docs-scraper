# _DXVADDI_QUERYEXTENSIONCAPSINPUT structure

## Description

The DXVADDI_QUERYEXTENSIONCAPSINPUT structure describes a capability of an extension GUID that information is requested for.

## Members

### `pGuid` [in]

A pointer to a GUID that represents the extension device type.

### `CapType` [in]

A capability type that information is requested for. A capability type can apply to one of the following categories of video acceleration:

* DXVADDI_EXTENSION_CATEGORY_DECODER (0x0001)
* DXVADDI_EXTENSION_CATEGORY_ENCODER (0x0002)
* DXVADDI_EXTENSION_CATEGORY_PROCESSOR (0x0004)
* DXVADDI_EXTENSION_CATEGORY_ALL (0x0007)

Extension capability types can be defined from DXVADDI_EXTENSION_CAPTYPE_MIN (300) to DXVADDI_EXTENSION_CAPTYPE_MAX (400).

### `pPrivate` [in]

A pointer to a [DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata) structure that contains data that the driver requires to retrieve information about the extension capability.

## See also

[D3DDDIARG_GETCAPS](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_d3dddiarg_getcaps)

[D3DDDICAPS_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ne-d3dumddi-_d3dddicaps_type)

[DXVADDI_PRIVATEDATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/ns-d3dumddi-_dxvaddi_privatedata)

[GetCaps](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_getcaps)