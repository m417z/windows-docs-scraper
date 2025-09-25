# tagDRMFORWARD structure

## Description

The DRMFORWARD structure contains the information that the [DRMK system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components) needs in order to forward a DRM content ID to a device that handles protected content.

## Members

### `Flags`

No flag bits are currently defined. Set this member to zero.

### `DeviceObject`

Pointer to the device object, which is a system structure of type [DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object).

### `FileObject`

Pointer to the file object, which is a system structure of type [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object).

### `Context`

Pointer to context data. For more information, see the following Remarks section.

## Remarks

This structure is one of the [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) function's call parameters. The structure contains the information that the function needs to send a [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request to a WDM driver.

The WDM driver manages the device that is represented by the **DeviceObject** member. The **DrmForwardContentToDeviceObject** function sends the property request to this device object.

When constructing the IRP that contains the property request, the **DrmForwardContentToDeviceObject** function copies the **FileObject** member into the **FileObject** field in the driver's I/O stack location in the IRP. If the WDM driver is a KS driver (which implements all or part of a KS filter), the **FileObject** member represents the pin on the filter that is to receive the stream containing the protected content. For a non-KS driver, the context fields in the FILE_OBJECT structure can contain any value whose meaning is agreed upon between the driver and the caller of the **DrmForwardContentToDeviceObject** function.

The **Context** member contains a context value that the **DrmForwardContentToDeviceObject** function copies into the property descriptor of the KSPROPERTY_DRMAUDIOSTREAM_CONTENTID set-property request (the [KSP_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-ksp_drmaudiostream_contentid) structure's **Context** member). The **Context** member can contain any value whose meaning is agreed upon between the driver and the caller of the **DrmForwardContentToDeviceObject** function.

By convention, if the downstream module is a KS filter, the **Context** member points to a file object that specifies the KS pin to which the **DrmForwardContentToDeviceObject** function sends the property request. In other words, the **Context** member points to the same file object as the **FileObject** member.

The DRMFORWARD structure is also used by the [PcForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttodeviceobject) function and the [IDrmPort2::ForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-forwardcontenttodeviceobject) method, which are alternative entry points for the **DrmForwardContentToDeviceObject** function. For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

When an audio driver forwards DRM content to a system-supplied USB driver, the following conditions apply:

* **DRMFORWARD.DeviceObject** must be placed at the top of the device stack.
* **DRMFORWARD.FileObject** can be **NULL** because the USB stack does not use IO_STACK_LOCATION.FileObject.
* **DRMFORWARD.Context** must be set to a USBD_PIPE_HANDLE value that corresponds to the pipe used by the audio driver.

For general information about DRM, see [Digital Rights Management](https://learn.microsoft.com/windows-hardware/drivers/audio/digital-rights-management).

## See also

[DEVICE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_device_object)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object)

[IDrmPort2::ForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-forwardcontenttodeviceobject)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))

[KSP_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-ksp_drmaudiostream_contentid)

[PcForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttodeviceobject)