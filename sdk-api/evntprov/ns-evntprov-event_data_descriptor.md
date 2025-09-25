# EVENT_DATA_DESCRIPTOR structure

## Description

The **EVENT_DATA_DESCRIPTOR** structure defines a block of data that will be
used in an ETW event.

This structure is typically initialized using the
[EventDataDescCreate](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventdatadesccreate)
function.

## Members

### `Ptr`

A pointer to the data.

> [!Important]
> This is a 64-bit unsigned integer value in both 32-bit and
> 64-bit architectures. To properly set this value, cast your data pointer to an
> unsigned integer before assigning it to the `Ptr` field, e.g.
> `EventDataDescriptor.Ptr = (UINT_PTR)dataPointer;`, or use the
> [EventDataDescCreate](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventdatadesccreate)
> function.

### `Size`

The size of the data in bytes.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.Reserved`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Type`

Specifies the use of this data in the event. This can be one of the following
values:

- **EVENT_DATA_DESCRIPTOR_TYPE_NONE** (0)

 Normal event data.

- **EVENT_DATA_DESCRIPTOR_TYPE_EVENT_METADATA** (1)

 TraceLogging event decoding information.

- **EVENT_DATA_DESCRIPTOR_TYPE_PROVIDER_METADATA** (2)

 Manually-attached provider traits. For use with operating systems that do not
support attaching provider traits via EventSetInformation. This data will be
ignored if provider traits have been configured via `EventSetInformation`.

- **EVENT_DATA_DESCRIPTOR_TYPE_TIMESTAMP_OVERRIDE** (3)

 64-bit event timestamp override. For use when relogging. Note that logging
events out of timestamp order may lead to event ordering issues during trace
processing.

Note that this field will be ignored unless the event provider has been
configured to respect the `Type` field by calling the
[EventSetInformation](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventsetinformation)
API with the `EventProviderSetTraits` or `EventProviderUseDescriptorType`
operation.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Reserved1`

Not used. Set to 0.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Reserved2`

Not used. Set to 0.

## Remarks

Most event providers will not call **EventDataDescCreate** directly. Instead,
most event providers are implemented using an ETW framework that wraps the calls
to **EventRegister**, **EventWrite**, and **EventUnregister**. For example, you
might
[write an event manifest](https://learn.microsoft.com/windows/win32/etw/writing-manifest-based-events) and
then use the [Message Compiler](https://learn.microsoft.com/windows/win32/wes/message-compiler--mc-exe-) to
generate C/C++ code for the events, or you might use
[TraceLogging](https://learn.microsoft.com/windows/win32/tracelogging/trace-logging-portal) to avoid the
need for a manifest.

To write an event that contains event data, you would create an array of
**EVENT_DATA_DESCRIPTOR** structures (one element for each chunk of data) and
call the
[EventDataDescCreate](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventdatadesccreate)
function to initialize each element with the data to be included in your event.
You would then pass this array to
[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite) to include
the data into the event. For an example, see
[Writing Manifest-based Events](https://learn.microsoft.com/windows/desktop/ETW/writing-manifest-based-events).

The data written to the event will be the concatenation of the data chunks
referenced by the **EVENT_DATA_DESCRIPTOR** structures passed to the
`EventWrite` function. This concatenation contains no padding and does not
retain any of the boundaries or size information from the original set of data
chunks.

The total size of an ETW event (the sum of the user-provided data, the
[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header), and any
[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)
that might be needed for the event) cannot exceed 64KB. Events larger than 64KB
will be dropped by the ETW runtime.

In addition, ETW events that cannot fit into a trace session buffer will also be
dropped. Each buffer has a 72-byte header, so the largest event that can fit
into a buffer is slightly smaller than the buffer's size. For example, a trace
session that uses 32KB buffers will not be able to accept any event larger than
32,696 bytes (32,768-byte buffer minus the 72-byte header leaves 32,696 bytes
for events).

## See also

[EVENT_HEADER](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header)

[EVENT_HEADER_EXTENDED_DATA_ITEM](https://learn.microsoft.com/windows/desktop/api/evntcons/ns-evntcons-event_header_extended_data_item)

[EventDataDescCreate](https://learn.microsoft.com/windows/win32/api/evntprov/nf-evntprov-eventdatadesccreate)

[EventWrite](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwrite)

[EventWriteTransfer](https://learn.microsoft.com/windows/desktop/api/evntprov/nf-evntprov-eventwritetransfer)

[Writing Manifest-based Events](https://learn.microsoft.com/windows/desktop/ETW/writing-manifest-based-events)