# PHYSICAL_MONITOR structure

## Description

Contains a handle and text description corresponding to a physical monitor.

## Members

### `hPhysicalMonitor`

Handle to the physical monitor.

### `szPhysicalMonitorDescription`

Text description of the physical monitor.

## Remarks

A physical monitor description is always an array of 128 characters.

## See also

[GetPhysicalMonitorsFromHMONITOR](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromhmonitor)

[GetPhysicalMonitorsFromIDirect3DDevice9](https://learn.microsoft.com/windows/desktop/api/physicalmonitorenumerationapi/nf-physicalmonitorenumerationapi-getphysicalmonitorsfromidirect3ddevice9)

[Monitor Configuration Structures](https://learn.microsoft.com/windows/desktop/Monitor/monitor-configuration-structures)