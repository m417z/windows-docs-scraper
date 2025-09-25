# _USBC_PD_REQUEST_DATA_OBJECT structure

## Description

Describes a request data object (RDO). For information about these members, see the [Power Delivery specification](https://www.usb.org/documents?search=&tid_2%5B0%5D=40&items_per_page=50).

## Members

### `U`

Size of the structure.

### `Common`

### `Common.Reserved1`

Reserved, do not use.

### `Common.ObjectPosition`

Object position.

### `Common.Reserved2`

Reserved, do not use.

### `FixedAndVariableRdo`

Contains bit fields describing a request data object.

### `FixedAndVariableRdo.MaximumOperatingCurrentIn10mA`

Maximum current in 10 mA units.

### `FixedAndVariableRdo.OperatingCurrentIn10mA`

Operating current in 10 mA units.

### `FixedAndVariableRdo.Reserved1`

Reserved, do not use.

### `FixedAndVariableRdo.CapabilityMismatch`

Capability mismatch

### `FixedAndVariableRdo.GiveBackFlag`

Giveback flag.

### `FixedAndVariableRdo.ObjectPosition`

Object position.

### `FixedAndVariableRdo.Reserved2`

Reserved, do not use.

### `BatteryRdo`

Contains bit fields describing a request data object.

### `BatteryRdo.MaximumOperatingPowerIn250mW`

Maximum operating power in 250 mW units.

### `BatteryRdo.OperatingPowerIn250mW`

Operating power in 250 mW units.

### `BatteryRdo.Reserved1`

Reserved, do not use.

### `BatteryRdo.CapabilityMismatch`

Capability mismatch.

### `BatteryRdo.GiveBackFlag`

Giveback flag.

### `BatteryRdo.ObjectPosition`

Object position.

### `BatteryRdo.Reserved2`

Reserved, do not use.

### `ProgrammableRdo`

Describes a programmable request data object.

### `ProgrammableRdo.OperatingCurrentIn50mA`

Operating current in 50 mA units.

### `ProgrammableRdo.Reserved1`

Reserved, do not use.

### `ProgrammableRdo.OutputVoltageIn20mV`

Output voltage in 20 mV units.

### `ProgrammableRdo.Reserved2`

Reserved, do not use.

### `ProgrammableRdo.UnchunkedExtendedMessagesSupported`

Supports unchunked extended messages.

### `ProgrammableRdo.Reserved3`

Reserved, do not use.

### `ProgrammableRdo.CapabilityMismatch`

Capability mismatch.

### `ProgrammableRdo.Reserved4`

Reserved, do not use.

### `ProgrammableRdo.ObjectPosition`

Object position.

### `ProgrammableRdo.Reserved5`

Reserved, do not use.

## Remarks

## See also