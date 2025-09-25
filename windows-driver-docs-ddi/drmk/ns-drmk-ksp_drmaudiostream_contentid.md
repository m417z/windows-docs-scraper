# KSP_DRMAUDIOSTREAM_CONTENTID structure

## Description

The KSP_DRMAUDIOSTREAM_CONTENTID structure specifies the property, request type, and context for a [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request. It also specifies a list of function pointers to the [DRM functions](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions).

## Members

### `Property`

Specifies the property to get or set. This member is a structure of type [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure).

### `Context`

Pointer to context data. This is the context specified in the [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) function's *DrmForward* parameter.

### `DrmAddContentHandlers`

Pointer to [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers) function.

### `DrmCreateContentMixed`

Pointer to [DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed) function.

### `DrmDestroyContent`

Pointer to [DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent) function.

### `DrmForwardContentToDeviceObject`

Pointer to [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) function.

### `DrmForwardContentToFileObject`

Pointer to [DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject) function.

### `DrmForwardContentToInterface`

Pointer to [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface) function.

### `DrmGetContentRights`

Pointer to [DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights) function.

## Remarks

The structure contains function pointers to the DRM library functions in order to provide the driver with convenient access to these functions.

## See also

[DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers)

[DrmCreateContentMixed](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmcreatecontentmixed)

[DrmDestroyContent](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmdestroycontent)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[DrmForwardContentToFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttofileobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[DrmGetContentRights](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmgetcontentrights)

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))