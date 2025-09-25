# SRIOV_SET_POWER_STATE callback

## Description

Sets the power state of the specified PCI Express SR-IOV Virtual Function (VF).

## Parameters

### `Context` [in]

A pointer to a driver-defined context.

### `VfIndex` [in]

A zero-based index of the VF to which this power state set operation applies.

### `PowerState` [in]

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)-type value that indicates the **Dx** power state to set.

### `Wake` [in]

A boolean value that indicates whether to arm the device for a wake signal (PME for PCI Express devices), as it goes into the low power state. TRUE indicates the device is armed; FALSE otherwise. This value must be FALSE if *PowerState* is **PowerDeviceD0**.

## Return value

Set to STATUS_SUCCESS if the request is successful. Otherwise, return appropriate a [NTSTATUS](https://learn.microsoft.com/windows-hardware/drivers/kernel/ntstatus-values) code to indicate the error condition.

## Prototype

```cpp
NTSTATUS  SRIOV_SET_POWER_STATE(
  _In_ PVOID              Context,
  _In_ USHORT             VfIndex,
  _In_ DEVICE_POWER_STATE PowerState,
  _In_ BOOLEAN            Wake
);
```

## Remarks

This callback function is implemented by the physical function (PF) driver. The callback is invoked when the system wants to change the power state of a virtual function.

The PF driver registers its implementation by setting the **SetVfPowerState** member of the SRIOV_DEVICE_INTERFACE_STANDARD, configuring a [WDF_QUERY_INTERFACE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/ns-wdfqueryinterface-_wdf_query_interface_config) structure, and calling [WdfDeviceAddQueryInterface](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfqueryinterface/nf-wdfqueryinterface-wdfdeviceaddqueryinterface).

Here is an example implementation of this callback function.

```

NTSTATUS
Virtualization_SetPowerState (
    __inout              PVOID              Context,
                         USHORT             VfIndex,
                         DEVICE_POWER_STATE PowerState,
                         BOOLEAN            Wake
    )

{
    PDEVICE_CONTEXT         deviceContext;
    WDF_POWER_DEVICE_STATE  wdfPowerState;
    NTSTATUS                status;

    PAGED_CODE();
    status = STATUS_SUCCESS;

    TraceEvents(TRACE_LEVEL_VERBOSE, DBG_INTERFACE,
                        "Virtualization_SetPowerState received with \
                        VFIndex = %d, PowerState = %d, Wake = %d\n",
                        VfIndex, PowerState, Wake);

    deviceContext = (PDEVICE_CONTEXT) Context;

    if (VfIndex >= deviceContext->NumVFs)
    {
        TraceEvents(TRACE_LEVEL_ERROR, DBG_INTERFACE,
                "VfIndex specified: %d was out of bounds. NumVFs: %d\n",
                VfIndex, deviceContext->NumVFs);
        return STATUS_INVALID_PARAMETER;
    }

    switch (PowerState)
    {
    case PowerDeviceD0:
        wdfPowerState = WdfPowerDeviceD0;
        break;
    case PowerDeviceD1:
        wdfPowerState = WdfPowerDeviceD1;
        break;
    case PowerDeviceD2:
        wdfPowerState = WdfPowerDeviceD2;
        break;
    case PowerDeviceD3:
        wdfPowerState = WdfPowerDeviceD3;
        break;
    default:
        return STATUS_INVALID_PARAMETER;
    }

    WdfWaitLockAcquire(deviceContext->PowerStateLock, NULL);
    deviceContext->VfContext[VfIndex].VfPowerDeviceState = wdfPowerState;
    deviceContext->VfContext[VfIndex].VfWake = Wake;
    WdfWaitLockRelease(deviceContext->PowerStateLock);

    return status;
}

```