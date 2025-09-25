# KSDRMAUDIOSTREAM_CONTENTID structure

## Description

The KSDRMAUDIOSTREAM_CONTENTID structure specifies the DRM content ID and DRM content rights for a [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request.

## Members

### `ContentId`

Specifies the DRM content ID. This member identifies a protected KS audio stream.

### `DrmRights`

Specifies the DRM content rights assigned to the stream. This member is a pointer to a [DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights) structure.

## See also

[DRMRIGHTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmrights)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))