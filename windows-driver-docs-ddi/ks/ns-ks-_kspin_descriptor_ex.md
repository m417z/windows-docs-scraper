## Description

The **KSPIN_DESCRIPTOR_EX** structure describes the characteristics of a pin type on a given filter type.

## Members

### `Dispatch`

A pointer to the [**KSPIN_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) structure for this pin. This pointer is optional and should only be provided by clients that wish to receive notifications. Clients that need to perform pin-centric processing (filters concerned with the routing of data, in other words hardware drivers) must provide this dispatch table and a process dispatch. See [**KSPIN_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch) for more information.

### `AutomationTable`

A pointer to the [KSAUTOMATION_TABLE](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) structure for this pin. The automation table contains the properties, methods, and events supported by the pin. This automation table is merged with the automation table provided by AVStream for all pins. If the client supplies any property, event, or method handlers that are already provided by AVStream, the client's implementation supersedes that of AVStream.

### `PinDescriptor`

This member specifies a structure of type [**KSPIN_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor).

### `Flags`

Specifies a value of type ULONG. This can be any combination of the flags listed in the following list. Specify flags using a bitwise OR, with the following exceptions: KSPIN_FLAG_CRITICAL_PROCESSING and KSPIN_FLAG_HYPERCRITICAL_PROCESSING are mutually exclusive. KSPIN_FLAG_DO_NOT_INITIATE_PROCESSING and KSPIN_FLAG_INITIATE_PROCESSING_ON_EVERY_ARRIVAL are mutually exclusive. KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING and KSPIN_FLAG_SOME_FRAMES_REQUIRED_FOR_PROCESSING are mutually exclusive. KSPIN_FLAG_PROCESS_IN_RUN_STATE_ONLY and KSPIN_FLAG_PROCESS_IF_ANY_IN_RUN_STATE are mutually exclusive.

#### KSPIN_FLAG_DISPATCH_LEVEL_PROCESSING

Indicates that the minidriver requests that the process dispatch to happen at IRQL DISPATCH_LEVEL instead of PASSIVE_LEVEL.

#### KSPIN_FLAG_CRITICAL_PROCESSING

If asynchronous processing has been specified or if the system is running at PASSIVE_LEVEL and a process call comes in at DISPATCH_LEVEL, processing is done in a queued work item. This flag indicates that the work item should be placed on the critical work queue as opposed to the delayed work queue.

#### KSPIN_FLAG_HYPERCRITICAL_PROCESSING

If asynchronous processing has been specified or if the system is running at PASSIVE_LEVEL and a process call comes in at DISPATCH_LEVEL, processing is done in a queued work item. This flag indicates that the work item should be placed on the hypercritical work queue as opposed to the delayed work queue or critical work queue.

#### KSPIN_FLAG_ASYNCHRONOUS_PROCESSING

Indicates that the pin should process data asynchronously. If this flag is set, AVStream does not wait for one process dispatch to be called before proceeding with additional frames.

#### KSPIN_FLAG_DO_NOT_INITIATE_PROCESSING

AVStream calls the processing dispatch only when the minidriver explicitly calls **Ks***Xxx***AttemptProcessing**. Useful for clients that intend to directly poll the queue at, for example, DPC time to transport data to hardware.

#### KSPIN_FLAG_INITIATE_PROCESSING_ON_EVERY_ARRIVAL

Indicates that processing should occur every time a data frame arrives into the queue. If this flag is not specified, the process dispatch is only called when data arrives into a previously empty queue.

#### KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING

Indicates that frames are not required on this pin for processing to commence. Even if no frames exist in the queue, a state change will now suffice to cause AVStream to call the processing dispatch. This flag is useful only for filter-centric filters. Pins that do not specify this flag delay processing on the filter if they do not have available frames. Pins that do specify this flag do not delay processing in this manner. If a pin specifies this flag, it becomes the responsibility of the process dispatch to check for available frames.

#### KSPIN_FLAG_ENFORCE_FIFO

Specifying this flag causes the queue to force IRPs to be handled in a first-in-first-out manner. If one IRP is completed by the minidriver prior to an IRP that was sent earlier, the later IRP is not completed by AVStream until the earlier IRP has been completed by the minidriver.

#### KSPIN_FLAG_GENERATE_MAPPINGS

Specifying this flag causes AVStream to automatically generate scatter/gather mappings for a queued frame when the minidriver locks a stream pointer referencing that frame. Clients that intend to use this feature need to register their DMA adapter object with AVStream via the [KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject) function. See the **DataUsed** member of [**KSSTREAM_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksstream_header) for the effect of this flag on the KSSTREAM_HEADER structure. Also see [**KSSTREAM_POINTER_OFFSET**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksstream_pointer_offset).

#### KSPIN_FLAG_DISTINCT_TRAILING_EDGE

Indicates that the queue associated with the pin should have a trailing edge stream pointer. The trailing edge pointer is a special stream pointer that points to the oldest data in the queue unless clone pointers exist on older data. Any data frames in the window between the leading and trailing edge stream pointers are considered to have at least one reference count on them and are not completed until they move out of the window by advancing the trailing edge with [KsPinGetTrailingEdgeStreamPointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspingettrailingedgestreampointer) and one of the **KsStreamPointerAdvance***Xxx* or [KsStreamPointerUnlock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksstreampointerunlock) functions. Pins that do not specify this flag do not have a trailing edge stream pointer.

#### KSPIN_FLAG_PROCESS_IN_RUN_STATE_ONLY

Indicates that AVStream should only call this pin to process when the pin is in KSSTATE_RUN. Changes the minimum processing state from pause to run. AVStream calls this pin to process *after* telling it to go to run state, even if frames arrive. Any pin that specifies this flag and is part of a filter-centric filter causes the filter not to process if the given pin is not in KSSTATE_RUN.

#### KSPIN_FLAG_SPLITTER

Indicates that this pin (an output pin) is a splitter. Pins that specify this flag should indicate a number of possible instances greater than one. When a second instance of this pin is created, AVStream automatically sets up a splitter so that frames sent to the original pin are copied to the new pin. Note that this copying is done automatically by AVStream. Clients *typically* can ignore process pins that have non-**NULL** **DelegateBranch** and **CopySource** pointers. These members indicate that the pin is part of a splitter branch and is handled automatically by AVStream. In releases post-DirectX 8.0, this flag works for pins on both filter-centric and pin-centric filters. Older releases support this flag only for pins on filter-centric filters.

#### KSPIN_FLAG_USE_STANDARD_TRANSPORT

This flag forces the pin to use the standard transport mechanism. It overrides all other checks (communication type, medium type, interface type, etc.) on the pin. Specifying both this flag and KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT results in the standard transport being used. This flag overrides all other checks.

#### KSPIN_FLAG_DO_NOT_USE_STANDARD_TRANSPORT

Indicates that the pin does not use the standard transport mechanism. Pins that do not use the standard transport mechanism will not belong to a pipe section and will not have associated queues.

#### KSPIN_FLAG_FIXED_FORMAT

Indicates that this pin uses a fixed data format. Any attempt to set the data format returns STATUS_INVALID_DEVICE_REQUEST.

#### KSPIN_FLAG_GENERATE_EOS_EVENTS

Indicates that this pin handles connection event support requests.

#### KSPIN_FLAG_RENDERER

Specifies that this pin is capable of rendering frames.

#### KSPIN_FLAG_SOME_FRAMES_REQUIRED_FOR_PROCESSING

When specified on a filter-centric filter pin, indicates that one or more instances of the pin type in question must have frames available in order to process data. Mutually exclusive with KSPIN_FLAG_FRAMES_NOT_REQUIRED_FOR_PROCESSING.

Note that this behavior can be obtained through [KsPinAttachOrGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattachorgate) by manually setting up an OR gate as the frame gate for every instance of the pin and attaching this OR gate to the filter's AND gate.

