# MbbDeviceReceiveDeviceServiceSessionData function

## Description

Client drivers call the **MbbDeviceReceiveServiceSessionData** method to pass received device service session data up to an application through the MBBCx framework.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `SessionId`

The ID of the device service session obtained from a previous call to [**MbbAdapterGetSessionId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbadaptergetsessionid).

### `Data`

A driver-allocated WDFMEMORY object containing the data to pass to the application.

## Remarks

For more information, see [Handling device service sessions](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#handling-device-service-sessions).

### Example

The following example shows how a client driver might pass received DSS data to the framework's DSS receive handler.

```C++
VOID
MyReceiveDssData(
    _In_ PMY_DEVICE_CONTEXT DeviceContext,
    _In_ ULONG SessionId,
    _In_ PUCHAR InBuffer,
    _In_ ULONG InBufferSize
)
{
    NTSTATUS status = STATUS_SUCCESS;
    WDFMEMORY data;

    // Allocate the WDFMEMORY object from the received data buffer
    status = WdfMemoryAllocatePreallocated(WDF_NO_OBJECT_ATTRIBUTES,
                                            InBuffer,
                                            InBufferSize,
                                            &data);

    // Pass the received data to the framework
    if(NT_SUCCESS(status))
    {
        DeviceContext->DSSPacketsReceivedCount++;

        MbbDeviceReceiveServiceSessionData(DeviceContext->WdfDevice,
                                            SessionId,
                                            data);
        WdfObjectDelete(data);
    }
}
```

## See also