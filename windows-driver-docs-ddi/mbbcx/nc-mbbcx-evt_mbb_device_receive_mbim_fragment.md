# EVT_MBB_DEVICE_RECEIVE_MBIM_FRAGMENT callback function

## Description

A client driver's *EvtMbbDeviceReceiveMbimFragment* event callback function provides the response message returned from its device in response to a previous MBIM control message sent from MBBCx. This callback function is the equivalent of the *GetEncapsulatedResponse* request defined in the MBIM specification.

## Parameters

### `Device`

A handle to a framework device object the client driver obtained from a previous call to [**WdfDeviceCreate**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `ReceiveRequest`

A handle to the framework object which represents the request to receive a fragmented MBIM message from the device.

## Prototype

```cpp
//Declaration

EVT_MBB_DEVICE_RECEIVE_MBIM_FRAGMENT EvtMbbDeviceReceiveMbimFragment;

// Definition

VOID EvtMbbDeviceReceiveMbimFragment
(
	WDFDEVICE Device
	MBBREQUEST ReceiveRequest
)
{...}

```

## Remarks

An MBBCx client driver must register an *EvtMbbDeviceReceiveMbimFragment* callback function by calling [**MbbDeviceInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdeviceinitialize).

The MBBCx framework calls this callback function after it is notified by the client driver that [an MBIM message is available from the device](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbdeviceresponseavailable), either as a response to a previous MBIM control message request from the framework, or as an unsolicited device event.

In this callback function, the client driver puts the response MBIM message into the buffer space pre-allocated by the MBBCx framework. If the size of a single response message is larger than the size of the pre-allocated buffer, and then it must split this response message into multiple fragmented messages as described in the MBIM specification. When fragmentation happens, MBBCx will continue to call this callback function, once per fragment, until all fragments of the response MBIM message has been received.

To access the pre-allocated buffer space and its size, the client driver should call [**MbbRequestGetBuffer**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbrequestgetbuffer). Once the client driver fills this buffer space with the response message, or a fragment of the response message, it must call [**MbbRequestCompleteWithInformation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nf-mbbcx-mbbrequestcompletewithinformation) with the number of bytes actually being filled. This can be done either asynchronously or synchronously.

For more information, see [Handling MBIM control messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#handling-mbim-control-messages).

### Example

Error handling has been left out of this example for brevity and clarity.

```C++
VOID
EvtMbbDeviceReceiveMbimFragment(
    WDFDEVICE  Device,
    MBBREQUEST ReceiveRequest
)
{
    size_t filledSize = 0;
    size_t bufferSize = 0;
    PVOID buffer = MbbRequestGetBuffer(ReceiveRequest, &bufferSize);

    //
    // Write the response MBIM message into the buffer.
    // This example uses memset as an illustration of how
    // it can being completed synchronously.
    //
    memset(buffer, '*', bufferSize);
    filledSize = bufferSize;

    MbbRequestCompleteWithInformation(ReceiveRequest,
        STATUS_SUCCESS,
        filledSize);
}
```

## See also