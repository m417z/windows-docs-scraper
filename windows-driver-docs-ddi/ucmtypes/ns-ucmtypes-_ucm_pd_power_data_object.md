# _UCM_PD_POWER_DATA_OBJECT structure

## Description

Describes a Power Data Object. For information about these members, see the [Power Delivery specification](https://www.usb.org/documents?search=&tid_2%5B0%5D=40&items_per_page=50).

## Members

### `Ul`

Size of the structure.

### `Common`

### `Common.Reserved`

Reserved.

### `Common.Type`

Type of Power Data Object.

### `FixedSupplyPdo`

Describing a Fixed Supply type Power Data Object.

### `FixedSupplyPdo.MaximumCurrentIn10mA`

Maximum current in multiples of 10 mA.

### `FixedSupplyPdo.VoltageIn50mV`

Voltage in multiples of 50 mV.

### `FixedSupplyPdo.PeakCurrent`

Peak current.

### `FixedSupplyPdo.Reserved`

Reserved for future use.

### `FixedSupplyPdo.DataRoleSwap`

If set, indicates the Power Data Object can perform a data role swap.

### `FixedSupplyPdo.UsbCommunicationCapable`

If set, indicates the Power Data Object is USB communication capable.

### `FixedSupplyPdo.ExternallyPowered`

If set, indicates the Power Data Object is externally powered.

### `FixedSupplyPdo.UsbSuspendSupported`

Indicates support for USB suspend.

### `FixedSupplyPdo.DualRolePower`

Dual role power

### `FixedSupplyPdo.FixedSupply`

fixed supply

### `VariableSupplyNonBatteryPdo`

Contains bitfields describing a variable-supply non-battery PD object.

### `VariableSupplyNonBatteryPdo.MaximumCurrentIn10mA`

Describes the maximum current in multiples of 10 mA.

### `VariableSupplyNonBatteryPdo.MinimumVoltageIn50mV`

Describes the minimum voltage in multiples of 50 mV.

### `VariableSupplyNonBatteryPdo.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 50 mV.

### `VariableSupplyNonBatteryPdo.VariableSupportNonBattery`

Variable Support Non Battery type.

### `BatterySupplyPdo`

Contains bitfields describing a battery supply PD object.

### `BatterySupplyPdo.MaximumAllowablePowerIn250mW`

Describes the maximum allowable power in multiples of 250 mW.

### `BatterySupplyPdo.MinimumVoltageIn50mV`

Describes the minimum voltage in multiples of 50 mV.

### `BatterySupplyPdo.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 50 mV.

### `BatterySupplyPdo.Battery`

Battery type.