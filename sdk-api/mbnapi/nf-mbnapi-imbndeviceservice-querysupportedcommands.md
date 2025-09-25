# IMbnDeviceService::QuerySupportedCommands

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Gets the list of commands IDs supported by the Mobile Broadband device service.

## Parameters

### `requestID` [out]

A unique request ID assigned by the Mobile Broadband service to identify this request.

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_ACCESSDENIED** | This device service command is not allowed for calling process privileges. |
| **Other** | An error was encountered when executing this method. |

## Remarks

**QuerySupportedCommands** enables the application to enumerate the list of command messages supported by a device service on the Mobile Broadband device.

This is an asynchronous operation and **QuerySupportedCommands** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnQuerySupportedCommandsComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicesevents-onquerysupportedcommandscomplete) method of the [IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents) interface.

## See also

[IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice)