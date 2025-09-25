# _WNODE_HEADER structure

## Description

The **WNODE_HEADER** structure is the first member of all other **WNODE_*XXX*** structures. It contains information common to all such structures.

## Members

### `BufferSize`

This member specifies the size, in bytes, of the nonpaged buffer to receive any **WNODE_*XXX*** data to be returned, including this **WNODE_HEADER** structure, additional members of a **WNODE_*XXX*** structure of the type indicated by **Flags**, and any WMI- or driver-determined data that accompanies that structure.

### `ProviderId`

If **Flags** is set to WNODE_FLAG_EVENT_ITEM or WNODE_FLAG_EVENT_REFERENCE, **ProviderId** should contain the ID of the WMI provider associated with the device object. You can obtain the **ProviderId** value by calling [IoWMIDeviceObjectToProviderId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoproviderid). If **Flags** is set to any other value, this member is reserved.

### `DUMMYUNIONNAME`

### `DUMMYUNIONNAME.HistoricalContext`

This member stores the handle to the event tracing session.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME`

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Version`

This member is reserved for WMI.

### `DUMMYUNIONNAME.DUMMYSTRUCTNAME.Linkage`

This member is reserved for WMI.

### `DUMMYUNIONNAME2`

### `DUMMYUNIONNAME2.CountLost`

Reserved

### `DUMMYUNIONNAME2.KernelHandle`

This member is reserved for WMI.

### `DUMMYUNIONNAME2.TimeStamp`

This member indicates the time at which a driver collected the **WNODE_*XXX*** data. This time value is expressed in absolute system time format. Absolute system time is the number of 100-nanosecond intervals since the start of the year 1601 in the Gregorian calendar. A driver can call **KeQuerySystemTime** to obtain this value. If the block is to be written to a log file (WNODE_FLAG_LOG_WNODE), an NT driver might also set WNODE_FLAG_USE_TIMESTAMP in **Flags** to request that the system logger leave the value of **TimeStamp** unchanged.

### `Guid`

This member indicates the GUID that represents the data block associated with the **WNODE_*XXX*** to be returned.

### `ClientContext`

This member stores the clock type for the session. Possible values are included in the following table.

| Value | Description |
| --- | --- |
| 1 | Performance counter value (also called QPC, QueryPerformanceCounter, or PerfCounter) |
| 2 | System timer |
| 3 | CPU cycle |

### `Flags`

This member indicates the type of **WNODE_*XXX*** structure that contains the WNODE_HEADER structure:

#### WNODE_FLAG_ALL_DATA

The rest of a [WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data) structure follows the **WNODE_HEADER** structure in the buffer.

WMI sets this flag in the **WNODE_HEADER** structure that it passes with an [IRP_MN_QUERY_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-query-all-data) request.

A driver sets this flag in the **WNODE_HEADER** structure of an event that consists of all instances of a data block. If the data block size is identical for all instances, a driver also sets WNODE_FLAG_FIXED_INSTANCE_SIZE.

#### WNODE_FLAG_EVENT_ITEM

A driver sets this flag to indicate that the **WNODE_*XXX*** structure was generated as an event. This flag is valid only if WNODE_FLAG_ALL_DATA, WNODE_FLAG_SINGLE_INSTANCE, or WNODE_FLAG_SINGLE_ITEM is also set.

#### WNODE_FLAG_EVENT_REFERENCE

The rest of a [WNODE_EVENT_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_reference) structure follows the **WNODE_HEADER** structure in the buffer.

A driver sets this flag when it generates an event that is larger than the maximum size specified in the registry for an event. WMI uses the information in the **WNODE_EVENT_REFERENCE** structure to request the event data and schedules such a request according to the value of WNODE_FLAG_SEVERITY_MASK.

#### WNODE_FLAG_METHOD_ITEM

The rest of a [WNODE_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_method_item) structure follows the **WNODE_HEADER** structure in the buffer.

