## Description

The stream class driver uses the **HW_STREAM_REQUEST_BLOCK** structure to pass information to and from the minidriver, using minidriver provided callbacks.

## Members

### `SizeOfThisPacket`

Specifies the size, in bytes, of this structure.

### `Command`

Specifies the operation to be performed by the minidriver's callback. The class driver passes SRB_XXX command codes to minidriver callbacks.

### `Status`

When the minidriver completes a stream request, it fills this member with the status code of the request. See the documentation for the appropriate **StrMini***Xxx***Request** routine for the status codes minidrivers are expected to use.

### `StreamObject`

For stream oriented requests, the class driver sets this to point to the [**HW_STREAM_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object) structure that specifies the stream the class driver is making a request on.

### `HwDeviceExtension`

Pointer to the minidriver's device extension. The minidriver may use this buffer to record private information. The minidriver sets the size of this buffer in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter). The class driver also passes pointers to this buffer in the **HwDeviceExtension** member of the [**HW_STREAM_OBJECT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_object), [**HW_TIME_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_time_context), and [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structures it passes to the minidriver.

### `SRBExtension`

Points to an uninitialized buffer the class driver allocates for the minidriver to use while processing this stream request block. This buffer is deallocated once the minidriver completes its handling of the block (see [StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification) or [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification) for details).

### `CommandData`

**CommandData** is a union of members provided for command-code-specific data.

### `CommandData.DataBufferArray`

Pointer to an array of **KSSTREAM_HEADER** structures. The number of entries in this array is specified in **NumberOfBuffers**. Each KSSTREAM_HEADER describes one block of data.

This member is used when the command code is [**SRB_READ_DATA**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-read-data) or [**SRB_WRITE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-write-data).

### `CommandData.StreamBuffer`

Points to the [**HW_STREAM_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_stream_descriptor) structure the minidriver fills in with a description of the kernel streaming semantics it supports.

The minidriver specifies the size of this buffer in the **StreamDescriptorSize** member of its [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structure.

This member is used when the command code is [**SRB_GET_STREAM_INFO**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-info).

### `CommandData.StreamState`

The stream state. See [**KSPROPERTY_CONNECTION_STATE**](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-connection-state) for details.

This member is used when the command code is [**SRB_GET_STREAM_STATE**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-state) or [**SRB_SET_STREAM_STATE**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-stream-state).

### `CommandData.TimeReference`

A pointer to a STREAM_TIME_REFERENCE structure.

### `CommandData.PropertyInfo`

Points to the [**STREAM_PROPERTY_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_stream_property_descriptor) structure that specifies the parameters for the property get or set operation.

This member is used when the command code is [**SRB_GET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-device-property), [**SRB_SET_DEVICE_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-device-property), [**SRB_GET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-stream-property), or [**SRB_SET_STREAM_PROPERTY**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-set-stream-property).

### `CommandData.OpenFormat`

Pointer to the **KSDATAFORMAT** structure that specifies the format.

This member is used when the command code is [**SRB_OPEN_STREAM**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-open-stream) or [**SRB_PROPOSE_DATA_FORMAT**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-propose-data-format).

### `CommandData.ConfigInfo`

Pointer to the [**PORT_CONFIGURATION_INFORMATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_port_configuration_information) structure used to initialize the device

This member is used when the command code is [**SRB_INITIALIZE_DEVICE**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-initialize-device).

### `CommandData.MasterClockHandle`

Handle for the clock object that now serves as the master clock.

This member is used when the command code is [**SRB_OPEN_MASTER_CLOCK**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-open-master-clock) or [**SRB_INDICATE_MASTER_CLOCK**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-indicate-master-clock).

### `CommandData.DeviceState`

Specifies the new power state.

This member is used when the command code is [**SRB_CHANGE_POWER_STATE**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-change-power-state).

### `CommandData.IntersectInfo`

Pointer to a [**STREAM_DATA_INTERSECT_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_stream_data_intersect_info) structure that describes the parameters of this operation.

This member is used when the command code is [**SRB_GET_DATA_INTERSECTION**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-get-data-intersection).

### `CommandData.MethodInfo`

Pointer to a buffer that the method data will be read from or written to.

### `CommandData.FilterTypeIndex`

Filter type index for SRB_OPEN_DEVICE_INSTANCE.

### `CommandData.Idle`

This member is set to **TRUE** if no open handles to the device remain. This member is set to **FALSE** if the device is no longer idle (a handle to the device has been opened).

This member is used when the command code is [**SRB_NOTIFY_IDLE_STATE**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-notify-idle-state).

### `_CommandData`

**CommandData** is a union of members provided for command-code-specific data.

### `NumberOfBuffers`

If Command is either [**SRB_READ_DATA**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-read-data) or [**SRB_WRITE_DATA**](https://learn.microsoft.com/windows-hardware/drivers/stream/srb-write-data), then this specifies the number of entries in the array of **KSSTREAM_HEADER** structures that begins at the address pointed to by **CommandData.DataBufferArray**. Otherwise this parameter is unused.

### `TimeoutCounter`

The number of seconds before this request times out. The class driver decrements this once per second. If the class driver decrements **TimeoutCounter** to zero before the minidriver completes this request, it will call the minidriver's [StrMiniRequestTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_request_timeout_handler) routine. If the minidriver sets this to zero, the request does not time out.

### `TimeoutOriginal`

The class driver sets this to the original value of **TimeoutCounter** upon the creation of the SRB.

### `NextSRB`

Points to another stream request block. The minidriver can use this member to queue stream request blocks.

### `Irp`

Pointer to the IRP for the request. Most minidrivers do not need to use this member.

### `Flags`

Specifies the type of request. The class driver and the minidriver can use this member to determine which callback the class driver passed this stream request block to.

| Value | Callback used |
|--|--|
| None | [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) |
| SRB_HW_FLAGS_STREAM_REQUEST | [StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85)) |
| SRB_HW_FLAGS_DATA_TRANSFER | [StrMiniReceiveStreamDataPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) |
| SRB_HW_FLAGS_STREAM_REQUEST | [StrMiniReceiveStreamDataPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) |

SRB_HW_FLAGS_STREAM_REQUEST bit is set for stream-specific requests (which are passed to the minidriver's **StrMiniReceiveStream***Xxx***Packet** routines). The SRB_HW_FLAGS_DATA_TRANSFER bit is set for data transfer requests (which are passed to the minidriver).

### `HwInstanceExtension`

Pointer to the minidriver's instance extension. The minidriver may use this buffer to record private information global to this instance of the minidriver. The minidriver sets the size of this buffer in the [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/ns-strmini-_hw_initialization_data) structure it passes when it registers itself via [StreamClassRegisterMinidriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassregisteradapter).

### `NumberOfBytesToTransfer`

For a SRB_READ_DATA or SRB_WRITE_DATA request, the number of bytes to be transferred.

### `ActualBytesTransferred`

For control requests, the number of bytes actually transferred.

### `ScatterGatherBuffer`

Points to an array of KSSCATTER_GATHER structures, of the form:

```cpp
typedef struct {
    PHYSICAL_ADDRESS PhysicalAddress;
    ULONG Length;
} KSSCATTER_GATHER, *PKSSCATTER_GATHER;
```

The array describes a scatter/gather list that can be used by the minidriver to do DMA. The memory does not need to be probed, locked, mapped, or flushed. The stream class driver performs these for the minidriver.

### `NumberOfPhysicalPages`

Specifies the size of the array passed in the **ScatterGatherBuffer** member.

### `NumberOfScatterGatherElements`

Specifies the number of physical elements pointed to by **ScatterGatherBuffer**.

### `Reserved`

The Reserved[1] field is reserved for system use. Do not use.

## Remarks

The stream class driver passes pointers to HW_STREAM_REQUEST_BLOCK structures to the minidriver's [StrMiniReceiveStreamDataPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb), [StrMiniReceiveStreamControlPacket](https://learn.microsoft.com/previous-versions/ff568467(v=vs.85)), and [StrMiniReceiveDevicePacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_receive_device_srb) routines.

The minidriver owns this stream request block until the request times out or it completes the request. The minidriver signals to the class driver that it has completed the request by calling [StreamClassDeviceNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassdevicenotification)(DeviceRequestComplete, pSrb->HwDeviceExtension, pSRB) for device-specific requests, or calling [StreamClassStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclassstreamnotification)(StreamRequestComplete, pSrb->StreamObject, pSrb) for stream-specific requests. (The minidriver can also complete a request by calling [StreamClassCompleteRequestAndMarkQueueReady](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nf-strmini-streamclasscompleterequestandmarkqueueready)(pSrb). See that routine for details.)

If the class driver times out the request, it will call the minidriver's [StrMiniRequestTimeout](https://learn.microsoft.com/windows-hardware/drivers/ddi/strmini/nc-strmini-phw_request_timeout_handler) routine, which has the responsibility of terminating processing of the request. If the minidriver queues a request for later processing, it should set the **TimeoutCounter** member to zero, which will prevent the class driver from timing out the request. Once the minidriver is ready to resume processing the request, it should reset the **TimeoutCounter** member to the value of **TimeoutOriginal**.