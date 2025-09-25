# IMbnDeviceService::WriteData

## Description

> [!IMPORTANT]
> Starting in Windows 10, version 1803, the Win32 APIs described in this section are replaced by the Windows Runtime APIs in the [Windows.Networking.Connectivity](https://learn.microsoft.com/uwp/api/windows.networking.connectivity) namespace.

Write data to a device service data session.

## Parameters

### `deviceServiceData` [in]

A byte array that is passed in to the device to write.

### `requestID` [out]

A unique request ID assigned by the Mobile Broadband service to identify this request.

## Return value

The method can return one of the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_ACCESSDENIED** | This device service command is not allowed for calling process privileges. |
| **HRESULT_FROM_WIN32(ERROR_BUFFER_OVERFLOW)** | The length of the *deviceServiceData* is greater than the supported [MaxDataSize](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicescontext-get_maxdatasize). |
| **HRESULT_FROM_WIN32(ERROR_OPEN_FAILED)** | The device service session is not open. |
| **Other** | An error was encountered when executing this method. |

## Remarks

**WriteData** passes a bulk data to a vendor-specific device service on the device. The Mobile Broadband service will forward this request to the device. *deviceServiceData* will be copied byte-by-byte into the data buffer passed in to the request. This data buffer must be less than [MaxDataSize](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicescontext-get_maxdatasize) bytes.

The data session must be opened before the application can call **WriteData**. The operating system does not provide guarantees on the latency or performance of **WriteData**.

This is an asynchronous operation and **WriteData** will return immediately. On completion of the operation, the Mobile Broadband service will call the [OnWriteDataComplete](https://learn.microsoft.com/windows/desktop/api/mbnapi/nf-mbnapi-imbndeviceservicesevents-onwritedatacomplete) method of the [IMbnDeviceServicesEvents](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservicesevents) interface.

## See also

[IMbnDeviceService](https://learn.microsoft.com/windows/desktop/api/mbnapi/nn-mbnapi-imbndeviceservice)