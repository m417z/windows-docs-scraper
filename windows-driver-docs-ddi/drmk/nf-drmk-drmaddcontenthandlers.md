# DrmAddContentHandlers function

## Description

The `DrmAddContentHandlers` function provides the system with a list of functions that handle protected content.

## Parameters

### `ContentId` [in]

Specifies the DRM content ID. This parameter identifies a protected KS audio stream.

### `paHandlers` [in]

Pointer to an array of function pointers. Each array element points to a content handler.

### `NumHandlers` [in]

Specifies the number of function pointers in the *paHandlers* array.

## Return value

`DrmAddContentHandlers` returns STATUS_SUCCESS if the call was successful. Otherwise, it returns an appropriate error code.

## Remarks

Before allowing protected content to flow through a data path, the system verifies that the data path is secure. To do so, the system authenticates each module in the data path beginning at the upstream end of the data path and moving downstream. As each module is authenticated, that module gives the system information about the next module in the data path so that it can also be authenticated. To be successfully authenticated, a module's binary file must be signed as DRM-compliant.

If two adjacent modules communicate with each other through either the [IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver) function or the downstream module's COM interface, the upstream module calls the [DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface) or [DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject) function, respectively, to provide the system with information about the downstream module. However, if the two modules use any other type of interface to communicate, the upstream module calls the `DrmAddContentHandlers` function instead.

The *paHandlers* array contains function pointers to entry points in the downstream module. `DrmAddContentHandlers` authenticates the module that implements these functions. (If the entry points are distributed among several modules, the function authenticates all these modules.) The vendor-defined functions in this array make up an interface that is understood by both the module that calls the functions and the module that implements the functions. `DrmAddContentHandlers` does not directly call any of these functions.

The upstream module can pass both the content ID and content rights to the downstream module by using one of the functions in the *paHandlers* array for this purpose. The downstream module needs the content ID to advise the system of any modules to which it sends the protected content.

*DrmAddContentHandlers* performs the same function as [PcAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddcontenthandlers) and [IDrmPort2::AddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-addcontenthandlers). For more information, see [DRM Functions and Interfaces](https://learn.microsoft.com/windows-hardware/drivers/audio/drm-functions-and-interfaces).

## See also

[DrmForwardContentToDeviceObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttodeviceobject)

[DrmForwardContentToInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/drmk/nf-drmk-drmforwardcontenttointerface)

[IDrmPort2::AddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-idrmport2-addcontenthandlers)

[IoCallDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocalldriver)

[PcAddContentHandlers](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nf-portcls-pcaddcontenthandlers)