# IWDFDevice::CreateDeviceInterface

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **CreateDeviceInterface** method creates an instance of a device interface class.

## Parameters

### `pDeviceInterfaceGuid` [in]

A pointer to the GUID for a device interface class.

### `pReferenceString` [in, optional]

A pointer to a **NULL**-terminated string that contains the name of the instance of the device interface. This parameter is optional. The driver can pass **NULL** if the driver does not have to supply a name. If the driver must supply a name, the string that the driver passes must not contain any path separator characters ("/" or "\\").

## Return value

**CreateDeviceInterface** returns S_OK if the operation succeeds. Otherwise, this method returns one of the error codes that are defined in Winerror.h.

## Remarks

Drivers can use the *pReferenceString* parameter to differentiate different instances of a single interface. In other words, if a driver calls **CreateDeviceInterface** twice for the same device interface class, the driver can specify a different string for *pReferenceString* each time. When an instance of an interface is opened, the framework passes the instance's reference string to the driver. The reference string is appended to the path component of the interface instance's name. The driver can then use the reference string to determine which instance of the device interface class is being opened.

If **CreateDeviceInterface** succeeds, the initial state of the interface is disabled. If creation succeeds, the framework automatically enables and disables the interface based on the device's PnP state. In addition, a driver can disable and re-enable a device interface as necessary by calling [IWDFDevice::AssignDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-assigndeviceinterfacestate).

For more information about device interfaces, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how to create a device interface instance. In this example, the driver explicitly calls [IWDFDevice::AssignDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-assigndeviceinterfacestate) to enable the interface.

```
    //
    // Create the device interface.
    //
    HRESULT hr;
    if (S_OK == hr) {
        hr = m_FxDevice->CreateDeviceInterface(
                         &GUID_DEVINTERFACE_OSRUSBFX2,
                         NULL);
    }
    if (S_OK == hr) {
        hr = m_FxDevice->AssignDeviceInterfaceState(
                        &GUID_DEVINTERFACE_OSRUSBFX2,
                        NULL,
                        TRUE);
    }
```

## See also

[IWDFDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfdevice)

[IWDFDevice::AssignDeviceInterfaceState](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice-assigndeviceinterfacestate)