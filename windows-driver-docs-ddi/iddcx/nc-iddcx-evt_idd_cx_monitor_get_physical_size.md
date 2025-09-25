# EVT_IDD_CX_MONITOR_GET_PHYSICAL_SIZE callback function

## Description

The OS calls **EVT_IDD_CX_MONITOR_GET_PHYSICAL_SIZE** to query the physical size of a remote EDID-less monitor.

## Parameters

### `MonitorObject` [in]

The context for the monitor this OPM context should be created on.

### `pOutArgs` [out]

Pointer to a [**IDARG_OUT_MONITORGETPHYSICALSIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorgetphysicalsize) structure that contains information about the monitor size.

## Return value

If the driver knows the physical size of the monitor, it should fill in the **pOutArgs** and return STATUS_SUCCESS. In the event the driver does not know the physical size, it should return STATUS_NO_DATA_DETECTED.

## Prototype

``` c++
//Declaration

EVT_IDD_CX_MONITOR_GET_PHYSICAL_SIZE EvtIddCxMonitorGetPhysicalSize;

// Definition

NTSTATUS EvtIddCxMonitorGetPhysicalSize
(
    IDDCX_MONITOR MonitorObject
    IDARG_OUT_MONITORGETPHYSICALSIZE * pOutArgs
)
{...}

```

## Remarks

This callback is only called for remote drivers that do not provide a monitor description for the specified monitor. If a remote driver does specify a monitor description for a given monitor, then the physical width and height will be taken from the description and this callback will not be called for that monitor.

**To declare a remote ID driver:**

An ID driver declares that it wants to create a remote ID adapter by setting the [**IDDCX_ADAPTER_FLAGS_REMOTE_SESSION_DRIVER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ne-iddcx-iddcx_adapter_flags) bit in the [**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps).**Flags** field when calling the [IddCxAdapterInitAsync](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/nf-iddcx-iddcxadapterinitasync) function. The OS tracks if the ID driver is being loaded due to the remote desktop stack connecting a remote session and will fail the IddCxAdapterInitAsync() call in the following two cases:

* If an ID driver does not set the **IDDCX_ADAPTER_FLAGS_REMOTE_SESSION_DRIVER** flags for a device that was created by the OS remote desktop stack for a remote session
* If an ID driver sets the **IDDCX_ADAPTER_FLAGS_REMOTE_SESSION_DRIVER** flags for a device that was not created by the OS remote desktop stack

## See also

[**IDARG_OUT_MONITORGETPHYSICALSIZE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-idarg_out_monitorgetphysicalsize)

[**IDDCX_ADAPTER_CAPS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/iddcx/ns-iddcx-iddcx_adapter_caps)