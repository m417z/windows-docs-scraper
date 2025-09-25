# MbbRequestGetBuffer function

## Description

The client driver calls the **MbbRequestGetBuffer** method to get the memory location where an MBIM control message is stored or should be stored.

## Parameters

### `Request`

A handle to the framework object which represents a request from MBBCx framework, either to send a MBIM control command message to the device or to receive an MBIM control response message from the device.

### `BufferSize`

A pointer to the location that receives the size, in bytes, of the MBIM control message fragment.

## Return value

Returns a pointer to the memory location where the MBIM message is stored:

- When this method is called on a request object passed from the [*EvtMbbDeviceSendMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_send_mbim_fragment) callback function, it points to the MBIM control command fragment sent from the MBBCx framework to the device. This memory location is read-only.
- When this method is called on a request object passed from the [*EvtMbbDeviceReceiveMbimFragment*](https://learn.microsoft.com/windows-hardware/drivers/ddi/mbbcx/nc-mbbcx-evt_mbb_device_receive_mbim_fragment) callback function, it points to an empty buffer to which the client driver should write the MBIM control response. This buffer is pre-allocated by the MBBCx framework and the *BufferSize* parameter specifies its size.

## Remarks

For more information, see [Handling MBIM control messages](https://learn.microsoft.com/windows-hardware/drivers/netcx/writing-an-mbbcx-client-driver#handling-mbim-control-messages).

## See also