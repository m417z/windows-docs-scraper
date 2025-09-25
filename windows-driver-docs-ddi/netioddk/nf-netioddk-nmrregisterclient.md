# NmrRegisterClient function

## Description

The
**NmrRegisterClient** function registers a client module with the NMR.

## Parameters

### `ClientCharacteristics` [in]

A pointer to an
[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics) structure that describes the characteristics of the client module. The
client module must make sure that this structure remains valid and resident in memory as long as the
client module is registered with the NMR.

### `ClientContext` [in]

A pointer to a caller-supplied context for the registration. The client module uses this context
to keep track of the state of the client registration. The contents of the client module's registration
context are opaque to the NMR. The NMR passes this pointer to the client module whenever it calls the
client module's
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function. The client module must make sure that its registration context remains valid and resident in
memory as long as the client module is registered with the NMR.

### `NmrClientHandle` [out]

A pointer to a variable that receives a handle used by the NMR to represent the registration of
the client module. The client module must save this handle and pass it as a parameter to the
[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient) function when it
deregisters from the NMR.

## Return value

The
**NmrRegisterClient** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The NMR successfully registered the client module. |
| **STATUS_INSUFFICIENT_RESOURCES** | The NMR did not have sufficient system resources to register the client module. |
| **Other status codes** | An error occurred. |

## Remarks

A client module calls the
**NmrRegisterClient** function to register as a client of an
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) so that it can attach to
provider modules that register as providers of the same
NPI.

A client module typically calls the
**NmrRegisterClient** function from its
[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver) function after it has completed
all other initialization tasks. The call to the
**NmrRegisterClient** function indicates to the NMR that the client module is ready to attach to any
provider modules that have registered or will register as providers of the same
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) for which the client module
has registered as a client.

## See also

[DriverEntry](https://learn.microsoft.com/windows-hardware/drivers/storage/driverentry-of-ide-controller-minidriver)

[NPI_CLIENT_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_client_characteristics)

[NmrDeregisterClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrderegisterclient)