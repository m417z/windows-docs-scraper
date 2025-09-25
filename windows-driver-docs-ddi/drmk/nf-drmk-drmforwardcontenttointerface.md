# DrmForwardContentToInterface function

## Description

The `DrmForwardContentToInterface` function accepts a pointer to the COM interface of an object to which the caller intends to forward protected content. The function authenticates the object and sends the object the content ID and DRM rights that the system has assigned to the protected content.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `pUnknown` [in]

Pointer to a COM interface that directly receives KS audio stream data for a KS audio filter.

### `NumMethods` [in]

Specifies the total number of methods in the COM interface that *pUnknown* points to, including all the methods in its base interfaces.

## Return value

`DrmForwardContentToInterface` returns STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error code. The following table shows some of the possible return status codes.

| Return code | Description |
| --- | --- |
| **STATUS_NOT_IMPLEMENTED** | Indicates that the KS audio stream that is associated with *pUnknown* does not support the DRM content rights that are assigned to *ContentId*. |

## Remarks

Before allowing protected content to flow through a data path, the system verifies that the data path is secure. To do so, the system authenticates each module in the data path beginning at the upstream end of the data path and moving downstream. As each module is authenticated, that module gives the system information about the next module in the data path so that it can also be authenticated. To be successfully authenticated, a module's binary file must be signed as DRM-compliant.

If two adjacent modules in the data path communicate with each other through the downstream module's COM interface, the upstream module calls the `DrmForwardContentToInterface` function to provide the system with a pointer to the COM interface. (If the two modules communicate through the [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) function or the downstream module's content handlers, the upstream module calls [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) or [DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers) instead.)

`DrmForwardContentToInterface` authenticates the module that implements the methods in the COM interface pointed to by *pUnknown*. (If the methods are distributed among several modules, the function authenticates all these modules.) This vendor-defined interface must be understood by both the module that calls the interface and the module that implements the interface. `DrmForwardContentToInterface` makes no assumptions regarding this interface other than that it is derived from **IUnknown**.

If `DrmForwardContentToInterface` succeeds in authenticating the driver or library, it does the following:

* Queries the *pUnknown* interface for its [IDrmAudioStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nn-drmk-idrmaudiostream) interface. Note that although the `DrmForwardContentToInterface` authenticates all the methods in the *pUnknown* interface, it does not call any methods in the *pUnknown* interface other than the base **IUnknown** methods.
* Calls [IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid) to set the DRM content ID and DRM content rights on the audio stream. Before returning, `DrmForwardContentToInterface` releases the **IDrmAudioStream** interface.

The *pUnknown* parameter follows the [reference-counting conventions for COM objects](https://learn.microsoft.com/windows-hardware/drivers/audio/reference-counting-conventions-for-com-objects).

`DrmForwardContentToInterface` performs the same function as [PcForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttointerface) and [IDrmPort::ForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-forwardcontenttointerface). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DrmAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmaddcontenthandlers)

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[IDrmAudioStream](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nn-drmk-idrmaudiostream)

[IDrmAudioStream::SetContentId](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-idrmaudiostream-setcontentid)

[IDrmPort::ForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport-forwardcontenttointerface)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[PcForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcforwardcontenttointerface)