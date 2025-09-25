# SRIOV_QUERY_LUID callback

## Description

Gets the local unique identifier of the SR-IOV device.

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `Luid` [out]

A pointer to the local unique
identifier of the SR_IOV device implementing the interface.

## Return value

Return STATUS_SUCCESS if the operation succeeds. Otherwise, return an appropriate [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) error code.

## Prototype

```cpp
SRIOV_QUERY_LUID SriovQueryLuid;

NTSTATUS SriovQueryLuid(
  _In_  PVOID Context,
  _Out_ PLUID Luid
)
{ ... }

typedef SRIOV_QUERY_LUID *PSRIOV_QUERY_LUID;
```

## Remarks

This callback function is implemented by the physical function (PF) driver. It is invoked when the system wants to get the identifier of a specific virtual function.

The PF driver registers its implementation by setting the **QueryLuid** member of the [SRIOV_DEVICE_INTERFACE_STANDARD](https://learn.microsoft.com/windows-hardware/drivers/ddi/pcivirt/ns-pcivirt-_sriov_device_interface_standard), configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

Here is an example implementation of this callback function. The PF driver generates a unique identifier by calling [ZwAllocateLocallyUniqueId](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-zwallocatelocallyuniqueid) and stores it in the device context.

```

NTSTATUS
Virtualization_QueryLuid (
    _In_        PVOID             Context,
    _Out_       PLUID             Luid
    )
{
    PDEVICE_CONTEXT deviceContext;

    PAGED_CODE();

    deviceContext = (PDEVICE_CONTEXT)Context;
    *Luid = deviceContext->Luid;

    return STATUS_SUCCESS;
}

```