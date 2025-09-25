# IWDFDevice2::CreateRemoteTarget

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateRemoteTarget** method creates a remote target object that represents a [remote I/O target](https://learn.microsoft.com/windows-hardware/drivers/wdf/general-i-o-targets-in-umdf).

## Parameters

### `pCallbackInterface` [in, optional]

A pointer to an optional, driver-supplied callback interface. The **IUnknown::QueryInterface** method of this interface must return a pointer to the driver's [IRemoteTargetCallbackRemoval](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iremotetargetcallbackremoval) interface, if the driver supports that interface. This parameter is optional and can be **NULL**.

### `pParentObject` [in, optional]

A pointer to a framework object. If the driver provides this optional pointer, the specified object becomes the parent of the new remote target object. If this parameter is **NULL**, the device object that provides the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface becomes the parent. The framework will delete the remote target object when it deletes the parent object.

### `ppRemoteTarget` [out]

A pointer to a location that receives a pointer to the [IWDFRemoteTarget](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremotetarget) interface of the new remote target object.

## Return value

**CreateRemoteTarget** returns S_OK if the operation succeeds. Otherwise, the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | The framework's attempt to allocate memory failed. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_PARAMETER)** | The *pParentObject* parameter did not specify the device object that provides the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface or an object whose chain of parents leads to that object. |

This method might return one of the other values that Winerror.h contains.

## Remarks

After your driver has called **CreateRemoteTarget**, the driver can open the remote target by calling either [IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface) (to open a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers)) or [IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname) (to open a file).

If the driver uses the *pParentObject* parameter to specify a parent object, the parent object can be the device object that provides the [IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2) interface, or it can be any object whose chain of parents leads to that device object. The framework will delete the remote target object when it (or the driver) deletes the device object.

For more information about remote I/O targets, see [Using I/O Targets in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-i-o-targets-in-umdf).

#### Examples

For code examples that use **CreateRemoteTarget**, see the code examples at [IWDFDevice2::CreateRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice2-createremoteinterface) and [IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname).

## See also

[IWDFDevice2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice2)

[IWDFRemoteTarget::OpenFileByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openfilebyname)

[IWDFRemoteTarget::OpenRemoteInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremotetarget-openremoteinterface)