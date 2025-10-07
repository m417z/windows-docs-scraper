# BATTERY\_MANUFACTURE\_DATE structure

Contains the date of manufacture of a battery. This structure is used by the [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) structure when the BatteryManufactureDate information level is requested.

## Members

**Day**

The day of the month of manufacture, in the range 1 to 31. In spite of the data type, this is not an ASCII encoded value. It is an unsigned byte.

**Month**

The month of manufacture, in the range 1 (January) to 12 (December). In spite of the data type, this is not an ASCII encoded value. It is an unsigned byte.

**Year**

The year of manufacture. This will typically be in the range 1900-2100.

## Remarks

The date is encoded in the Gregorian or western calendar format.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Header<br> | Poclass.h;

Batclass.h on Windows Server 2008 R2, Windows 7, Windows Server 2008, Windows Vista, Windows Server 2003 and Windows XP | ## See also [**BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/battery-query-information-str) [**IOCTL\_BATTERY\_QUERY\_INFORMATION**](https://learn.microsoft.com/windows/win32/power/ioctl-battery-query-information)