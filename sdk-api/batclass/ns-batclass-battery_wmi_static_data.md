## Description

Defines static data about a battery.

## Members

### `Tag`

A tag that identifies a specific battery.

### `ManufactureDate`

A [BATTERY_MANUFACTURE_DATE](https://learn.microsoft.com/previous-versions/ff536284(v=vs.85)) structure that specifies the date that the battery was manufactured.

### `Granularity`

Specifies the granularity as a [BATTERY_REPORTING_SCALE](https://learn.microsoft.com/windows-hardware/drivers/ddi/content/wdm/ns-wdm-battery_reporting_scale) value.

### `Capabilities`

Battery capabilities as a ULONG value encoded with one or more of the following flags:

### `Technology`

Specify zero for a primary, nonrechargeable battery, or one for a secondary, rechargeable battery.

### `Chemistry`

A four-character string indicating the type of chemistry used in the battery. Possible values include "PbAc" (Lead Acid), "LION" (Lithium Ion), "NiCd" (Nickel Cadmium), "NiMH" (Nickel Metal Hydride), "NiZn" (Nickel Zinc), and "RAM" (Rechargeable Alkaline-Manganese). Additional values might be returned as additional battery types become available.

### `DesignedCapacity`

The theoretical capacity of the battery when new, in milliwatt-hours. If BATTERY_CAPACITY_RELATIVE is set, the units are undefined.

### `DefaultAlert1`

The capacity, in milliwatt-hours, at which a low battery alert should occur.

### `DefaultAlert2`

The capacity, in milliwatt-hours, at which a warning battery alert should occur.

### `CriticalBias`

Specify the amount, in milliwatt-hours, of any small reserved charge that remains when the critical battery level shows zero. Miniclass drivers should subtract this value from the battery's **FullChargedCapacity** and remaining capacity, which is reported in [BATTERY_STATUS](https://learn.microsoft.com/previous-versions/ff536290(v=vs.85)), before reporting those values.

### `Strings`

Four variable length string values are stored with the first USHORT value containing the length of the string in bytes.

## See also

[BATTERY_MANUFACTURE_DATE](https://learn.microsoft.com/previous-versions/ff536284(v=vs.85))