# MINIPORT_PNP_IRP callback function

## Description

The *MiniportPnpIrp* function enables a miniport driver to optionally manage its Plug and Play (PnP) resources. *MiniportPnpIrp* itself is never defined by miniport drivers directly. Instead, it is defined either as *MiniportFilterResourceRequirements* or *MiniportStartDevice*.

 If defined as *MiniportFilterResourceRequirements*, this function enables a miniport driver to modify
the resource requirements for a device. If defined as *MiniportStartDevice*, this function enables the miniport driver to remove resources that it added in the
*MiniportFilterResourceRequirements* function.

**Note** You must declare this function by using the either the **MINIPORT_FILTER_RESOURCE_REQUIREMENTS** type or the **MINIPORT_START_DEVICE** type. For more
information, see the following Examples section.

## Parameters

### `MiniportAddDeviceContext` [in]

A handle for a driver-allocated context area that the miniport driver registered with NDIS in the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function.

### `Irp` [in]

If this function is defined as *MiniportFilterResourceRequirements*, this parameter is a pointer to the [IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) for the driver to handle.

If this function is defined as *MiniportStartDevice*, this parameter is a pointer to an
[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device) IRP.

## Return value

*MiniportPnpIrp* returns one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver handled the start device request successfully. |
| **NDIS_STATUS_RESOURCES** | The miniport driver could not handle the start device request because of low resources. |
| **NDIS_STATUS_FAILURE** | *MiniportFilterResourceRequirements* failed for reasons other than insufficient resources. |

## Remarks

### MiniportFilterResourceRequirements Remarks

The
*MiniportFilterResourceRequirements* function is an optional function. Miniport
drivers should register this function if they support MSI-X and at least one of the following is
true:

* The driver requires the ability to change the interrupt affinity for each MSI-X message.
* The driver will register for line-based interrupts in the
  [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

To register
*MiniportFilterResourceRequirements*, specify the entry point in the
[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics) structure.

NDIS calls the
*MiniportFilterResourceRequirements* function after NDIS receives an
[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) IRP for a network interface card (NIC). NDIS calls
*MiniportFilterResourceRequirements* after the underlying function drivers in the
device stack have completed the processing of the IRP.

The miniport driver must be prepared to handle IRP_MN_FILTER_RESOURCE_REQUIREMENTS from
*MiniportFilterResourceRequirements* immediately after the
[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) function returns
NDIS_STATUS_SUCCESS.

A miniport driver can set an affinity policy for each resource of type
**CmResourceTypeInterrupt** that describes an MSI-X message. If an affinity policy requests targeting
for a specific set of processors, the miniport driver also sets a
[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity) mask at the
**Interrupt.TargetedProcessors** member in the
[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor) structure.

If an NDIS 6.1 or later miniport driver requires more message interrupt resources, it can add more
message interrupt resources to the resources list. If the operating system can provide more message
interrupt resources, the miniport adapter receives the added message interrupt resources when it is
started.

Each message interrupt resource in the list is assigned a message number that corresponds to the order
it has in the resource list. The messages are numbered from 0 through the total number of message
interrupt resources minus one.

To assign an MSI-X table entry to a CPU at run time, the miniport driver can call the
[NdisMConfigMSIXTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismconfigmsixtableentry) function.

A miniport driver can remove all of the resources of type
**CmResourceTypeInterrupt** that are message interrupt resources. The driver can then register for
line-based interrupts in the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function. If
the miniport driver does not remove these message interrupt resources, the operating system will fail if
the driver tries to register line-based interrupt in
*MiniportInitializeEx*.

To allocate memory for a new resource-requirements list, use the
[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority) function. The miniport driver can free the memory for the old
resources-requirement list with the
[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory) function. The PnP manager
frees any driver-allocated memory after the associated IRP is complete.

Miniport drivers should not modify other resources, such as
**CmResourceTypeMemory** and
**CmResourceTypePort** resources. Miniport drivers should avoid adding a new resource to the resource
list. However, miniport drivers can add more message interrupt resources. If the miniport driver adds
more message interrupt resources, the driver must not remove them from the
*MiniportStartDevice* function.

If a miniport driver returns NDIS_STATUS_RESOURCES or NDIS_STATUS_FAILURE from *MiniportFilterResourceRequirements*, NDIS will use the resource requirements as specified by the parent bus driver.

NDIS can call
*MiniportFilterResourceRequirements* several times before NDIS calls the
[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device) function. But
NDIS calls
*MiniportFilterResourceRequirements* only when a device is in the halted
state.

NDIS calls
*MiniportFilterResourceRequirements* at IRQL = PASSIVE_LEVEL.

### MiniportFilterResourceRequirements Example

To define a [MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a [MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function that is named "MyFilterResourceRequirements", use the **MINIPORT_FILTER_RESOURCE_REQUIREMENTS** type as shown in this code example:

```
MINIPORT_FILTER_RESOURCE_REQUIREMENTS MyFilterResourceRequirements;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyFilterResourceRequirements(
    NDIS_HANDLE  MiniportAddDeviceContext,
    PIRP  Irp
    )
  {...}
```

The **MINIPORT_FILTER_RESOURCE_REQUIREMENTS** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_FILTER_RESOURCE_REQUIREMENTS** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

### MiniportStartDevice Remarks

*MiniportStartDevice* is an optional function. Miniport drivers that support
MSI-X can specify an entry point for this function in the
[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics) structure. When NDIS receives a request from the Plug and Play
(PnP) manager to start a device, NDIS calls the
*MiniportStartDevice* function, if any. If a miniport driver adds new resources
in the
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function, it should provide a
*MiniportStartDevice* function to remove the resources.

If a miniport driver modifies resources in such a way that an underlying bus driver cannot recognize
the resources, the driver should provide a
*MiniportStartDevice* function to remove the resources. An underlying bus driver
might fail a start device request if it does not recognize resources that a miniport driver added in
*MiniportFilterResourceRequirements*. If the miniport driver adds message
interrupt resources, it must not remove them from
*MiniportStartDevice*.

NDIS calls
*MiniportStartDevice* before it forwards the start device request to the
underlying drivers. If an underlying driver successfully completes the request, NDIS calls the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function to
initialize the miniport adapter.

NDIS calls
*MiniportStartDevice* at IRQL = PASSIVE_LEVEL.

### MiniportStartDevice Example

To define a *MiniportStartDevice* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportStartDevice* function that is named "MyStartDevice", use the **MINIPORT_START_DEVICE** type as shown in this code example:

```
MINIPORT_START_DEVICE MyStartDevice;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyStartDevice(
    NDIS_HANDLE  MiniportAddDeviceContext,
    PIRP  Irp
    )
  {...}
```

The **MINIPORT_START_DEVICE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_START_DEVICE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IO_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_resource_descriptor)

[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements)

[IRP_MN_START_DEVICE](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-start-device)

[**KAFFINITY**](https://learn.microsoft.com/windows-hardware/drivers/kernel/interrupt-affinity-and-priority#about-kaffinity)

[MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device)

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device)

**MiniportStartDevice**

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NdisAllocateMemoryWithTagPriority](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisallocatememorywithtagpriority)

[NdisFreeMemory](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisfreememory)

[NdisMConfigMSIXTableEntry](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismconfigmsixtableentry)