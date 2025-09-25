# DXGKCB_INDICATE_CHILD_STATUS callback function

## Description

The **DxgkCbIndicateChildStatus** function records the current status of a specified child device of a display adapter.

## Parameters

### `DeviceHandle` [in]

A handle that represents a display adapter. The display miniport driver previously obtained this handle in the **DeviceHandle** member of the [DXGKRNL_INTERFACE](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgkrnl_interface) structure that was passed to [DxgkDdiStartDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_start_device).

### `ChildStatus` [in]

A pointer to a [DXGK_CHILD_STATUS](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/ns-dispmprt-_dxgk_child_status) structure that identifies the child device and describes the current status of the child device.

## Return value

**DxgkCbIndicateChildStatus** returns STATUS_SUCCESS if it succeeds. Otherwise, it returns one of the error codes defined in *Ntstatus.h*.

## Remarks

The display miniport driver's DPC for ISR calls **DxgkCbIndicateChildStatus** when the display adapter generates an interrupt for any of the following reasons:

* An external device (typically a monitor) has been connected to one of the display adapter's child devices that has an HPD awareness value of **HpdAwarenessInterruptible**. In this case, the display miniport driver sets *ChildStatus*->**Type** to **StatusConnection** and sets *ChildStatus*.**HotPlug**.**Connected** to **TRUE**.
* An external device (typically a monitor) has been disconnected from one of the display adapter's child devices that has an HPD awareness value of **HpdAwarenessInterruptible**. In this case, the display miniport driver sets *ChildStatus*->**Type** to **StatusConnection** and sets *ChildStatus*.**HotPlug**.**Connected** to **FALSE**.
* The display device connected to one of its on-board child devices (that has a monitor orientation awareness value of **D3DKMDT_MOA_INTERRUPTIBLE**) has been rotated. In this case, the display miniport driver sets *ChildStatus*->**Type** to **StatusRotation** and sets *ChildStatus*.**Rotation**.**Angle** to the angle of rotation.

The display miniport driver's [DxgkDdiNotifyAcpiEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_notify_acpi_event) function calls **DxgkCbIndicateChildStatus** in the following situations:

* The lid on a portable computer gets opened. In this case, the display miniport driver sets *ChildStatus*->**Type** to **StatusConnection** and sets *ChildStatus*.**HotPlug**.**Connected** to **TRUE**.
* The lid on a portable computer gets closed. In this case, the display miniport driver sets *ChildStatus*->**Type** to **StatusConnection** and sets *ChildStatus*.**HotPlug**.**Connected** to **FALSE**.

#### Examples

The following code example shows how to record the current status of a child device.

```cpp
NTSTATUS
AtiSimulateMonitor(HW_DEVICE_EXTENSION *pHwDeviceExtension, PR2_SIMULATE_MONITOR i_pEscape)
{
    NTSTATUS Status;
    PVOID MonitorDescriptor = NULL;
    DXGK_CHILD_STATUS     ChildStatus;
    ChildStatus.ChildUid    =  pHwDeviceExtension->ulNumberDisplays | HW_ID_DISPLAY_CHILD;
    ChildStatus.Type    = StatusConnection;

    if(i_pEscape->Data == NULL) {
        // Remove a simulated monitor
        if(pHwDeviceExtension->pvSimulatedMonitorDescriptor != NULL) {
            ExFreePoolWithTag(pHwDeviceExtension->pvSimulatedMonitorDescriptor, ATI_TAG);
            pHwDeviceExtension->pvSimulatedMonitorDescriptor = NULL;
            pHwDeviceExtension->ulSimulatedMonitorDescriptorLength = 0;
           pHwDeviceExtension->ulRetryCount = 0;
           pHwDeviceExtension->bReportDescriptor = FALSE;

            ChildStatus.HotPlug.Connected = FALSE;
            Status = DxgkCbIndicateChildStatus(pHwDeviceExtension->DeviceHandle, &ChildStatus);
        }
        else {
            // No simulated monitor is present so the request to remove one is invalid
            return STATUS_INVALID_PARAMETER;
        }
    }
    else {
        //Add a simulated monitor
    }
    return Status;
}
```

## See also

[DxgkDdiQueryChildRelations](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_relations)

[DxgkDdiQueryChildStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/dispmprt/nc-dispmprt-dxgkddi_query_child_status)