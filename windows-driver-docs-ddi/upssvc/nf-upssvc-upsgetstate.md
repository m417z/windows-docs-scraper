# UPSGetState function

## Description

The **UPSGetState** function returns the operational state of the UPS.

## Return value

The **UPSGetState** function returns one of the following DWORD values:

| Return code | Description |
| --- | --- |
| **UPS_ONLINE** | Utility-supplied power is normal. |
| **UPS_ONBATTERY** | Utility-supplied power is inadequate, and the UPS batteries are discharging. |
| **UPS_LOWBATTERY** | Utility-supplied power is inadequate, and the UPS batteries are critically low. |
| **UPS_NOCOMM** | Communication with the UPS is not currently established. |

## Remarks

This is a nonblocking call.