## Description

The **KSFILTER_DESCRIPTOR** structure describes the characteristics of a filter created by a given filter factory.

## Members

### `Dispatch`

A pointer to a [**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch) structure for this type of filter. This member is optional and need only be provided by clients that wish to receive notifications about filter creations, deletions, and so on. Drivers that are interested in the processing of data (transforms) typically provide this dispatch table and a processing function. Providing a filter-processing function instead of individual pin-processing functions is what makes a driver filter-centric instead of pin-centric.

### `AutomationTable`

A pointer to a [**KSAUTOMATION_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-ksautomation_table_) structure for this type of filter. The automation table is what describes the properties, methods, and events supported by this filter. This automation table is merged with the automation table supplied by AVStream for all filters. Should the client supply a property, method, or event handler already implemented by AVStream, the client's implementation supersedes AVStream's.

### `Version`

This member specifies the version of the filter descriptor. This member should be set to KSFILTER_DESCRIPTOR_VERSION.

### `Flags`

Flags describing the behavior of the filter. Specify flags using a bitwise OR, with the exception of KSFILTER_FLAG_CRITICAL_PROCESSING and KSFILTER_FLAG_HYPERCRITICAL_PROCESSING, which are mutually exclusive:

| Flag | Description |
|---|---|
| KSFILTER_FLAG_DISPATCH_LEVEL_PROCESSING | Indicates that the filter processes at IRQL DISPATCH_LEVEL as opposed to PASSIVE_LEVEL. This applies to the filter process callback as described in [**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch). |
| KSFILTER_FLAG_CRITICAL_PROCESSING | If asynchronous processing has been specified or if the system is running at PASSIVE_LEVEL and a process call comes in at DISPATCH_LEVEL, processing is done in a queued work item. This flag indicates that the work item should be placed on the critical work queue as opposed to the delayed work queue. |
| KSFILTER_FLAG_RECEIVE_ZERO_LENGTH_SAMPLES | Set this flag if a filter-centric filter needs to receive zero-length samples (stream headers with flags but no data). If this flag is not set, zero length samples are passed on to downstream pins, with automatic propagation of necessary flags. Note that this is identical to default behavior in DX8 and prior. If this happens, *these samples bypass the minidriver*. Set the **Terminate** flag in [**KSPROCESSPIN**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksprocesspin) to "turn off" this flag. Also see [Filter-Centric Processing](https://learn.microsoft.com/windows-hardware/drivers/stream/filter-centric-processing). |
| KSFILTER_FLAG_DENY_USERMODE_ACCESS | This flag prevents user-mode access to a specific filter and all pins instantiated on this filter. |
| KSFILTER_FLAG_HYPERCRITICAL_PROCESSING | If asynchronous processing has been specified or if the system is running at PASSIVE_LEVEL and a process call comes in at DISPATCH_LEVEL, AVStream processes a queued work item. This flag indicates that the work item should be placed on the hypercritical work queue as opposed to the delayed work queue or critical work queue. |

### `ReferenceGuid`

A pointer to a GUID that is the binary representation of the Unicode reference string identifying this filter type. If multiple filter factories exist, each must have a unique GUID. Also note that other methods of supplying a reference string require that the filter descriptor be registered using **KsCreateFilterFactory**. The value specified in **ReferenceGuid** must match the filter-specific reference GUID in the driver's INF file. See [Initializing an AVStream Minidriver](https://learn.microsoft.com/windows-hardware/drivers/stream/initializing-an-avstream-minidriver).

### `PinDescriptorsCount`

This member specifies the number of pin descriptors that are provided for this filter type in the **PinDescriptors** member. On Windows XP and later, **PinDescriptorsCount** may be zero if the driver creates pins dynamically.

### `PinDescriptorSize`

This member specifies the size of each individual descriptor in the descriptor table. This value must be a multiple of eight and must be at least **sizeof** (KSPIN_DESCRIPTOR_EX). Larger values allow client-specific descriptor information to be appended to pin descriptors. See additional information in Remarks.

### `PinDescriptors`

A pointer to an array of [**KSPIN_DESCRIPTOR_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex) structures that describe the pins supported by this filter type. If **PinDescriptorsCount** is zero, set this member to **NULL**..

### `CategoriesCount`

This member specifies the number of category GUIDs that are provided in the **Categories** member for this filter type. Zero is a legal value for this member.

### `Categories`

A pointer to an array of category GUIDs for this filter type. If required, a device interface is registered for each category. This member may be **null** if and only if **CategoriesCount** is zero.

### `NodeDescriptorsCount`

This member specifies the number of topology node descriptors provided in **NodeDescriptors**. Zero is a legal value for this member.

### `NodeDescriptorSize`

This member specifies the size in bytes of each individual descriptor in the descriptor table. This value must be a multiple of eight and at least **sizeof(KSNODE_DESCRIPTOR)**. Larger values allow client-specific descriptor information to be appended to node descriptors. See additional information in Remarks.

### `NodeDescriptors`

A pointer to an array of [**KSNODE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor) structures describing the topology nodes for this filter type. This member may be **null** if and only if **NodeDescriptorsCount** is zero.

### `ConnectionsCount`

This member specifies the number of topology connections present in **Connections**. This member may be zero indicating that the default connection set is used. Using default connections means that the topology of the filter is described with a single topology node where each pin on the filter is connected to the corresponding ID on the topology node. The direction of each connection is determined by pin data flow.

### `Connections`

A pointer to an array of [**KSTOPOLOGY_CONNECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection) structures present in this filter type. This member is optional; it may be **NULL** if and only if **ConnectionsCount** is zero (in which case, the default topology is used).

### `ComponentId`

A pointer to the [**KSCOMPONENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscomponentid) structure for this filter type. This is used for the component ID property that provides identification information. This member is optional.

## Remarks

In laying out the filter descriptor, there are a number of macros that the caller may find useful. Instead of specifying count, size, and a table for pin descriptors, categories, node descriptors, and connections, there are a number of useful macros:

| Macro | Description |
|---|---|
| **DEFINE_KSFILTER_PIN_DESCRIPTORS**(*Table*) | Automatically inserts the number of items in table, the size of each item in the table, and the table of pin descriptors itself into the filter descriptor. |
| **DEFINE_KSFILTER_CATEGORIES**(*Table*) | Automatically inserts the number of categories in the table and the table itself into the filter descriptor. |
| **DEFINE_KSFILTER_CATEGORIES_NULL** | Automatically fills in the category members for a filter that defines no categories. |
| **DEFINE_KSFILTER_NODE_DESCRIPTORS**(*Table*) | Automatically inserts the number of items in the table, the size of each item in the table, and the table of node descriptors itself into the filter descriptor. |
| **DEFINE_KSFILTER_NODE_DESCRIPTORS_NULL** | Automatically fills in the node descriptor members for a filter that defines no topology nodes. |
| **DEFINE_KSFILTER_CONNECTIONS**(*Table*) | Automatically inserts the number of connections in the table and the table itself into the filter descriptor. |
| **DEFINE_KSFILTER_DEFAULT_CONNECTIONS** | Automatically fills in the connections table for a filter that defines no explicit connections. |

If you do not use **DEFINE_KS_FILTER_PIN_DESCRIPTORS** to set *PinDescriptorSize*, then you must set *PinDescriptorSize* to **sizeof(KSPIN_DESCRIPTOR_EX)**.

Similarly, if you do not use **DEFINE_KS_FILTER_NODE_DESCRIPTORS** to set *NodeDescriptorSize*, then you must set *NodeDescriptorSize* to **sizeof(KSNODE_DESCRIPTOR)**.

## See also

[**KSCOMPONENTID**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kscomponentid)

[**KSFILTER_DISPATCH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksfilter_dispatch)

[**KSNODE_DESCRIPTOR**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_ksnode_descriptor)

[**KSPIN_DESCRIPTOR_EX**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-_kspin_descriptor_ex)

[**KSTOPOLOGY_CONNECTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/ns-ks-kstopology_connection)

[KsCreateFilterFactory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-kscreatefilterfactory)