## Description

The **SCSI_ADAPTER_CONTROL_TYPE** enumeration contains adapter control operations, where each control type initiates an action on an adapter by the miniport driver. Storport specifies the control type when it calls a miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine.

## Constants

### `ScsiQuerySupportedControlTypes`

Reports the adapter-control operations implemented by the miniport driver. A miniport must support this control type.

The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**SCSI_SUPPORTED_CONTROL_TYPE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-scsi_supported_control_type_list) structure after the HBA has been initialized but before the first I/O.

The miniport driver fills in the **SCSI_SUPPORTED_CONTROL_TYPE_LIST** structure with the operations it supports. After **HwStorAdapterControl** returns from this call, the Storport driver calls the miniport driver's **HwStorAdapterControl** only for operations supported by the miniport.

### `ScsiStopAdapter`

Shuts down the HBA. A miniport must support this control type.

The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL) when the HBA has been removed from the system, stopped for resource reconfiguration, shut down for power management, or otherwise reconfigured or disabled. Storport ensures that there are no uncompleted requests and issues an SRB_FUNCTION_FLUSH request to the miniport driver before calling this routine.

The miniport driver disables interrupts on its HBA, halts all processing, (including background processing not subject to interrupts or processing of which the Storport driver is unaware, such as reconstructing fault-tolerant volumes), flushes any remaining cached data to persistent storage, and puts the HBA into a state from which it can be reinitialized or restarted.

The miniport driver should not free its resources when stopping its HBA. If the HBA was removed or stopped for PnP resource reconfiguration, the Storport driver releases resources on behalf of the miniport driver. If the HBA is shut down for power management, the miniport driver's resources are preserved so the HBA can be restarted.

After [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) returns from stopping the HBA, any data structures allocated on behalf of the miniport driver for the HBA should be considered invalid until the miniport driver is asked to restart.

Note that Storport might call **HwStorAdapterControl** to stop the adapter after the HBA has already been physically removed from the system, so the miniport driver's **HwStorAdapterControl** routine must not perform any operations that require the HBA to be physically present while it is stopping the HBA.

The miniport driver is not called again for the HBA until either the PnP manager requests that the HBA be started, in which case the Storport driver (re)initializes by calling its **HwStorAdapterControl** and [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routines, or an HBA that was stopped for power management is powered up, in which case the Storport driver calls the miniport driver's **HwStorAdapterControl** routine with **ScsiRestartAdapter** or, if the miniport driver does not implement that control type, repeats the initialization sequence for the HBA.

### `ScsiRestartAdapter`

Reinitializes an HBA. A miniport must support this control type.

The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL) to power up an HBA that was shut down for power management. All resources previously assigned to the miniport driver are still available, and its device extension and logical unit extensions, if any, are intact.

The miniport driver performs the same operations as in its [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routine, such as setting up the HBA's registers and its initial state, if any.

The miniport driver must not call routines that can only be called from [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) or from **HwStorAdapterControl** when the control type is **ScsiSetRunningConfig**, such as [**StorPortGetBusData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetbusdata) and [**StorPortSetBusDataByOffset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetbusdatabyoffset). If the miniport driver must call such routines to restart its HBA, it must also implement **ScsiSetRunningConfig**.

If the miniport driver does not implement **ScsiRestartAdapter**, the Storport driver calls the miniport driver's [**HwStorFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) and [**HwStorInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_initialize) routines. However, because such routines might do detection work unnecessary for restarting the HBA, such a miniport driver will not power up its HBA as quickly as a miniport driver that implements **ScsiRestartAdapter**.

### `ScsiSetBootConfig`

Restores any settings on an HBA that the BIOS might need to reboot. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL) after calling this routine with **ScsiStopAdapter**.

A miniport driver must implement **ScsiSetBootConfig** if it must call [**StorPortGetBusData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetbusdata) or [**StorPortSetBusDataByOffset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetbusdatabyoffset) before the system will be able to reboot.

### `ScsiSetRunningConfig`

Restores any settings on an HBA that the miniport driver might need to control the HBA while the system is running. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL) before calling this routine with **ScsiRestartAdapter** if the miniport driver implements that control type.

The HBA's interrupt is not yet connected when the Storport driver makes this call, so the miniport driver must take care not to generate an interrupt.

A miniport driver must implement **ScsiSetRunningConfig** if it must call [**StorPortGetBusData**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportgetbusdata) or [**StorPortSetBusDataByOffset**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetbusdatabyoffset) to restore the appropriate running configuration to the HBA before it can be restarted.

### `ScsiPowerSettingNotification`

Notification for a registered power setting change. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_POWER_SETTING_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_power_setting_info) structure if a power setting change occurs. Miniports register for power setting notifications by calling [**StorPortSetPowerSettingNotificationGuids**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetpowersettingnotificationguids) with a list of GUIDs representing the power change events of interest. This control type is valid in Windows 8 and later.

### `ScsiAdapterPower`

Reports the adapter power on or power off states. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_ADAPTER_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_adapter_control_power) structure. If the miniport supports this control type, it will not receive a storage request block with SRB_FUNCTION_POWER and **HwStorAdapterControl** is not called with the **ScsiStopAdapter** control type. This control type is valid in Windows 8 and later.

### `ScsiAdapterPoFxPowerRequired`

Notifies the miniport whether power is required or not for the adapter component. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a **BOOLEAN** value which is **TRUE** if the adapter component requires power; otherwise, **FALSE.** This control type is valid in Windows 8 and later.

### `ScsiAdapterPoFxPowerActive`

Notifies the miniport whether the adapter component is active or idle. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_POFX_ACTIVE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_active_context) structure. This control type is valid in Windows 8 and later.

### `ScsiAdapterPoFxPowerSetFState`

 Notifies the miniport to set the adapter component to the given F-state. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a[**STOR_POFX_FSTATE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_fstate_context) structure. This control type is valid in Windows 8 and later.

### `ScsiAdapterPoFxPowerControl`

Requests that the miniport execute a private power control operation that was initiated for the adapter by a power engine plug-in (PEP). The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_POFX_POWER_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_power_control) structure. This control type is valid in Windows 8 and later.

### `ScsiAdapterPrepareForBusReScan`

Notifies the miniport to prepare the adapter for bus enumeration. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL). The miniport should power on the adapter and all connected devices to allow the bus enumeration operation to find the devices. This control type is valid in Windows 8 and later.

### `ScsiAdapterSystemPowerHints`

Provides system power hints to the miniport. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_SYSTEM_POWER_HINTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_system_power_hints) structure. This control type is valid in Windows 8 and later.

### `ScsiAdapterFilterResourceRequirements`

Filters the required resources for the adapter. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this [IRP_MN_FILTER_RESOURCE_REQUIREMENTS](https://learn.microsoft.com/windows-hardware/drivers/kernel/irp-mn-filter-resource-requirements) control type and **Parameters** pointing to a [**STOR_FILTER_RESOURCE_REQUIREMENTS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_filter_resource_requirements) structure when Storport processes the request and miniport has the STOR_FEATURE_ADAPTER_CONTROL_PRE_FINDADAPTER flag set in the **FeatureSupport** field of [**HW_INITIALIZATION_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_hw_initialization_data-r1). Note that the **DeviceExtension** passed in for this control type will be uninitialized.

The miniport driver should change or reduce the resources described in the buffer using the **STOR_FILTER_RESOURCE_REQUIREMENTS** structure. This control type is valid in Windows 8.1 and later.

### `ScsiAdapterPoFxMaxOperationalPower`

Communicates a maximum operational power value to the miniport. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_MAX_OPERATIONAL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_max_operational_power) structure. To receive this control, the miniport must have previously called [**StorPortPoFxSetPerfState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxsetperfstate) to register a perf set with **PStateType** = **StorPoFxPerfStateTypeDiscrete** and **Count** > 1.

The **Value** field in each power state (P-State) must represent a maximum power level that is relative in proportion to the other P-States and will be within the range of maximum power levels reported by the miniport's P-States, inclusive. The miniport must ensure it chooses a power state whose maximum power consumption is less than or equal to the value given in this parameter.

### `ScsiAdapterPoFxSetPerfState`

