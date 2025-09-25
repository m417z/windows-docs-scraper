# HW_UNIT_CONTROL callback function

## Description

A miniport driver's **HwStorUnitControl** routine is called to perform synchronous operations to control the state of storage unit device.

## Parameters

### `DeviceExtension` [in]

A pointer to the miniport driver's per-unit storage area.

### `ControlType` [in]

A [**SCSI_UNIT_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_unit_control_type) value that specifies a unit control operation, where each control type initiates an action by the miniport driver. See **SCSI_UNIT_CONTROL_TYPE** for details.

### `Parameters` [in]

Pointer to a structure or value that contains information related to the **ControlType**. All structures are caller-allocated. See [**SCSI_UNIT_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_unit_control_type) for details.

#### Address

The address of the unit the control operation is specified for.

## Return value

Depending on the control type, **HwStorUnitControl** returns one of the following **SCSI_UNIT_CONTROL_STATUS** values:

| Return code | Description |
| ----------- | ----------- |
| **ScsiUnitControlSuccess** | The miniport driver completed the requested operation successfully. |
| **ScsiUnitControlUnsuccessful** | The unit control operation was not successful. |

## Remarks

Storport calls a miniport's **HwStorUnitControl** with a **ScsiQuerySupportedControlTypes** control type after the HBA has been initialized but before the first I/O. The miniport driver fills in the [**SCSI_SUPPORTED_CONTROL_TYPE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-scsi_supported_control_type_list) structure at **Parameters** with the operations that it supports. After **HwStorUnitControl** returns from this call, the Storport driver calls the miniport driver's **HwStorAdapterControl** callback only for operations supported by the miniport.

Storport calls **HwStorUnitControl** to notify the miniport driver of a change to the unit device identified by **Address**, or that the miniport should perform a query or set operation on that unit, such as starting a unit or handling a power control operation for a unit.

The following table lists the current IRQL and the spinlock acquired when the control type is issued.

| Control Type | IRQL | Spin lock |
| ------------ | ---- | --------- |
| **ScsiQuerySupportedControlTypes** | PASSIVE_LEVEL | None |
| **ScsiUnitUsage** | PASSIVE_LEVEL | None |
| **ScsiUnitStart** | PASSIVE_LEVEL | None |
| **ScsiUnitPower** | DISPATCH_LEVEL | None |
| **ScsiUnitPoFxPowerInfo** | PASSIVE_LEVEL | None |
| **ScsiUnitPoFxPowerRequired** | DISPATCH_LEVEL | None |
| **ScsiUnitPoFxPowerActive** | DISPATCH_LEVEL | None |
| **ScsiUnitPoFxPowerSetFState** | DISPATCH_LEVEL | None |
| **ScsiUnitPoFxPowerControl** | DISPATCH_LEVEL | None |
| **ScsiUnitRemove** | PASSIVE_LEVEL | None |
| **ScsiUnitSurpriseRemoval** | PASSIVE_LEVEL | None |
| **ScsiUnitRichDescription** | PASSIVE_LEVEL | None |
| **ScsiUnitQueryBusType** | PASSIVE_LEVEL | None |
| **ScsiUnitQueryFruId** | PASSIVE_LEVEL | None |

The name **HwStorUnitControl** is just a placeholder. The actual prototype of this routine is defined in *storport.h* as follows:

``` C
typedef
SCSI_UNIT_CONTROL_STATUS
HW_UNIT_CONTROL (
  _In_ PVOID  DeviceExtension,
  _In_ SCSI_UNIT_CONTROL_TYPE  ControlType,
  _In_ PVOID  Parameters
  );
```

## See also

[**HwStorAdapterControl**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nc-storport-hw_adapter_control)

[**SCSI_SUPPORTED_CONTROL_TYPE_LIST**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-scsi_supported_control_type_list)

[**SCSI_UNIT_CONTROL_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ne-storport-scsi_unit_control_type)