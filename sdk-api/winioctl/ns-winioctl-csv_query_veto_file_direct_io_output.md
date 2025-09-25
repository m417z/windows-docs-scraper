# CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT structure

## Description

Contains troubleshooting information about why a volume is in redirected mode.

## Members

### `VetoedFromAltitudeIntegral`

The integer portion of VetoedFromAltitude.

### `VetoedFromAltitudeDecimal`

The decimal portion of VetoedFromAltitude.

### `Reason`

The reason why volume is in a redirected mode.

## Remarks

CSV writes the troubleshooting strings to a diagnostic log that, when filtered, can provide hints as to why
a volume is in a redirected mode.

## See also

[Volume Management Structures](https://learn.microsoft.com/windows/desktop/FileIO/volume-management-structures)