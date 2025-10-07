# BATTERY\_INFORMATION structure

Contains battery information. This structure is returned by the [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information) control code when the BatteryInformation information level is requested.

## Members

**Capabilities**

The battery capabilities. This member can be one or more of the following values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**BATTERY\_CAPACITY\_RELATIVE**

0x40000000

| Indicates that the battery capacity and rate information are relative, and not in any specific units. If this bit is not set, the reporting units are milliwatt-hours (mWh) for capacity and milliwatts (mW) for rate. If this bit is set, all references to units in the other battery documentation can be ignored. All rate information is reported in units per hour. For example, if the fully charged capacity is reported as 100, a rate of 200 indicates that the battery will use all of its capacity in half an hour.<br> |
|

**BATTERY\_IS\_SHORT\_TERM**

0x20000000

| Indicates that the normal operation is for a fail-safe function. If this bit is not set the battery is expected to be used during normal system usage.<br> |
|

**BATTERY\_SET\_CHARGE\_SUPPORTED**

0x00000001

| Indicates that set information requests of the type BatteryCharge are supported by this battery device.<br> |
|

**BATTERY\_SET\_DISCHARGE\_SUPPORTED**

0x00000002

| Indicates that set information requests of the type BatteryDischarge are supported by this battery device.<br> |
|

**BATTERY\_SYSTEM\_BATTERY**

0x80000000

| Indicates that the battery can provide general power to run the system.<br> |

**Technology**

The battery technology. This member can be one of the following values.

| Value | Meaning |
|------------------------------------------------------------------------------|------------------------------------------------------------|
| 0 | Nonrechargeable battery, for example, alkaline.<br> |
| 1 | Rechargeable battery, for example, lead acid.<br> |

**Reserved**

Reserved.

**Chemistry**

An abbreviated character string that indicates the battery's chemistry. This string is not necessarily zero-terminated. The following is a partial list of abbreviations that can be returned and the associated chemistries.

| Unicode string | Meaning |
|----------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------|
|

**PbAc**

| Lead Acid<br> |
|

**LION**

| Lithium Ion<br> |
|

**Li-I**

| Lithium Ion<br> |
|

**NiCd**

| Nickel Cadmium<br> |
|

**NiMH**

| Nickel Metal Hydride<br> |
|

**NiZn**

| Nickel Zinc<br> |
|

**RAM**

| Rechargeable Alkaline-Manganese<br> |

Other chemistries may appear in the future and your code should be able to handle them.

**DesignedCapacity**

The theoretical capacity of the battery when new, in mWh unless BATTERY\_CAPACITY\_RELATIVE is set. In that case, the units are undefined.

**FullChargedCapacity**

The battery's current fully charged capacity in mWh (or relative). Compare this value to **DesignedCapacity** to estimate the battery's wear.

**DefaultAlert1**

The manufacturer's suggested capacity, in mWh, at which a low battery alert should occur. Definitions of low vary from manufacturer to manufacturer. In general, a warning state will occur before a low state, but you should not assume that it always will. To reduce risk of data loss, this value is usually used as the default setting for the critical battery alarm.

**DefaultAlert2**

The manufacturer's suggested capacity, in mWh, at which a warning battery alert should occur. Definitions of warning vary from manufacturer to manufacturer. In general, a warning state will occur before a low state, but you should not assume that it always will. To reduce risk of data loss, this value is usually used as the default setting for the low battery alarm.

**CriticalBias**

A bias from zero, in mWh, which is applied to battery reporting. Some batteries reserve a small charge that is biased out of the battery's capacity values to show "0" as the critical battery level. Critical bias is analogous to setting a fuel gauge to show "empty" when there are several liters of fuel left.

**CycleCount**

The number of charge/discharge cycles the battery has experienced. This provides a means to determine the battery's wear. If the battery does not support a cycle counter, this member is zero.

## Remarks

Generally, a warning state occurs before a low state, but you should not assume it will. It is possible to poll a battery and find that neither alert level has occurred, and poll the battery again and find it discharged to the extent that both levels have been achieved. This may indicate that you are not polling often enough. It may also indicate that the battery is unable to hold a charge for very long and is discharging more rapidly than you expected. Such a battery may be nearing the end of its useful life, or it may be damaged.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information)