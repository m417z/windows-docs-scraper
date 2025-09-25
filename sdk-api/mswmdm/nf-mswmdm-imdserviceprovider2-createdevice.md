# IMDServiceProvider2::CreateDevice

## Description

The **CreateDevice** method is called by the Windows Media Device Manager to get the **IMDSPDevice** object(s) corresponding to the canonical device obtained from the PnP subsystem. This method must be implemented for PnP and Windows Explorer support, but otherwise it is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## Parameters

### `pwszDevicePath` [in]

Pointer to a wide-character null-terminated string containing the device path of the device detected by Windows Media Device Manager. This name is obtained from the PnP subsystem, and is the canonical name plus "$ *#* ", where *#* is an auto-incremented number. This name can be passed directly to functions such as **CreateFile** to gain access to the underlying kernel device object. The service provider should create a wrapper **IMDSPDevice** object(s) for this device.

### `pdwCount` [out]

Pointer to a **DWORD** containing the number of **IMDSPDevice** objects that are created.

### `pppDeviceArray` [out]

An array of [IMDSPDevice](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice) interfaces representing the devices. Typically, there is only one array element, but a service provider can create more than one **IMDSPDevice** object corresponding to a device path name if it creates an **IMDSPDevice** object for each top-level storage. This is subject to change in the future, and the count may be restricted to 1.

## Return value

If the method succeeds it returns S_OK. If the method fails, it returns the Windows Media Device Manager error codes.

## Remarks

Windows Media Device Manager calls this method when an application starts, or when a Plug and Play compliant device connects with the computer.

## See also

[Enumerating Devices](https://learn.microsoft.com/windows/desktop/WMDM/enumerating-devices-service-provider)

[IMDServiceProvider2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdserviceprovider2)