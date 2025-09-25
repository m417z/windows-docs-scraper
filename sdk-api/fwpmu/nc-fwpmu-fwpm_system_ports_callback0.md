# FWPM_SYSTEM_PORTS_CALLBACK0 callback function

## Description

The **FWPM_SYSTEM_PORTS_CALLBACK0** function is used to add custom behavior to the system port subscription process.

## Parameters

### `context` [in, out]

Type: **void***

Optional context pointer. It contains the value of the *context* parameter of the [FwpmSystemPortsSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsystemportssubscribe0) function.

### `sysPorts` [in]

Type: [FWPM_SYSTEM_PORTS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports0)*

The system port information.

## Remarks

Call [FwpmSystemPortsSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsystemportssubscribe0) to register this callback function.

**FWPM_SYSTEM_PORTS_CALLBACK0** is a specific implementation of FWPM_SYSTEM_PORTS_CALLBACK. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_SYSTEM_PORTS0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_system_ports0)

[FwpmSystemPortsSubscribe0](https://learn.microsoft.com/windows/desktop/api/fwpmu/nf-fwpmu-fwpmsystemportssubscribe0)