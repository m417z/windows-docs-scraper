# _USBC_PD_POWER_DATA_OBJECT structure

## Description

Describes a power data object (PDO). For information about these members, see the [Power Delivery specification](https://www.usb.org/documents?search=&tid_2%5B0%5D=40&items_per_page=50).

## Members

### `U`

Size of the structure.

### `Common`

### `Common.Reserved`

Reserved.

### `Common.Type`

Type of power data object.

### `FixedSupplyPdo`

 Describing a fixed supply type power data object.

### `FixedSupplyPdo.MaximumCurrentIn10mA`

Maximum current in multiples of 10 mA.

### `FixedSupplyPdo.VoltageIn50mV`

Voltage in multiples of 50 mV.

### `FixedSupplyPdo.PeakCurrent`

Peak current.

### `FixedSupplyPdo.Reserved1`

Reserved for future use.

### `FixedSupplyPdo.DataRoleSwap`

If set, indicates the power data object can perform a data role swap.

### `FixedSupplyPdo.UsbCommunicationCapable`

If set, indicates the power data object is USB communication capable.

### `FixedSupplyPdo.ExternallyPowered`

If set, indicates the power data object is externally powered.

### `FixedSupplyPdo.UsbSuspendSupported`

Indicates support for USB suspend.

### `FixedSupplyPdo.DualRolePower`

Dual role power.

### `FixedSupplyPdo.FixedSupply`

Fixed supply.

### `BatterySupplyPdo`

Contains bitfields describing a variable-supply non-battery PD object.

### `BatterySupplyPdo.MaximumAllowablePowerIn250mW`

Describes the maximum voltage in multiples of 250mV.

### `BatterySupplyPdo.MinimumVoltageIn50mV`

Describes the minimum voltage in multiples of 50mV.

### `BatterySupplyPdo.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 50mV.

### `BatterySupplyPdo.Battery`

Battery type.

### `VariableSupplyNonBatteryPdo`

Contains bitfields describing a variable-supply non-battery PD object.

### `VariableSupplyNonBatteryPdo.MaximumCurrentIn10mA`

Describes the maximum current in multiples of 10 mA.

### `VariableSupplyNonBatteryPdo.MinimumVoltageIn50mV`

Describes the minimum current in multiples of 50 mA.

### `VariableSupplyNonBatteryPdo.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 10 mA.

### `VariableSupplyNonBatteryPdo.VariableSupportNonBattery`

Variable Support Non Battery type.

### `ProgrammablePowerSupplyApdo`

Describing a programmable power supply augmented power delivery object.

### `ProgrammablePowerSupplyApdo.MaximumCurrentIn50mA`

Describes the maximum current in multiples of 50 mA.

### `ProgrammablePowerSupplyApdo.Reserved1`

Reserved, do not use.

### `ProgrammablePowerSupplyApdo.MinimumVoltageIn100mV`

Describes the minimum voltage in multiples of 100 mV.

### `ProgrammablePowerSupplyApdo.Reserved2`

Reserved, do not use.

### `ProgrammablePowerSupplyApdo.MaximumVoltageIn100mV`

Describes the maximum voltage in multiples of 100 mV.

### `ProgrammablePowerSupplyApdo.Reserved3`

Reserved, do not use.

### `ProgrammablePowerSupplyApdo.PpsPowerLimited`

Power limited supply.

### `ProgrammablePowerSupplyApdo.AugmentedPowerDataObjectType`

Describes a USBC augmented power data object type.

### `ProgrammablePowerSupplyApdo.AugmentedPowerDataObject`

Describes a USBC power data object type.

### `FixedSupplyPdoSink`

Describing a fixed supply type power data object.

### `FixedSupplyPdoSink.OperationalCurrentIn10mA`

Describes the operational current in multiples of 10 mA.

### `FixedSupplyPdoSink.VoltageIn50mV`

Voltage in multiples of 50 mV.

### `FixedSupplyPdoSink.Reserved`

Reserved.

### `FixedSupplyPdoSink.DataRoleSwap`

If set, indicates the power data object can perform a data role swap.

### `FixedSupplyPdoSink.UsbCommunicationCapable`

If set, indicates the power data object is USB communication capable.

### `FixedSupplyPdoSink.ExternallyPowered`

If set, indicates the power data object is externally powered.

### `FixedSupplyPdoSink.HigherCapability`

Power data object has a higher capability.

### `FixedSupplyPdoSink.DualRolePower`

Dual role power.

### `FixedSupplyPdoSink.FixedSupply`

Fixed supply.

### `BatterySupplyPdoSink`

Contains bitfields describing a variable-supply non-battery PD object.

### `BatterySupplyPdoSink.OperationalPowerIn250mW`

Describes the maximum voltage in multiples of 250mV.

### `BatterySupplyPdoSink.MinimumVoltageIn50mV`

Describes the minimum voltage in multiples of 50mV.

### `BatterySupplyPdoSink.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 50mV.

### `BatterySupplyPdoSink.Battery`

Battery type.

### `VariableSupplyNonBatteryPdoSink`

Contains bit fields describing a battery supply power data object.

### `VariableSupplyNonBatteryPdoSink.OperationalCurrentIn10mA`

Describes the operational current in multiples of 10 mA.

### `VariableSupplyNonBatteryPdoSink.MinimumVoltageIn50mV`

Describes the minimum voltage in multiples of 50mV.

### `VariableSupplyNonBatteryPdoSink.MaximumVoltageIn50mV`

Describes the maximum voltage in multiples of 50mV.

### `VariableSupplyNonBatteryPdoSink.VariableSupportNonBattery`

Variable Support Non Battery type.

## Remarks

## See also