# RILC2KMRL structure (ntddrilapitypes.h)

## Description

**Warning** The Cellular COM API is deprecated in Windows 10. This content is provided to support maintenance of OEM and mobile operator created Windows Phone 8.1 applications.

This structure represents a RILC2KMRL.

## Members

### `dwParams`

A bitwise combination of RILC2KMRLPARAMMASK enumeration values that indicates which members of the structure contain valid data. A member of the structure is valid if the corresponding bit flag is set.

### `fServing`

Indicates whether this is a serving cell. There may be more than one serving cell at a time.

### `dwNID`

Network ID (0...65535).

### `dwSID`

System ID (0...32767).

### `dwBaseStationID`

Base station ID (0...65535).

### `dwBaseLat`

Base station Latitude (0...4194303) encoded in units of 0.25 seconds, expressed in two’s complement representation within the low 22 bits of the DWORD. This is a signed field with North latitudes represented by positive values.

### `dwBaseLong`

Base station Longitude (0...8388607) encoded in units of 0.25 seconds, expressed in two’s complement representation within the low 23 bits of the DWORD. This is a signed field with East longitudes represented by positive values.

### `dwRefPN`

Base station PN number (0...511).

### `dwGPSSeconds`

GPS seconds; the time at which this arrived from the base station.

### `dwPilotStrength`

Signal strength of pilot (0...63).

## Syntax

```cpp
struct RILC2KMRL {
  DWORD dwParams;
  BOOL  fServing;
  DWORD dwNID;
  DWORD dwSID;
  DWORD dwBaseStationID;
  DWORD dwBaseLat;
  DWORD dwBaseLong;
  DWORD dwRefPN;
  DWORD dwGPSSeconds;
  DWORD dwPilotStrength;
};
```

## See also

[Cellular COM structures](https://learn.microsoft.com/previous-versions/windows/hardware/cellular/dn946511(v=vs.85))