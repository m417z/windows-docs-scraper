# NmrRegisterProvider function

## Description

The
**NmrRegisterProvider** function registers a provider module with the NMR.

## Parameters

### `ProviderCharacteristics` [in]

A pointer to an
[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics) structure that describes the characteristics of the provider module.
The provider module must make sure that this structure remains valid and resident in memory as long as
the provider module is registered with the NMR.

### `ProviderContext` [in]

A pointer to a caller-supplied context for the registration. The provider module uses this context
to keep track of the state of the provider registration. The contents of the provider module's
registration context are opaque to the NMR. The NMR passes this pointer to the provider module whenever
it calls the provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function. The provider module must make sure that this context remains valid and resident in memory as
long as the provider module is registered with the NMR.

### `NmrProviderHandle` [out]

A pointer to a variable that receives a handle used by the NMR to represent the registration of
the provider module. The provider module must save this handle and pass it as a parameter to the
[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider) function when
it deregisters from the NMR.

## Return value

The
**NmrRegisterProvider** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The NMR successfully registered the provider module. |
| **STATUS_INSUFFICIENT_RESOURCES** | The NMR did not have sufficient system resources to register the provider module. |
| **Other status codes** | An error occurred. |

## Remarks

A provider module calls the
**NmrRegisterProvider** function to register as a provider of an
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) so that it can attach to
client modules that register as clients of the same
NPI.

A provider module typically calls the
**NmrRegisterProvider** function from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function after it has completed
all other initialization tasks. The call to the
**NmrRegisterProvider** function indicates to the NMR that the provider module is ready to attach to
any client modules that have registered or will register as clients of the same
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which the provider module
has registered as a provider.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics)

[NmrDeregisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterprovider)