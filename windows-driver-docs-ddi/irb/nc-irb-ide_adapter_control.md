# IDE_ADAPTER_CONTROL callback function

## Description

The *AtaAdapterControl* miniport driver routine is called to perform Plug and Play (PnP) and Power Management operations on the HBA.

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Parameters

### `ControllerExtension` [in]

A pointer to the controller extension.

### `ControlAction` [in]

One of five actions that the miniport driver must perform as defined in the following table.
| ControlAction | Parameters | Description |
| ------------- | ---------- | ----------- |
| IdeStart | IDE_CONTROLLER_CONFIGURATION | Indicates that the adapter is being started. The miniport driver should update the member in the [**IDE_CONTROLLER_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_configuration) structure. If it is required, the miniport driver could obtain its hardware resources from the **IDE_CONTROLLER_CONFIGURATION** structure. |
| IdeStop | None | The miniport driver should stop using any resources that are allocated for this controller. Be aware that the port driver guarantees that all the channels that are exposed by the adapter are stopped before it stops the adapter. |
| IdePowerUp | None | Indicates that the adapter is being turned on. Anything that does not persist across a power cycle must be configured during IdePowerUp. |
| IdePowerDown | None | Indicates that the adapter is being turned off. |
| IdeVendorDefined | None | Indicates that the miniport driver should perform a vendor-defined control action. |

### `Parameters` [in, out]

Parameters associated with the given action.

## Return value

The miniport driver must return **TRUE** to acknowledge the completion of the requested action. A return value of **FALSE** indicates that the miniport driver was unable to complete the action successfully. A return value of **FALSE** for certain actions might cause the device installation to fail.

## Remarks

The port driver guarantees that there is no outstanding I/O on the adapter before it invokes the *AtaAdapterControl* routine.

## See also

[**IDE_CONTROLLER_CONFIGURATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/irb/ns-irb-_ide_controller_configuration)