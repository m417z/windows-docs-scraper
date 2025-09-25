# FWPM_SYSTEM_PORTS_BY_TYPE0 structure

## Description

The **FWPM_SYSTEM_PORTS_BY_TYPE0** structure contains information about the system ports of a specified type.

## Members

### `type`

An [FWPM_SYSTEM_PORT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_system_port_type) enumeration that specifies the type of port.

### `numPorts`

The number of ports of the specified type.

### `ports`

Array of IP port numbers for the specified type.

## Remarks

**FWPM_SYSTEM_PORTS_BY_TYPE0** is a specific implementation of FWPM_SYSTEM_PORTS_BY_TYPE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SYSTEM_PORT_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_system_port_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)