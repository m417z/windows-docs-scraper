## Description

Battery miniclass drivers fill in this structure in response to certain [BatteryMiniQueryInformation](https://learn.microsoft.com/windows/win32/api/batclass/nc-batclass-bclass_query_information_callback) requests.

## Members

### `Granularity`

Specify the granularity of the **Capacity** value, in milliwatt-hours. For most batteries, this value describes a monotonically increasing scale of capacity. For lithium-ion batteries, this value describes one of two possible scales: a gross measure of battery capacity, with a large granularity, or a finer measure as the capacity approaches zero.

### `Capacity`

Specify the battery capacity described by the corresponding granularity, in milliwatt-hours.

## See also

[BatteryMiniQueryInformation](https://learn.microsoft.com/windows/win32/api/batclass/nc-batclass-bclass_query_information_callback)