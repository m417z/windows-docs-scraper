# StorPortStateChangeDetected function

## Description

Notifies the Storport port driver of a state change for a logical unit number (LUN), host bus adapter (HBA) port, or target device.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension. This is a per-HBA storage area that the port driver allocates and initializes on behalf of the miniport driver. Miniport drivers usually store HBA-specific information in this extension, such as the state of the HBA and the mapped access ranges for the HBA. This area is available to the miniport driver immediately after the miniport driver calls [StorPortInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitialize). The port driver frees this memory when it removes the device.

### `ChangedEntity` [in]

Flags indicating the entities whose state has changed. This is a bitwise **OR** combination of these values:

| Value | Meaning |
| --- | --- |
| **STATE_CHANGE_LUN**<br><br>1 (0x1) | LUN state has changed. |
| **STATE_CHANGE_TARGET**<br><br>2 (0x2) | Target state has changed. |
| **STATE_CHANGE_BUS**<br><br>4 (0x4) | Bus or port state has changed. |

### `Address` [in]

The address of the entity with the state change. *Address* value cannot change until the callback at *HwStateChange* is invoked. If *Address* is allocated in memory, the memory should be freed by the callback routine.

### `Attributes` [in]

Attributes associated with the entity. These are a bitwise **OR** combination of the following:

| Value | Meaning |
| --- | --- |
| **ATTRIBUTE_VM_PASSTHROUGH_LUN** | LUNs are reserved for virtual machine use. |

### `HwStateChange` [in, optional]

A pointer to a callback routine supplied by the miniport. If present, the Storport driver will call this routine when the driver is finished processing this state change notification.

### `HwStateChangeContext` [in, optional]

A miniport-supplied context value that is included when the routine set in *HwStateChange* is called.

## Return value

A status value indicating the result of the notification. This can be one of these values:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_SUCCESS** | The state change notification is scheduled for processing. |
| **STOR_STATUS_INVALID_PARAMETER** | The address type or the entity type is invalid. |
| **STOR_STATUS_UNSUCCESSFUL** | A prior notification is in process and this one cannot be scheduled. |

## Remarks

A successful call to **StorPortStateChangeDetected** results in re-enumeration of the changed entity.

Only one state change request can be active at any time. If a miniport needs to make another  **StorPortStateChangeDetected** call, it should provide a *HwStateChange* callback and make another call to  **StorPortStateChangeDetected** after the callback to *HwStateChange* occurs. If a miniport wants to indicate multiple state changes at the same time, the miniport can call  **StorPortStateChangeDetected** once, with changed entities set in *ChangedEntity* that includes all of the current state changes.

If multiple flags are specified in *ChangedEntity*, the flag with greater value will have precedence over lesser ones.

## See also

[HwStorStateChange](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_state_change)