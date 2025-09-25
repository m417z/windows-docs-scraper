# NfcCxHardwareEvent function

## Description

Called by the client driver when a hardware event occurs like D0Entry and D0Exit callbacks to start or stop the device. For drivers that require firmware download on initialization or boot-up, it is recommended to move this call to a separate work item. However, the client driver is responsible for the following:

* The client driver should take an idle power reference before queueing the work item. The reference needs to be dropped when the work item completes. This ensures idle power management doesn't cause the driver to go into D3 while the work-item is running.
* The client driver should synchronize the work item with other device callbacks. This is typically achieved by AutomaticSerialization option in [WDF_WORKITEM_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfworkitem/ns-wdfworkitem-_wdf_workitem_config) and have the parent of the WDFWORKITEM be the WDFDEVICE or by having the work item callback explicitly taking the device lock i.e. [WdfObjectAcquireLock](https://learn.microsoft.com/previous-versions/ff548721(v=vs.85)) on the WDFDEVICE.
* If the hardware event call fails from a work-item, the client driver should either restart or unlock the driver to prevent it from being in a bad state. This can be achieved using the Restart or Unload option.

## Parameters

### `Device`

A handle to a framework device object.

### `HardwareEvent`

A pointer to an [NFC_CX_HARDWARE_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/nfccx/ns-nfccx-_nfc_cx_hardware_event) structure.

## Return value

If the operation succeeds, the function returns STATUS_SUCCESS.

## See also

[NFC class extension design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/nfc-class-extension-)

[Near field communication (NFC) design guide](https://learn.microsoft.com/windows-hardware/drivers/nfc/)