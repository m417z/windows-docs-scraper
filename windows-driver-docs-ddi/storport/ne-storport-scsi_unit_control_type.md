## Description

The **SCSI_UNIT_CONTROL_TYPE** enumeration contains unit control operations, where each control type initiates an action on a unit by the miniport driver. Storport specifies the control type when it calls a miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine.

## Constants

### `ScsiQuerySupportedUnitControlTypes`

Reports the unit-control operations implemented by the miniport driver. A miniport must support this control type.

The Storport driver calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**SCSI_SUPPORTED_CONTROL_TYPE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-scsi_supported_control_type_list) structure after the HBA has been initialized but before the first I/O.

The miniport driver fills in the **SCSI_SUPPORTED_CONTROL_TYPE_LIST** structure with the operations that it supports. After **HwStorUnitControl** returns from this call, the Storport driver calls the miniport driver's **HwStorUnitControl** only for operations supported by the miniport.

### `ScsiUnitUsage`

Notifies the miniport whether the logical unit is used for any supported usage types. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_UC_DEVICE_USAGE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_uc_device_usage) structure. Storport will call **HwStorUnitControl** separately for each usage type supported.

### `ScsiUnitStart`

Notifies the miniport to start a unit device. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to the [**STOR_ADDR_BTL8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8) address of the unit to start.

### `ScsiUnitPower`

Reports the unit power on or power off states. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_UNIT_CONTROL_POWER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_unit_control_power) structure. If the miniport supports this control type, it will not receive a storage request block with SRB_FUNCTION_POWER.

### `ScsiUnitPoFxPowerInfo`

Notifies the miniport if idle power management is enabled or disabled on the unit component. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_POFX_UNIT_POWER_INFO**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_unit_power_info) structure. The miniport should call [**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower) within this unit control if idle power management was enabled and if it supports runtime power management for the unit device.

### `ScsiUnitPoFxPowerRequired`

Notifies the miniport whether power is required for the unit component. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a[**STOR_POFX_POWER_REQUIRED_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_power_required_context) structure.

### `ScsiUnitPoFxPowerActive`

Notifies the miniport that the unit component is either active or idle. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_POFX_ACTIVE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_active_context) structure.

### `ScsiUnitPoFxPowerSetFState`

Notifies the miniport to set the unit component to the given functional power state (F-state). Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_POFX_FSTATE_CONTEXT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_fstate_context) structure. The miniport must support this control type if is specifies more than one F-state in the call to [**StorPortInitializePoFxPower**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializepofxpower).

### `ScsiUnitPoFxPowerControl`

Requests that the miniport execute a private power control operation that was initiated for the unit by a power engine plug-in (PEP). Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_POFX_POWER_CONTROL**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_pofx_power_control) structure.

### `ScsiUnitRemove`

Notifies the miniport that the unit has been removed. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to the [**STOR_ADDR_BTL8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8) address of the unit that was removed.

### `ScsiUnitSurpriseRemoval`

Notifies the miniport that the unit has been surprise-removed. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to the [**STOR_ADDR_BTL8**](https://learn.microsoft.com/windows-hardware/drivers/ddi/scsi/ns-scsi-_stor_addr_btl8) address of the unit that was surprise-removed.

### `ScsiUnitRichDescription`

The miniport can choose to support this if the device reports a longer vendor ID, model number, or firmware revision than is defined in the SCSI spec. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_RICH_DEVICE_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-_stor_rich_device_description) structure.

### `ScsiUnitQueryBusType`

Queries whether the miniport wants to specify a bus type for a given logical unit (LUN). Typically the bus type of a LUN and controller have the same bus type, but not always. Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_UNIT_CONTROL_QUERY_BUS_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_unit_control_query_bus_type) structure. Available in Windows 10 version 2004 and later.

> [!NOTE]
> In Windows 10 version 21H1 and later, Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureBusTypeUnitControl** specified.

### `ScsiUnitQueryFruId`

Queries the ID of a fault replacement unit (FRU). If the miniport supports this control type, Storport calls [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) with this control type and **Parameters** pointing to a [**STOR_FRU_ID_DESCRIPTION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_fru_id_description) structure. Available in Windows 10 version 21H1 and later.

> [!NOTE]
> Storport sends this control only if a miniport has also previously called [**StorPortSetFeatureList**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetfeaturelist) in its [**HwFindAdapter**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_find_adapter) routine with **StorportFeatureFruIdUnitControl** specified.

### `ScsiUnitReportInternalData`

Reserved for system use. Available starting in Windows 11, version 22H2.

### `ScsiUnitKsrPowerDown`

Reserved for internal use. Do not use.

### `ScsiUnitControlMax`

Maximum control type value.

### `MakeUnitControlTypeSizeOfUlong`

Makes this enumeration the size of a ULONG.

## Remarks

A miniport reports which control types it supports when Storport calls the miniport's [**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control) routine with a control type of **ScsiQuerySupportedControlTypes**. For those control types that the miniport supports, Storport calls **HwStorUnitControl** with a **SCSI_UNIT_CONTROL_TYPE** value that specifies the unit control operation to be performed by the miniport.

## See also

[**HwStorUnitControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_unit_control)