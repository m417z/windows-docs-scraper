# FWPM_SYSTEM_PORTS0 structure

## Description

The **FWPM_SYSTEM_PORTS0** structure contains information about all of the system ports of all types.

## Members

### `numTypes`

The number of types in the array.

### `types`

A [FWPM_SYSTEM_PORTS_BY_TYPE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports_by_type0) structure that specifies the array of system port types.

## Remarks

**FWPM_SYSTEM_PORTS0** is a specific implementation of FWPM_SYSTEM_PORTS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SYSTEM_PORTS_BY_TYPE0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports_by_type0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)