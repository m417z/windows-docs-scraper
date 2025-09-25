# SRIOV_GET_RESOURCE_FOR_BAR callback

## Description

Gets the translated resource for a specific Base Address Register (BAR)

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF that is being queried.

### `BarIndex` [in]

The index of the BAR (between 0 and 5).

### `Resource` [out]

A pointer to a [CM_PARTIAL_RESOURCE_DESCRIPTOR](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_cm_partial_resource_descriptor) structure that is filled with the translated hardware resources for the specified BAR.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_GET_RESOURCE_FOR_BAR SriovGetResourceForBar;

NTSTATUS SriovGetResourceForBar(
  _In_  PVOID                           Context,
  _In_  USHORT                          VfIndex,
  _In_  USHORT                          BarIndex,
  _Out_ PCM_PARTIAL_RESOURCE_DESCRIPTOR Resource
)
{ ... }

typedef SRIOV_GET_RESOURCE_FOR_BAR *PSRIOV_GET_RESOURCE_FOR_BAR;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to access the translated hardware resources of a particular BAR of a virtual function.

The PF driver registers its implementation by setting the **GetResourceForBar** member of the SRIOV_DEVICE_INTERFACE_STANDARD, configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

Here is an example implementation of this callback function.

```

NTSTATUS
Virtualization_GetResourceForBar(
    __inout     PVOID             Context,
    __in        USHORT            VfIndex,
    __in        USHORT            BarIndex,
    __out       PCM_PARTIAL_RESOURCE_DESCRIPTOR Resource
    )

{
    PDEVICE_CONTEXT  deviceContext;

    PAGED_CODE();

    deviceContext = (PDEVICE_CONTEXT)Context;

    TraceEvents(TRACE_LEVEL_VERBOSE, DBG_INTERFACE,
        "Virtualization_GetResourceForBar received with"
        "VFIndex = %d, BarIndex = %d\n",
        VfIndex, BarIndex);

    NT_ASSERT(BarIndex < PCI_TYPE0_BAR_COUNT);

    if(VfIndex >= deviceContext->NumVFs)
    {
        NT_ASSERT(FALSE);
        return STATUS_INVALID_DEVICE_REQUEST;
    }

    //
    // Copy the descriptor for all VFs at the given Bar index
    // to the output descriptor.
    //

    *Resource = deviceContext->AssignedVfBarResources[BarIndex];

    if(Resource->Type == CmResourceTypeMemory ||
       Resource->Type == CmResourceTypeMemoryLarge)
    {
        NT_ASSERT((Resource->u.Memory.Length % deviceContext->NumVFs) == 0);
        Resource->u.Memory.Length /= deviceContext->NumVFs;
        Resource->u.Memory.Start.QuadPart += (Resource->u.Memory.Length * VfIndex);
    }

    return STATUS_SUCCESS;
}

```