# StorPortSetPowerSettingNotificationGuids function

## Description

The **StorPortSetPowerSettingNotificationGuids** routine enables a miniport to receive power setting notifications. The miniport registers an array of GUIDs which identify the power settings to receive power change notifications for.

## Parameters

### `HwDeviceExtension` [in]

A pointer to the hardware device extension for the host bus adapter (HBA).

### `GuidCount` [in]

The number of GUIDs in the *Guid* array.

### `Guid` [in]

An array of power setting GUIDs to register for notification. A typical use for registering these GUIDs is for SATA miniports to receive notifications for AHCI Link Power Management setting changes. The AHCI Link Power Management settings defined by the Microsoft AHCI StorPort miniport driver are the following.

#### HIPM/DIPM Setting (0b2d69d7-a2a1-449c-9680-f91c70521c60)

Configures the link power management mode for disk and storage devices that are attached to the system through an AHCI interface.

| Index | Name | Description |
| --- | --- | --- |
| 0 | Active | Link power management is not used. |
| 1 | HIPM | Host-Initiated Power Management (HIPM) is used. |
| 2 | HIPM and DIPM | HIPM and Device-Initiated Power Management (DIPM) are used. |

#### Adaptive Setting (dab60367-53fe-4fbc-825e-521d069d2456)

The period of AHCI link idle time before the link is put into a slumber state when HIPM or DIPM is enabled.

| Value | Description |
| --- | --- |
| 0 | Minimum value in milliseconds (only use Partial state). |
| ... | Any intermediate value. |
| 300000 | Maximum value in milliseconds (5 minutes). |

Other miniports may define and register their own power setting GUIDs.

## Return value

The **StorPortSetPowerSettingNotificationGuids** routine returns one of these status codes:

| Return code | Description |
| --- | --- |
| **STOR_STATUS_INSUFFICIENT_RESOURCES** | Insufficient resources are available to register for notifications. |
| **STOR_STATUS_SUCCESS** | The notification GUIDs were registered successfully. |

## Remarks

A miniport calls **StorPortSetPowerSettingNotificationGuids** in its [HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine to register the GUIDs it requests to receive notifications for.

When a power state change occurs for a registered notification, the miniport is notified in its [HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine. The control type of **ScsiPowerSettingNotification** is set in the *ControlType* parameter.

The AHCI Link Power management settings are part of the Disk Settings subgroup (0012ee47-9041-4b5d-9b77-535fba8b1442) in the power policy configuration. These are managed under the SUB_DISK configuration alias with *powercfg.exe*.

## See also

[HwStorAdapterControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[HwStorFindAdapter](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter)