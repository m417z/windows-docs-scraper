# IMbnDeviceService::SetCommand

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Sends a **SET** control command to the device service of a Mobile Broadband device.

## Parameters

### `commandID` [in]

An identifier for the command.

### `deviceServiceData` [in]

A byte array that is passed in to the device.

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

**SetCommand** exists to implement vendor-specific device service functionality which is not otherwise covered in the Mobile Broadband API. A command session on a device service must be opened before the application can call **SetCommand**.

The Mobile Broadband service will issue a **SET** request to the device. *deviceServiceData* will be copied byte-by-byte into the data buffer passed in to the request. This data buffer must be less than [MaxCommandSize](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicescontext-get_maxcommandsize) bytes.

This is an asynchronous operation and **SetCommand** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnSetCommandComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicesevents-onsetcommandcomplete) method of the [IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents) interface.

## See also

[IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice)