# _UCM_PD_REQUEST_DATA_OBJECT structure

## Description

Describes a Request Data Object (RDO). For information about these members, see the [Power Delivery specification](https://www.usb.org/documents?search=&tid_2%5B0%5D=40&items_per_page=50).

## Members

### `Ul`

Size of the structure.

### `Common`

### `Common.Reserved1`

Reserved.

### `Common.ObjectPosition`

Object position.

### `Common.Reserved2`

Reserved.

### `FixedAndVariableRdo`

### `FixedAndVariableRdo.MaximumOperatingCurrentIn10mA`

Maximum current in 10 mA units.

### `FixedAndVariableRdo.OperatingCurrentIn10mA`

Operating current in 10mA units.

### `FixedAndVariableRdo.Reserved1`

Reserved.

### `FixedAndVariableRdo.NoUsbSuspend`

Indicates support for USB suspend.

### `FixedAndVariableRdo.UsbCommunicationCapable`

USB communication capable.

### `FixedAndVariableRdo.CapabilityMismatch`

Capability Mismatch

### `FixedAndVariableRdo.GiveBackFlag`

GiveBack Flag.

### `FixedAndVariableRdo.ObjectPosition`

Object Position.

### `FixedAndVariableRdo.Reserved2`

Reserved for future use.

### `BatteryRdo`

### `BatteryRdo.MaximumOperatingPowerIn250mW`

Maximum Operating Power in 250mW units.

### `BatteryRdo.OperatingPowerIn250mW`

Operating Power in 250mW units.

### `BatteryRdo.Reserved1`

Reserved for future use.

### `BatteryRdo.NoUsbSuspend`

 USB Suspend.

### `BatteryRdo.UsbCommunicationCapable`

USB Communications Capable.

### `BatteryRdo.CapabilityMismatch`

Capability Mismatch.

### `BatteryRdo.GiveBackFlag`

GiveBack Flag.

### `BatteryRdo.ObjectPosition`

Object Position.

### `BatteryRdo.Reserved2`

Reserved.