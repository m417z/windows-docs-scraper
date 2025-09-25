# IWDFDriver::CreateDevice

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateDevice** method configures and creates a new framework device object.

## Parameters

### `pDeviceInit` [in]

A pointer to the [IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize) interface that represents the configuration properties for the new device to create.

### `pCallbackInterface` [in, optional]

A pointer to the **IUnknown** interface that the framework uses to obtain the interfaces that the driver provides for the new device object. These interfaces provide the callback functions that the framework calls when relevant events occur. For more information, see the following Remarks section.

### `ppDevice` [out]

A pointer to a buffer that receives a pointer to the [IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice) interface for the new device object.

## Return value

**CreateDevice** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

The **IUnknown** interface that the driver supplies for the *pCallbackInterface* parameter can support several interfaces. The framework calls the **QueryInterface** method of the supplied **IUnknown** interface multiple times to retrieve the interfaces that the driver supports. The driver's **QueryInterface** method can return the following interfaces:

[IFileCallbackCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackcleanup)

[IFileCallbackClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackclose)

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback)

[IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware)

[IPnpCallbackHardware2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware2)

[IPnpCallbackHardwareInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardwareinterrupt)

[IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio)

[IPnpCallbackHardwareInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardwareinterrupt)

[IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio)

[IPowerPolicyCallbackWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefroms0)

[IPowerPolicyCallbackWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipowerpolicycallbackwakefromsx)

When the device changes state, the framework calls the method that is related to the change (such as the [IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry) method) to notify the driver.

If the call to **CreateDevice** is successful, the driver must eventually call the **IWDFDevice::Release** method. Note that the framework has its own reference count on the object.

For more information, see [Adding a Device](https://learn.microsoft.com/windows-hardware/drivers/wdf/adding-a-device).

#### Examples

The following code example shows an implementation of the [OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd) method of the [IDriverEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-idriverentry) interface. The framework calls **OnDeviceAdd** when a device is added to a computer.

```
HRESULT
CDriver::OnDeviceAdd(
 IWDFDriver* pDriver,
 IWDFDeviceInitialize* pDeviceInit
    )
{
 IUnknown   *pDeviceCallback = NULL;
 IWDFDevice *pIWDFDevice     = NULL;
 IUnknown   *pIUnkQueue      = NULL;

    //
    // Create the device callback object.
    //
    HRESULT hr = CDevice::CreateInstance(&pDeviceCallback);

    //
    // Set device properties
    //
    if (S_OK == hr) {
        pDeviceInit->SetLockingConstraint(WdfDeviceLevel);
        // To register as the power-policy owner for
        // the device stack, call the following:
        // pDeviceInit->SetPowerPolicyOwnership(TRUE);

        // For a filter driver, call the following:
        // pDeviceInit->SetFilter();
    }

    //
    // Request that the framework create a device object.
    // The device callback object is passed to inform the
    // framework about the PnP callback functions the driver supports.
    //
    if (S_OK == hr) {
        hr = pDriver->CreateDevice(pDeviceInit,
                                   pDeviceCallback,
                                   &pIWDFDevice);
    }

    //
    // Create the queue callback object.
    //

    if (S_OK == hr) {
        hr = CQueue::CreateInstance(&pIUnkQueue);
    }

    //
    // Configure the default queue.
    // The queue callback object is passed to inform the
    // framework about the queue callback functions the driver supports.
    //
    if (S_OK == hr) {
        IWDFIoQueue * pDefaultQueue = NULL;
        hr = pIWDFDevice->CreateIoQueue(
                       pIUnkQueue,
                       TRUE,                  // bDefaultQueue
                       WdfIoQueueDispatchParallel,
                       TRUE,                  // bPowerManaged
                       FALSE, //bAllowZeroLengthRequests
                       &pDefaultQueue);
        SAFE_RELEASE(pDefaultQueue);
    }

    SAFE_RELEASE(pDeviceCallback);
    SAFE_RELEASE(pIWDFDevice);
    SAFE_RELEASE(pIUnkQueue);

    return hr;
}
```

## See also

[IDriverEntry::OnDeviceAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-idriverentry-ondeviceadd)

[IFileCallbackCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackcleanup)

[IFileCallbackClose](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ifilecallbackclose)

[IObjectCleanup](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iobjectcleanup)

[IPnpCallback](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallback)

[IPnpCallback::OnD0Entry](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallback-ond0entry)

[IPnpCallbackHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackhardware)

[IPnpCallbackSelfManagedIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-ipnpcallbackselfmanagedio)

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdeviceinitialize)

[IWDFDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdriver)