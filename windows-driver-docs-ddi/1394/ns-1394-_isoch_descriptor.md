# _ISOCH_DESCRIPTOR structure

## Description

The ISOCH_DESCRIPTOR structure describes a buffer to be attached or detailed from a resource handle, using the [REQUEST_ISOCH_ATTACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) and [REQUEST_ISOCH_DETACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) requests.

## Members

### `fulFlags`

Specifies various flags for this isochronous descriptor. Each attached buffer on the channel has an associated isoch descriptor.

Before using a particular buffer for an I/O operation, the host controller examines the flags in the buffer's isoch descriptor for instructions on how to handle the data. In some cases, the host controller will continue to observe the behavior specified by these flags during I/O operations with subsequent buffers. For instance, if the isoch descriptor flags indicate that the host controller should filter out packets that do not have a certain Sy value recorded in **ulSynch**, the host controller will continue this filtering operation with the data in the buffers that follow, even if the isoch descriptors associated with these buffers do not have the same flags set.

The following table describes the flags that can be assigned to this member.

| Flag | Isochronous Transaction | Description |
| --- | --- | --- |
| DESCRIPTOR_SYNCH_ON_SY | Listen | Starting with the data in current buffer, the host controller ignores all packets not containing a particular Sy value that is embedded in the isochronous packet. The Sy value is specified in **ulSynch**. If the DESCRIPTOR_USE_SY_TAG_IN_FIRST flag is set, the host controller resumes reading all packets after encountering the first packet with the Sy value specified in **ulSynch**. If the DESCRIPTOR_USE_SY_TAG_IN_FIRST flag is not set, the host controller continues filtering, reading packets with the indicated Sy value and ignoring all others. |
| DESCRIPTOR_SYNCH_ON_TAG | Listen | Starting with the data in current buffer, the host controller ignores all packets not containing a particular tag value that is embedded in the isochronous packet. The tag value is specified in **ulTag**. If the DESCRIPTOR_USE_SY_TAG_IN_FIRST flag is set, the host controller resumes reading all packets after encountering the first packet with the tag value specified in **ulTag**. If the DESCRIPTOR_USE_SY_TAG_IN_FIRST flag is not set, the host controller continues filtering, reading packets with the indicated tag value and ignoring all others. |
| DESCRIPTOR_SYNCH_ON_TIME | Listen, Talk | The host controller waits for a particular isochronous cycle time before continuing the operation. The cycle time is specified in the **CycleTime** member. Starting with the data in the current buffer, the host controller ignores all packets not containing a cycle time of **CycleTime**. After finding a packet with the indicated cycle time, the host controller resumes processing all packets. |
| DESCRIPTOR_USE_SY_TAG_IN_FIRST | Listen | Filtering on the **Sy** or **Tag** members occurs only until the first matching packet is received. This flag is used in conjunction with the flags DESCRIPTOR_SYNCH_ON_SY and DESCRIPTOR_SYNCH_ON_TAG. These two flags initiate a filtering operation based on the values in **Sy** or **Tag**, unless DESCRIPTOR_USE_SY_TAG_IN_FIRST is also set, in which case these flags initiate a synchronization rather than a filtering operation. In this synchronization operation the host controller ignores all packets until discovering a packet with the right **Sy** or **Tag** value. After discovering a packet with the indicated **Sy** or **Tag** value, the host controller resumes processing all packets. |
| DESCRIPTOR_TIME_STAMP_ON_COMPLETION | Listen, Talk | Once the host controller completes its DMA to or from this buffer, store the cycle time in the **CycleTime** member of the ISOCH_DESCRIPTOR. |
| DESCRIPTOR_PRIORITY_TIME_DELIVERY | Talk | If the local host controller is not ready for a write, do not retry the write later. (The default behavior is to retry until the host controller is ready.) |
| DESCRIPTOR_HEADER_SCATTER_GATHER | Talk | The host controller treats the data in this buffer as a sequence of headers. The host controller prepends a header from this buffer to each packet it assembles from the data in the next buffer attached. |

### `Mdl`

Specifies the MDL representing a buffer in which the data is, or will be, contained.

### `ulLength`

Specifies the length of the **Mdl**.

### `nMaxBytesPerFrame`

Specifies the maximum bytes contained in each isochronous frame. On writes, the data in the buffer is split into isochronous packets of this size.

### `ulSynch`

For IsochTalk requests, if the DESCRIPTOR_SYNCH_ON_SY flag is set, this member specifies the Sy field of the outgoing packet. For REQUEST_ISOCH_LISTEN requests, if the DESCRIPTOR_SYNCH_ON_SY flag is set, this member specifies the value the host controller will match against the Sy field in isochronous packet headers.

### `ulTag`

For IsochTalk requests, this member specifies the Tag field of the outgoing packet. For REQUEST_ISOCH_LISTEN requests, if the DESCRIPTOR_SYNCH_ON_TAG flag is set, this member specifies the value the host controller will match against the Tag field in isochronous packet headers.

### `CycleTime`

If the DESCRIPTOR_SYNCH_ON_TIME flag is set, this member specifies the isochronous cycle time to synchronize on. (The timing resolution is per isochronous cycle. The **CycleOffset** member of the cycle time is not used.) If the DESCRIPTOR_TIME_STAMP_ON_COMPLETION flag is set, the bus driver fills this member with the isochronous cycle time on completion of the operation that used this buffer.

### `Callback`

Pointer to a callback routine. If non-NULL, the bus driver calls this routine to indicate that the associated attached buffers are ready to be detached. The callback executes at IRQL DISPATCH_LEVEL. The callback is of the following type:

```
void Callback(IN PVOID Context1, IN PVOID Context2);
```

### `Context1`

Specifies the first parameter when the bus driver calls the routine passed in **Callback**.

### `Context2`

Specifies the second parameter when the bus driver calls the routine passed in **Callback**.

### `status`

For [REQUEST_ISOCH_ATTACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class) requests, this member specifies the status of the attach operation on this buffer. If an error occurs during the processing of the **REQUEST_ISOCH_ATTACH_BUFFERS** request, the bus driver fills in the **status** member with an appropriate error code.

**Note** The **status** member must be initialized to STATUS_SUCCESS before the **REQUEST_ISOCH_ATTACH_BUFFERS** request is made.

### `DeviceReserved`

Reserved.

### `BusReserved`

Reserved.

### `PortReserved`

Reserved.

## Remarks

Not all DESCRIPTOR_XXX flags are supported on all hardware. The device driver can use the REQUEST_GET_LOCAL_HOST_INFO request, with **nLevel** = GET_HOST_CAPABILITIES, to determine which DESCRIPTOR_XXX flags are supported. The bus driver returns a pointer to a GET_LOCAL_HOST_INFO2 structure, whose **HostCapabilities** member contains flags that determine which flags the host controller supports. The following table lists which DESCRIPTOR_XXX flags require hardware support, and the corresponding **HostCapabilities** flag the driver should check.

| DESCRIPTOR_XXX flags | HostCapabilities |
| --- | --- |
| DESCRIPTOR_SYNCH_ON_TIME | HOST_INFO_SUPPORTS_START_ON_CYCLE |
| DESCRIPTOR_HEADER_SCATTER_GATHER | HOST_INFO_SUPPORTS_ISO_HDR_INSERTION |

If the driver sets the DESCRIPTOR_HEADER_SCATTER_GATHER flag, the host controller combines the data of the buffer specified in **Mdl** with the data of the next buffer attached. (Subsequent buffers are unaffected.) Each frame of the buffer is prepended to a frame of the next buffer (in the order the data in the buffer is split into frames), and sent as the data of the next isochronous packet. The number of frames of each buffer must match, or the bus driver returns STATUS_INVALID_PARAMETER for the next REQUEST_ISOCH_ATTACH_BUFFER request.

## See also

[GET_LOCAL_HOST_INFO2](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ns-1394-_get_local_host_info2)

[REQUEST_ISOCH_ALLOCATE_RESOURCES](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_ATTACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_DETACH_BUFFERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_LISTEN](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)

[REQUEST_ISOCH_TALK](https://learn.microsoft.com/windows-hardware/drivers/ddi/1394/ni-1394-ioctl_1394_class)