WMI sets this flag in the **WNODE_HEADER** structure that it passes with an [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request.

#### WNODE_FLAG_SINGLE_INSTANCE

The rest of a [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structure follows the **WNODE_HEADER** structure in the buffer.

WMI sets this flag in the **WNODE_HEADER** structure that it passes with a request to query or change an instance.

A driver sets this flag in the **WNODE_HEADER** structure of an event that consists of a single instance of a data block.

#### WNODE_FLAG_SINGLE_ITEM

The rest of a [WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance) structure follows the **WNODE_HEADER** structure in the buffer.

WMI sets this flag in the **WNODE_HEADER** structure that it passes with a request to change an item.

A driver sets this flag in the **WNODE_HEADER** structure of an event that consists of a single data item.

#### WNODE_FLAG_TOO_SMALL

The rest of a [WNODE_TOO_SMALL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_too_small) structure follows the **WNODE_HEADER** structure in the buffer.

A driver sets this flag when it passes a **WNODE_TOO_SMALL** structure, indicating that the buffer is too small for all of the **WNODE_*XXX*** data to be returned.

In addition, **Flags** might be set with one or more of the following flags that provide additional information about the **WNODE_*XXX***:

#### WNODE_FLAG_FIXED_INSTANCE_SIZE

All instances of a data block are the same size. This flag is valid only if WNODE_FLAG_ALL_DATA is also set.

#### WNODE_FLAG_INSTANCES_SAME

The number of instances and the dynamic instance names in a **WNODE_ALL_DATA** structure to be returned are identical to those returned from the previous **WNODE_ALL_DATA** query. This flag is valid only if WNODE_FLAG_ALL_DATA is also set. This flag is ignored for data blocks registered with static instance names.

For optimized performance, a driver should set this flag if it can track changes to the number or names of its data blocks. WMI can then skip the processing required to detect and update dynamic instance names.

#### WNODE_FLAG_STATIC_INSTANCE_NAMES

The **WNODE_*XXX*** data to be returned does not include instance names.

WMI sets this flag before requesting **WNODE_*XXX*** data for data blocks registered with static instance names. After receiving the returned **WNODE_*XXX*** from the driver, WMI fills in the static instance names specified at registration before passing the returned **WNODE_*XXX*** to a data consumer.

#### WNODE_FLAG_PDO_INSTANCE_NAMES

Static instance names are based on the device instance ID of the PDO for the device. A driver requests such names by setting WMIREG_FLAG_INSTANCE_PDO in the [WMIREGGUID](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-wmiregguidw) it uses to register the block.

WMI sets this flag before requesting **WNODE_*XXX*** data for data blocks registered with PDO-based instance names.

#### WNODE_FLAG_SEVERITY_MASK

The driver-determined severity level of the event associated with a returned [WNODE_EVENT_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_reference), with 0x00 indicating the least severe and 0xff indicating the most severe level.

WMI uses the value of this flag to prioritize its requests for the event data.

#### WNODE_FLAG_USE_TIMESTAMP

The system logger should not modify the value of **TimeStamp** set by the driver.

An NT driver might also set **Flags** to one or more of the following values for event blocks to be written to a system log file:

#### WNODE_FLAG_LOG_WNODE

An event block is to be sent to the system logger. The event header is a standard **WNODE_HEADER** structure. If the driver clears WNODE_FLAG_TRACED_GUID, the block will also be sent to WMI for delivery to any data consumers that have enabled the event. The driver must allocate the **WNODE_*XXX*** from pool memory. WMI frees the memory after delivering the event to data consumers.

#### WNODE_FLAG_TRACED_GUID

An event block is to be sent only to the system logger. It does not get sent to WMI data consumers. The event header is an **EVENT_TRACE_HEADER** structure, declared in *Evntrace.h*, instead of a **WNODE_HEADER**. The driver must allocate memory for the **WNODE_*XXX*** and free it after [IoWMIWriteEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiwriteevent) returns. The driver can allocate such memory either from the stack or, to minimize the overhead of allocating and freeing the memory, from the driver's thread local storage if the driver creates and maintains its own thread pool.

#### WNODE_FLAG_USE_GUID_PTR

The **Guid** member points to a GUID in memory, rather than containing the GUID itself. The system logger dereferences the pointer before passing the data to the consumer. This flag is valid only if WNODE_FLAG_LOG_WNODE or WNODE_FLAG_TRACED_GUID are also set.

#### WNODE_FLAG_USE_MOF_PTR

Data that follows the fixed members of a **WNODE_*XXX*** structure consists of an array of MOF_FIELD structures, defined in Evntrace.h, that contain pointers to data and sizes rather than the data itself. The array can contain up to MAX_MOF_FIELD elements. The system logger dereferences the pointers before passing the data to the consumer This flag is valid only for blocks registered with WMIREG_FLAG_TRACED_GUID.

## Remarks

In an **IRP_MN_CHANGE_*XXX*** or [IRP_MN_EXECUTE_METHOD](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-execute-method) request, **BufferSize** in the IRP indicates the maximum size in bytes of the output buffer, while **BufferSize** in the input **WNODE_HEADER** for such a request indicates the size, in bytes, of the input data in the buffer.

## See also

[IoWMIDeviceObjectToProviderId](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmideviceobjecttoproviderid)

[IoWMIWriteEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iowmiwriteevent)

[KeQuerySystemTime](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-kequerysystemtime)

[WNODE_ALL_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_all_data)

[WNODE_EVENT_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_item)

[WNODE_EVENT_REFERENCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_event_reference)

[WNODE_METHOD_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_method_item)

[WNODE_SINGLE_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_instance)

[WNODE_SINGLE_ITEM](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_single_item)

[WNODE_TOO_SMALL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wmistr/ns-wmistr-tagwnode_too_small)