When using this flag, minidrivers cannot call [KsPinAttachAndGate](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kspinattachandgate) or **KsPinAttachOrGate** on the associated pin instances. (The flag effectively does this for you for the simple OR case.) Also see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing).

#### KSPIN_FLAG_PROCESS_IF_ANY_IN_RUN_STATE

When specified on a [filter-centric](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing) pin, indicates that processing may occur when one or more of the pin instances so flagged are in the run state. All non-stopped pins still must be in at least pause to process data. Do not use this flag if the corresponding pin is an output pin and this pin is involved in an in-place transform.

#### KSPIN_FLAG_DENY_USERMODE_ACCESS

This flag prevents user-mode access to this specific pin.

#### KSPIN_FLAG_IMPLEMENT_CLOCK

Indicates that this pin exposes a clock that can be selected by the graph manager as a master clock. Also see [AVStream Clocks](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-clocks).

### `InstancesPossible`

Specifies a value of type ULONG that contains a count of the maximum number of possible instances of this pin. Any attempt to instantiate more than this number of pins of the given type fails. Set to KSINSTANCE_INDETERMINATE to have no limit on number of pins instantiated.

### `InstancesNecessary`

Specifies a value of type ULONG that contains the minimum number of pins of a given pin type that are required to be in a state at or above the minimum processing level for proper functioning of the filter. By default the minimum processing level is KSSTATE_PAUSE, although the minidriver can modify the default behavior by setting the **Flags** member of this structure to either KSPIN_FLAG_PROCESS_IN_RUN_STATE_ONLY or KSPIN_FLAG_PROCESS_IF_ANY_IN_RUN_STATE. Any attempt to change the state of a filter that does not have this number of instances of this type of pin fails. See additional information in the Remarks section.

### `AllocatorFraming`

A pointer to a [**KSALLOCATOR_FRAMING_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing_ex) structure containing the allocator framing requirements for this pin type. Allocator framing specifies items such as memory alignment requirements, maximum frame size, and minimum frame size. This member can be **NULL**, which indicates that this pin does not support the allocator framing property.

### `IntersectHandler`

A pointer to a driver-defined [KStrIntersectHandlerEx](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff567185(v=vs.85)) function to handle data-intersection. If this member is **NULL**, the pin handles data intersection queries for data ranges with the specifier KSDATAFORMAT_SPECIFIER_NONE. The intersection handler function receives a single data range from the query and a single data range from the pins list of data ranges. The type, subtype, and specifier GUIDs of these ranges are guaranteed to match, though some may be wildcards. The function either indicates the data ranges do not match, or it produces the best data format in the intersection of the two data ranges. See [Data Range Intersections in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/data-range-intersections-in-avstream) for more information.

## Remarks

AMCap and Blink might not be able to find tuner and crossbar interfaces on your AVStream driver if the **InstancesNecessary** member of KSPIN_DESCRIPTOR_EX is set to zero for the analog video input pin. To fix this problem, set **InstancesNecessary** for this pin to one.

Note that the allocator framing requirements of your pin may be ignored despite the fact that your allocator framing specifies that alignment or size is absolutely required to be a certain value. If your kernel-mode driver is connected to an upstream user-mode filter that allocates for it and the particular upstream filter's allocator does not understand framing requirements, this can happen (current particular examples include the MPEG-2 splitter).

Furthermore, if you specify KSPIN_FLAG_DO_NOT_INITIATE_PROCESSING and the pin uses the standard transport mechanism, you must have a processing object. This means there must be some process dispatch provided (either at the filter level or at the pin level); even if this function is never called, it must be provided in this circumstance.

[Data Range Intersections in AVStream](https://learn.microsoft.com/windows-hardware/drivers/stream/data-range-intersections-in-avstream) and [AVStream Splitters](https://learn.microsoft.com/windows-hardware/drivers/stream/avstream-splitters).

## See also

[**KSALLOCATOR_FRAMING_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksallocator_framing_ex)

[**KSPIN_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kspin_descriptor)

[**KSPIN_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_dispatch)

[KsDeviceRegisterAdapterObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksdeviceregisteradapterobject)