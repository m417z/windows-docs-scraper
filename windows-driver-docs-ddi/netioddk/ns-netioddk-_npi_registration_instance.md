# _NPI_REGISTRATION_INSTANCE structure

## Description

The NPI_REGISTRATION_INSTANCE structure defines the data related to the registration of a network
module with the NMR.

## Members

### `Version`

The version of the NMR with which the network module is registering. A network module should set
this member to zero.

### `Size`

The size, in bytes, of the NPI_REGISTRATION_INSTANCE structure.

### `NpiId`

A pointer to the
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) identifier for the specific
NPI to which the network module
is registering as either a client or a provider. The NPIID data type is defined as:

```
typedef GUID NPIID;
typedef CONST NPIID *PNPIID;
```

### `ModuleId`

A pointer to an
[NPI_MODULEID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568813(v=vs.85)) structure that uniquely
identifies the network module.

### `Number`

The implementation number of the
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which the network module
is registering as either a client or a provider. A network module can support multiple implementations
of the same
NPI by registering as either a
client or a provider of each implementation of the
NPI. If there is only one
implementation of an
NPI, this member is set to
zero.

### `NpiSpecificCharacteristics`

A pointer to a structure that specifies characteristics that are unique to the network module. The
contents of the structure are
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface)-specific. A network module
should set this member to **NULL** if it is registering as a client of an NPI that does not define a client
characteristics structure or if it is registering as a provider of an NPI that does not define a
provider characteristics structure.

## Remarks

An NPI_REGISTRATION_INSTANCE structure is a member of the
[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics) and
[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics) structures. These structures are used for registering network modules
with the NMR.

When the NMR calls a client module's
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function, it passes a pointer to the NPI_REGISTRATION_INSTANCE structure for the provider module to which
the client module can attach itself. Likewise, when the NMR calls a provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function, it passes a pointer to the NPI_REGISTRATION_INSTANCE structure for the client module to which
the provider module can attach itself.

A network module must make sure that the memory for the NPIID pointed to by the
**NpiId** member, the memory for the
[NPI_MODULEID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568813(v=vs.85)) structure pointed to by the
**ModuleId** member, and the memory for the
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface)-specific characteristics
structure pointed to by the
**NpiSpecificCharacteristics** member remain valid and resident in memory as long as the network module
is registered with the NMR.

## See also

[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn)

[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics)

[NPI_MODULEID](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff568813(v=vs.85))

[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics)

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)