Informs the miniport of the status of a P-State transition requested by a call to [**StorPortPoFxSetPerfState**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportpofxsetperfstate). The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_POFX_PERF_STATE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_perf_state_context) structure.

If the miniport needs to initiate a physical power state transition, it should wait for the **HwStorAdapterControl** callback before doing so. That is, a miniport must first call **StorPortPoFxSetPerfState** to signal its intent to make a P-State transition. Storport will then call the miniport's **HwStorAdapterControl** callback, at which point the miniport can take any actions related to the P-State transition (such as changing the physical power state of the device).

### `ScsiAdapterSurpriseRemoval`

Notifies the miniport that the unit has been surprise-removed. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type (and **Parameters** set to NULL).

### `ScsiAdapterSerialNumber`

Requests that the miniport retrieve the adapter's serial number. The Storport driver calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with this control type and **Parameters** pointing to a [**STOR_SERIAL_NUMBER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_serial_number) structure.

### `ScsiAdapterCryptoOperation`

Reserved for system use. Notifies the miniport to perform a cryptographic operation. Storport calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with it and **Parameters** pointing to a [**STOR_CRYPTO_OPERATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_crypto_operation).

### `ScsiAdapterQueryFruId`

Available starting in Windows 10 version 21H1. Queries the ID of a fault replacement unit (FRU) of the adapter. Storport calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with it and **Parameters** pointing to a [**STOR_FRU_ID_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_fru_id_description) structure when handling [**IOCTL_STORAGE_QUERY_PROPERTY**]ni-ntddstor-ioctl_storage_query_property.md) with a **StorageFruIdProperty** property ID.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureFruIdAdapterControl** specified.

### `ScsiAdapterSetEventLogging`

Available starting in Windows 10 version 21H1. Notifies the miniport about whether a specific event channel is enabled or disabled for an adapter. A miniport should then call an API to log an event for the adapter only when the corresponding channel is enabled. If the miniport supports this control type, Storport calls [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) with it and **Parameters** pointing to a [**STOR_SET_EVENT_LOGGING**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_set_event_logging) structure.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureFruIdAdapterControl** specified.

### `ScsiAdapterReportInternalData`

Reserved for system use. Available starting in Windows 11, version 22H2.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **ScsiAdapterReportInternalData** specified.

### `ScsiAdapterResetBusSynchronous`

Available starting in Windows 11, version 22H2. Storport sends this control during the handling of an IOCTL_STORAGE_DEVICE_RESET. The miniport driver should handle this control similar to what it does in its [**HwResetBus**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_reset_bus) callback routine, and should return SCSI_ADAPTER_CONTROL_STATUS.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureResetBusSynchronous** specified.

### `ScsiAdapterPostHwInitialize`

Reserved for system use. Available starting in Windows 11, version 22H2.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeaturePostHwInitialize** specified.

### `ScsiAdapterPrepareEarlyDumpData`

Reserved for system use. Available starting in Windows 11, version 22H2.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeaturePrepareEarlyDumpData** specified.

### `ScsiAdapterRestoreEarlyDumpData`

Reserved for system use. Available starting in Windows 11, version 22H2.

Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureRestoreEarlyDumpData** specified.

### `ScsiAdapterKsrPowerDown`

Reserved for internal use. Do not use.

### `ScsiAdapterPreparePLDR`

Storport sends this control to notify miniport to do necessary work before invoking PLDR. Available starting in Windows 11, version 24H2.

### `ScsiNvmeofAdapterOperation`

Indicates whether ScsiNvmeofAdapterOperation is supported. Available starting in Windows 11, version 24H2.

### `ScsiAdapterControlMax`

Maximum control type value.

### `MakeAdapterControlTypeSizeOfUlong`

Makes this enumeration the size of a ULONG.

## Remarks

A miniport reports which control types it supports when Storport calls the miniport's [**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control) routine with a control type of **ScsiQuerySupportedControlTypes**. For those control types that the miniport supports, Storport calls **HwStorAdapterControl** with a **SCSI_ADAPTER_CONTROL_TYPE** value to indicate the control operation that specifies the adapter control operation to be performed by the miniport.

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)