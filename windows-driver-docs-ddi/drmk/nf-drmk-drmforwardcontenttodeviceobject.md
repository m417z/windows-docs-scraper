# DrmForwardContentToDeviceObject function

## Description

The `DrmForwardContentToDeviceObject` function accepts a device object representing a device to which the caller intends to forward protected content. The function authenticates the device and sends it the content ID and DRM rights that the system has assigned to the protected content.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `Reserved` [in, optional]

Reserved for future use. Set to **NULL**.

### `DrmForward` [in]

Pointer to a [DRMFORWARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmforward) structure specifying a device object and file object that identify the target device and a KS audio pin on that device, respectively. The structure also contains the context value that the [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))set-property request passes to the device.

## Return value

`DrmForwardContentToDeviceObject` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

Before allowing protected content to flow through a data path, the system verifies that the data path is secure. To do so, the system authenticates each module in the data path beginning at the upstream end of the data path and moving downstream. As each module is authenticated, that module gives the system information about the next module in the data path so that it can also be authenticated. To be successfully authenticated, a module's binary file must be signed as DRM-compliant.

Two adjacent modules in the data path can communicate with each other in one of several ways. If the upstream module calls the downstream module through [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver), the downstream module is part of a WDM driver. In this case, the upstream module calls the `DrmForwardContentToDeviceObject` function to provide the system with the device object representing the downstream module. (If the two modules communicate through the downstream module's COM interface or content handlers, the upstream module calls [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface) or [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers) instead.)

The caller fills in the **DeviceObject**, **FileObject**, and **Context** members of the [DRMFORWARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmforward) structure that parameter *DrmForward* points to. `DrmForwardContentToDeviceObject` uses these values as follows:

* **DeviceObject** specifies the device object that represents the driver (the downstream module). `DrmForwardContentToDeviceObject` uses the device object to authenticate the driver. If successful, the function sets the [KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85)) property on the device by sending a set-property request to a KS pin on the device.
* **FileObject** specifies the KS pin to which `DrmForwardContentToDeviceObject` sends the property request.
* **Context** specifies a context value that the caller passes to the driver through the property request. `DrmForwardContentToDeviceObject` copies the context value into the request's property descriptor. The context value is typically a pointer to a buffer containing data in some custom format that both the caller and driver understand. By convention, if the downstream module is a KS filter, the **Context** member points to a file object that specifies the KS pin to which the `DrmForwardContentToDeviceObject` function sends the property request. In other words, the **Context** member points to the same file object as the **FileObject** member. USB audio drivers must set the **Context** parameter to a USBD_PIPE_HANDLE value.

The property request also contains the DRM content ID from parameter *ContentId* and the DRM content rights belonging to that content ID. `DrmForwardContentToDeviceObject` copies these values into the request's property value. `DrmForwardContentToDeviceObject` makes no further use of the device object after returning.

`DrmForwardContentToDeviceObject` performs the same function as [PcForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttodeviceobject) and [IDrmPort2::ForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-forwardcontenttodeviceobject). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

The KSPROPERTY_DRMAUDIOSTREAM_CONTENTID property assigns the DRM content ID and DRM content rights to a KS audio pin.

###

### Usage Summary Table

| Get | Set | Target | Property descriptor type | Property value type |
| --- | --- | --- | --- | --- |
| No | Yes | Pin | [KSP_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-ksp_drmaudiostream_contentid) | [KSDRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-ksdrmaudiostream_contentid) |

The property value (operation data) is a KSDRMAUDIOSTREAM_CONTENTID structure that specifies the stream's DRM content ID and DRM content rights.

### Return Value

A KSPROPERTY_DRMAUDIOSTREAM_CONTENTID property request returns a status code that indicates whether the KS filter can enforce the specified DRM content rights, as shown in the following table.

| Status Code | Meaning |
| --- | --- |
| STATUS_SUCCESS | The KS audio filter enforces the specified DRM content rights. |
| STATUS_NOT_IMPLEMENTED | The KS filter cannot enforce the specified DRM content rights. |

The **DrmForwardContentToDeviceObject** function uses this property to set the DRM content ID and content rights on the audio stream entering the KS pin that is the target of the property request.

A KS audio filter handles this property request synchronously. If the request returns STATUS_SUCCESS, all the downstream KS audio nodes (see [Audio Topology Nodes](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-topology-nodes)) of the target KS audio pin were also successfully configured with the specified DRM content ID and DRM content rights. (Note that a downstream node is a direct or indirect sink for the audio content flowing through an audio pin.)

The DRM system can set this property at any time during the lifetime of the file object that represents a KS audio pin. If the request does not succeed, the previously set DRM content ID and DRM content rights remain in effect on the KS audio stream.

The handler for the KSPROPERTY_DRMAUDIOSTREAM_CONTENTID property must verify that the property-request IRP originates in kernel mode (that is, confirm that the IRP's **RequestorMode** field equals **KernelMode**). If the IRP originates in user mode, the handler must fail the IRP and return status code INVALID_DEVICE_REQUEST.

**DrmForwardContentToDeviceObject** is an entry point in the [DRMK system driver](https://learn.microsoft.com/windows-hardware/drivers/audio/kernel-mode-wdm-audio-components), Drmk.sys. DRMK sends an IOCTL_KS_PROPERTY request for the KSPROPERTY_DRMAUDIOSTREAM_CONTENTID property at IRQL PASSIVE_LEVEL.

## See also

[DRMFORWARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/ns-drmk-tagdrmforward)

[DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[IDrmPort2::ForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-forwardcontenttodeviceobject)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[KSPROPERTY_DRMAUDIOSTREAM_CONTENTID](https://learn.microsoft.com/previous-versions/ff537351(v=vs.85))

[PcForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttodeviceobject)