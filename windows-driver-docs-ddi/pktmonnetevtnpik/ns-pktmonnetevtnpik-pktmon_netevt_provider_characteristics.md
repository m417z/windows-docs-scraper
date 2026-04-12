## Description

The **PKTMON_NETEVT_PROVIDER_CHARACTERISTICS** structure defines the characteristics of a Packet Monitor NetEvt NMR provider module. This structure is used during provider registration to describe the provider's capabilities and properties to the Network Module Registrar (NMR).

## Members

### `Header`

A **[PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header)** structure containing version and size information for this characteristics structure. The *Header* field ensures proper structure versioning and compatibility between provider and client modules.

## Remarks

Provider modules populate this structure when registering with the NMR to advertise their capabilities. The structure must remain valid and resident in memory as long as the provider is registered with the NMR.

## See also

- [PKTMON_HEADER](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnpik/ns-pktmonnpik-pktmon_header)
- [PKTMON_NETEVT_PROVIDER_DISPATCH](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonnetevtnpik/ns-pktmonnetevtnpik-pktmon_netevt_provider_dispatch)
- [NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider)