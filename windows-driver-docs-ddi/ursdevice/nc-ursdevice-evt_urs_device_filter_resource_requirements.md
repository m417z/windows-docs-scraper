# EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS callback function

## Description

The USB dual-role class extension invokes this callback to allow the client driver to insert the resources from the resource-requirements-list object to resource lists that will be used during the life time of each role.

## Parameters

### `Device` [in]

A handle to the framework device object that the client driver retrieved in the previous call to [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate).

### `IoResourceRequirementsList` [in]

A handle to a framework resource-requirements-list object that represents a device's resource requirements list.

### `HostRoleResources` [in]

A handle to a resource list for the controller device when it is operating in host mode.

### `FunctionRoleResources` [in]

A handle to a resource list for the controller when it is operating in function mode.

## Return value

If the operation is successful, the callback function must return STATUS_SUCCESS, or another status value for which NT_SUCCESS(status) equals TRUE. Otherwise it must return a status value for which NT_SUCCESS(status) equals FALSE.

## Remarks

The client driver registers its implementation with the USB dual-role class extension by calling [UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize) after calling [WdfDeviceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicecreate) to create the framework device object for the controller. The class extension invokes this callback before [EvtDevicePrepareHardware](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_prepare_hardware). The callback is invoked within the class extension's [EvtDeviceFilterRemoveResourceRequirements](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdffdo/nc-wdffdo-evt_wdf_device_filter_resource_requirements), which is registered on behalf of the client driver. The client must not implement and register its *EvtDeviceFilterRemoveResourceRequirements* because it will override the class extension's implementation.

Each role has a certain number of assigned hardware resources. Those resources can be memory, interrupts, and so on. The resources are maintained by the system in a *resource requirements list* that contains the range of hardware resources in which the device can operate.

For more information about resource requirements lists, see [Handling Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers).

The class extension allocates memory for the *resource requirements list* and *resource lists* for both host and function roles. When the class extension invokes the client driver's implementation of *EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS*, it passes a WDFIORESREQLIST handle to that requirements list along with URSIORESLIST handles for host and function role *resource lists*. In the implementation, the client driver is expected to enumerate through the logical configurations in the requirements list and check the resource descriptor for each configuration by calling [WdfIoResourceListGetDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistgetdescriptor).

If the driver wants to use a particular resource, it can add the associated resource descriptor to the respective resource list by calling [UrsIoResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursioresourcelistappenddescriptor).

To delete a resource descriptor from the requirement list, the driver calls [WdfIoResourceListRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistremove).

#### Examples

```

EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS EvtUrsFilterRemoveResourceRequirements;

_Function_class_(EVT_URS_DEVICE_FILTER_RESOURCE_REQUIREMENTS)
_IRQL_requires_same_
_IRQL_requires_max_(PASSIVE_LEVEL)
NTSTATUS
EvtUrsFilterRemoveResourceRequirements (
    _In_ WDFDEVICE Device,
    _In_ WDFIORESREQLIST IoResourceRequirementsList,
    _In_ URSIORESLIST HostRoleResources,
    _In_ URSIORESLIST FunctionRoleResources
    )
{
    NTSTATUS status;
    WDFIORESLIST resList;
    ULONG resListCount;
    ULONG resCount;
    ULONG currentResourceIndex;
    PIO_RESOURCE_DESCRIPTOR descriptor;
    BOOLEAN assignToHost;
    BOOLEAN assignToFunction;
    BOOLEAN keepAssigned;

    TRY {

        status = STATUS_SUCCESS;

        //
        // Currently does not support multiple logical configurations. Only the first one
        // is considered.
        //

        resListCount = WdfIoResourceRequirementsListGetCount(IoResourceRequirementsList);
        if (resListCount == 0) {
            // No logical resource configurations found.
            LEAVE;
        }

        // Enumerate through logical resource configurations.

        resList = WdfIoResourceRequirementsListGetIoResList(IoResourceRequirementsList, 0);
        resCount = WdfIoResourceListGetCount(resList);

        for (currentResourceIndex = 0; currentResourceIndex < resCount; ++currentResourceIndex) {

            descriptor = WdfIoResourceListGetDescriptor(resList, currentResourceIndex);

            if (descriptor->Type == CmResourceTypeConfigData) {

                //
                // This indicates the priority of this logical configuration.
                // This descriptor can be ignored.
                //

                keepAssigned = TRUE;
                assignToFunction = FALSE;
                assignToHost = FALSE;

            } else if ((descriptor->Type == CmResourceTypeMemory) ||
                       (descriptor->Type == CmResourceTypeMemoryLarge)) {

                //
                // This example client driver keeps the memory resources here.
                //

                keepAssigned = TRUE;
                assignToFunction = TRUE;
                assignToHost = TRUE;

            } else {

                //
                // For all other resources, pass it to the child device nodes for host and function.
                //

                keepAssigned = FALSE;
                assignToHost = TRUE;
                assignToFunction = TRUE;
            }

            if (assignToHost != FALSE) {
                status = UrsIoResourceListAppendDescriptor(HostRoleResources, descriptor);
                if (!NT_SUCCESS(status)) {
                    // UrsIoResourceListAppendDescriptor for HostRoleResources failed.
                    LEAVE;
                }
            }

            if (assignToFunction != FALSE) {
                status = UrsIoResourceListAppendDescriptor(FunctionRoleResources, descriptor);
                if (!NT_SUCCESS(status)) {
                    // UrsIoResourceListAppendDescriptor for FunctionRoleResources failed.
                    LEAVE;
                }
            }

            if (keepAssigned == FALSE) {
                WdfIoResourceListRemove(resList, currentResourceIndex);
                --currentResourceIndex;
                --resCount;
            }
        }

    } FINALLY {
    }

    return status;
}
```

## See also

[Handling Hardware Resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/hardware-resources-for-kmdf-drivers)

[UrsDeviceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursdeviceinitialize)

[UrsIoResourceListAppendDescriptor](https://learn.microsoft.com/windows-hardware/drivers/ddi/ursdevice/nf-ursdevice-ursioresourcelistappenddescriptor)

[WdfIoResourceListRemove](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfresource/nf-wdfresource-wdfioresourcelistremove)