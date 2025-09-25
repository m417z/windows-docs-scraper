# EVT_MBB_DEVICE_SEND_DEVICE_SERVICE_SESSION_DATA callback function

## Description

A client driver's *EvtMbbDeviceSendServiceSessionData* event callback function sends device service session data down to its modem device.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `SessionId`

The ID of the device service session obtained from a previous call to [**MbbAdapterGetSessionId**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbadaptergetsessionid).

### `Data`

A WDFMEMORY object containing the data to pass to the device.

## Prototype

```cpp
//Declaration

EVT_MBB_DEVICE_SEND_DEVICE_SERVICE_SESSION_DATA EvtMbbDeviceSendDeviceServiceSessionData;

// Definition

VOID EvtMbbDeviceSendDeviceServiceSessionData
(
	WDFDEVICE Device
	DSS_SESSION_ID SessionId
	WDFMEMORY Data
)
{...}

```

## Remarks

MBBCx invokes a client driver's *EvtMbbDeviceSendServiceSessionData* callback function when an application sends DSS data down to the modem device. After sending the data to the device asynchronously, the client driver must call [**MbbDeviceSendServiceSessionDataComplete**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdevicesenddeviceservicesessiondatacomplete) so MBBCx can free the memory allocated for the data.

### Example

The following example shows how a client might send DSS data down to its modem device. Error handling has been left out of this example for brevity and clarity.

```C++
VOID
MyEvtMbbDeviceSendServiceSessionData(
    _In_ WDFDEVICE Device,
    _In_ DSS_SESSION_ID SessionId,
    _In_ WDFMEMORY Data
)
{
    // Get the device context and NETADAPTER context
    PMY_DEVICE_CONTEXT deviceContext = GetMyDeviceContext(Device);

    // Set up a driver-defined DSS packet structure
    PMY_DSS_PACKET packet = NULL;

    // Get the data to send from the WDFMEMORY object
    size_t bufferSize = 0;
    PVOID buffer = WdfMemoryGetBuffer(Data,
                                      &bufferSize);

    // Populate the DSS packet
    packet = MyAllocateDssPacket(Data,
                                buffer,
                                bufferSize,
                                SessionId);

    // Send the data asynchronously, which returns STATUS_PENDING when successful
    status = MyModemBusWriteData(deviceContext->BusHandle,
                                 packet);

    // Increment count of sent packets
    deviceContext->DSSPacketsSentCount++;

    // Clean up the memory
    MbbDeviceSendServiceSessionDataComplete(Data,
                                            status);
    MyCleanupDssPacket(packet);
}
```

## See also