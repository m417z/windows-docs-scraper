## Description

The **PO_EFFECTIVE_POWER_MODE_CALLBACK** is the effective power mode callback.

## Parameters

### `Mode`

Indicates the effective power mode the system is running in. For more information, see [**PO_EFFECTIVE_POWER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-po_effective_power_mode).

### `Context`

User-specified opaque context. This context would have been passed in at registration in [PoRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterforeffectivepowermodenotifications).

## Remarks

Immediately after registration, this callback is invoked with the current value of the power setting. If the registration occurs while the power setting is changing, you may receive multiple callbacks. The last callback is the most recent update.

## See also

[**PO_EFFECTIVE_POWER_MODE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-po_effective_power_mode)

[PoRegisterForEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-poregisterforeffectivepowermodenotifications)

[PoUnregisterFromEffectivePowerModeNotifications](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-pounregisterfromeffectivepowermodenotifications)