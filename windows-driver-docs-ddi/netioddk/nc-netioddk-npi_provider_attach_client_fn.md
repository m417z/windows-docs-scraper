# NPI_PROVIDER_ATTACH_CLIENT_FN callback function

## Description

A provider module's
*ProviderAttachClient* callback function attaches the provider module to a client module.

## Parameters

### `NmrBindingHandle` [in]

A handle used by the NMR to represent the binding between the client module and the provider
module.

### `ProviderContext` [in]

A pointer to the provider module's registration context. The provider module passes this pointer
to the NMR when it calls the
[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider) function to
register itself with the NMR.

### `ClientRegistrationInstance` [in]

A pointer to an
[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance) structure. This structure contains the client module's registration
data.

### `ClientBindingContext` [in]

A pointer to the client module's context for the binding between the client module and the
provider module. The client module uses this context to keep track of the state of the binding. The
contents of the client module's binding context are opaque to the provider module. The provider module
passes this pointer to the client module whenever it calls any of the client module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions that
require the client module's binding context.

### `ClientDispatch` [in]

A pointer to a constant structure that contains the dispatch table of
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions for the
client module. The contents of the structure are
NPI-specific. If the
NPI does not define a client
dispatch table structure, then this pointer is **NULL**.

### `ProviderBindingContext` [out]

A pointer to a variable into which the provider module will store a pointer to its context for the
binding between the client module and the provider module. The provider module uses this context to keep
track of the state of the binding. The contents of the provider module's binding context are opaque to
the client module. The client module passes this pointer to the provider module whenever it calls one of
the provider module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions that require the
provider module's binding context. The provider module must make sure that this context remains valid
and resident in memory as long as the client module is attached to the provider module.

### `ProviderDispatch` [out]

A pointer to a variable into which the provider module will store a pointer to a constant
structure that contains the dispatch table of
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions for the provider
module. The provider module must make sure that this structure remains valid and resident in memory as
long as the client module is attached to the provider module. The contents of the structure are
NPI-specific.

## Return value

A provider module's
*ProviderAttachClient* callback function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The provider module successfully attached to the client module. |
| **STATUS_NOINTERFACE** | The provider module did not attach to the client module. |
| **Other status codes** | An error occurred. |

## Remarks

The NMR calls a provider module's
*ProviderAttachClient* callback function whenever a client module calls the
[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider) function
with a handle that represents a binding between the client module and the provider module.

A provider module can examine the client module's registration data. This data is in the structure
pointed to by the
*ClientRegistrationInstance* parameter. The provider module uses this data to determine whether it
will attach to the client module:

* If the provider module determines that it will attach to the client module, then the
  *ProviderAttachClient* callback function must do the following:
  1. Save the pointers passed in the
     *ClientBindingContext* and
     *ClientDispatch* parameters so that the provider module can make calls to the client module's
     [NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions.
  2. Save the handle passed in the
     *NmrBindingHandle* parameter. The provider module passes this handle as a parameter to the
     [NmrProviderDetachClientComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrproviderdetachclientcomplete) function when it detaches from the client module.
  3. Set the
     *ProviderBindingContext* parameter to point to the provider module's binding context structure for
     the binding between the client module and the provider module.
  4. Set the
     *ProviderDispatch* parameter to point to a structure that contains the provider module's dispatch
     table of
     [NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions.
  5. Return STATUS_SUCCESS.
* If the provider module determines that it will not attach to the client module, then the
  *ProviderAttachClient* callback function must return STATUS_NOINTERFACE.

If the provider module attaches to the client module and it dynamically allocated memory for its
binding context, it should free that allocated memory when the NMR calls the provider module's
[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn) callback function after the client module and provider module are
detached from each other.

The NMR calls a provider module's
*ProviderAttachClient* callback function at IRQL = PASSIVE_LEVEL.

## See also

[NPI_PROVIDER_CHARACTERISTICS](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_provider_characteristics)

[NPI_REGISTRATION_INSTANCE](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/ns-netioddk-_npi_registration_instance)

[NmrClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrclientattachprovider)

[NmrProviderDetachClientComplete](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrproviderdetachclientcomplete)

[NmrRegisterProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nf-netioddk-nmrregisterprovider)

[ProviderCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_cleanup_binding_context_fn)

[ProviderDetachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_detach_client_fn)