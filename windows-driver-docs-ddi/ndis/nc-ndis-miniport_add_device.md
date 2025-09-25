# MINIPORT_ADD_DEVICE callback function

## Description

The
*MiniportAddDevice* function enables a miniport driver to establish a context area
for an added device.

**Note** You must declare the function by using the **MINIPORT_ADD_DEVICE** type. For more
information, see the following Examples section.

## Parameters

### `NdisMiniportHandle` [in]

An NDIS handle that identifies the miniport adapter that the Plug and Play (PnP) manager is
adding. NDIS also passes this handle to the
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function.

### `MiniportDriverContext` [in]

A handle to a driver-allocated context area where the driver maintains state and configuration
information. The miniport driver passed this context area to the
[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver) function.

## Return value

*MiniportAddDevice* returns one of the following values:

| Return code | Description |
| --- | --- |
| **NDIS_STATUS_SUCCESS** | The miniport driver successfully allocated the resources that it requires to add the device. |
| **NDIS_STATUS_RESOURCES** | The miniport driver failed to allocate the required resources. |
| **NDIS_STATUS_FAILURE** | [MiniportAddDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_add_device) failed for reasons other than insufficient resources. |

If
*MiniportAddDevice* fails, NDIS will not call the [MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) function
to initialize the miniport adapter.

## Remarks

The
*MiniportAddDevice* function is an optional function. Miniport drivers that
support MSI-X should specify an entry point for this function in the
[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics) structure.

*MiniportAddDevice* can allocate a context area for handling
[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) I/O request packets (IRPs) that the
[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp) function handles. Miniport drivers specify the context area by
initializing an
[NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_add_device_registration_attributes) structure and then calling the
[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes) function. NDIS later provides this context handle to the
[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device),
*MiniportFilterResourceRequirements*,
[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp), and
[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize) functions.
For
*MiniportInitializeEx*, the context handle is passed in the
**MiniportAddDeviceContext** member of the
[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure that the
*MiniportInitParameters* parameter points to.

If the miniport driver fails the
*MiniportAddDevice* call after it allocated the context area, the driver must
free the context area before returning from
*MiniportAddDevice*.

Miniport drivers should use a different context area for the
**MiniportAddDeviceContext** member of the [NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_add_device_registration_attributes) structure
and the
**MiniportAdapterContext** member of the [NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters) structure. Separate context
areas will ensure that information in the context area is not reinitialized, which might occur in the
*MiniportInitializeEx* function if the miniport adapter is halted and
reinitialized.

When the PnP manager requests that NDIS remove the device, NDIS calls the
[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device) function to
undo the operations that
*MiniportAddDevice* performed.

NDIS calls
*MiniportAddDevice* at IRQL = PASSIVE_LEVEL.

### Examples

To define a *MiniportAddDevice* function, you must first provide a function declaration that identifies the type of function you're defining. Windows provides a set of function types for drivers. Declaring a function using the function types helps [Code Analysis for Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/code-analysis-for-drivers), [Static Driver Verifier](https://learn.microsoft.com/windows-hardware/drivers/devtest/static-driver-verifier) (SDV), and other verification tools find errors, and it's a requirement for writing drivers for the Windows operating system.

For example, to define a *MiniportAddDevice* function that is named "MyAddDevice", use the **MINIPORT_ADD_DEVICE** type as shown in this code example:

```
MINIPORT_ADD_DEVICE MyAddDevice;
```

Then, implement your function as follows:

```
_Use_decl_annotations_
NDIS_STATUS
 MyAddDevice(
    NDIS_HANDLE  NdisMiniportHandle,
    NDIS_HANDLE  MiniportDriverContext
    )
  {...}
```

The **MINIPORT_ADD_DEVICE** function type is defined in the Ndis.h header file. To more accurately identify errors when you run the code analysis tools, be sure to add the _Use_decl_annotations_ annotation to your function definition. The _Use_decl_annotations_ annotation ensures that the annotations that are applied to the **MINIPORT_ADD_DEVICE** function type in the header file are used. For more information about the requirements for function declarations, see [Declaring Functions by Using Function Role Types for NDIS Drivers](https://learn.microsoft.com/windows-hardware/drivers/devtest/declaring-functions-by-using-function-role-types-for-ndis-drivers).

For information about _Use_decl_annotations_, see [Annotating Function Behavior](https://learn.microsoft.com/visualstudio/code-quality/annotating-function-behavior).

## See also

[IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements)

[MiniportFilterResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[MiniportRemoveDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_remove_device)

[MiniportStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_pnp_irp)

[NDIS_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_add_device_registration_attributes)

[NDIS_MINIPORT_INIT_PARAMETERS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_init_parameters)

[NDIS_MINIPORT_PNP_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/ns-ndis-_ndis_miniport_pnp_characteristics)

[NdisMRegisterMiniportDriver](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismregisterminiportdriver)

[NdisMSetMiniportAttributes](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndismsetminiportattributes)