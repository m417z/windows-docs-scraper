# NmrClientAttachProvider function

## Description

The
**NmrClientAttachProvider** function attaches a client module to a provider module.

## Parameters

### `NmrBindingHandle` [in]

A handle used by the NMR to represent the binding between the client module and the provider
module. The NMR passes this handle to the client module when it calls the client module's
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function.

### `ClientBindingContext` [in]

A pointer to a caller-supplied context for the binding between the client module and the provider
module. The client module uses this context to keep track of the state of the binding. The contents of
the client module's binding context are opaque to the provider module. The provider module passes this
pointer to the client module whenever it calls any of the client module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions that
require the client module's binding context. The client module must make sure that this context remains
valid and resident in memory as long as the provider module is attached to the client module.

### `ClientDispatch` [in]

A pointer to a constant structure that contains the dispatch table of
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) callback functions for the
client module. The client module must make sure that this structure remains valid and resident in memory
as long as the provider module is attached to the client module. The contents of the structure are
NPI-specific. If the
NPI does not define a client
dispatch table structure, the client module must set this parameter to **NULL**.

### `ProviderBindingContext` [out]

A pointer to a variable that receives a pointer to the provider module's context for the binding
between the client module and the provider module. The provider module uses this context to keep track
of the state of the binding. The contents of the provider module's binding context are opaque to the
client module. The client module passes this pointer to the provider module whenever it calls any of the
provider module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions that require the
provider module's binding context.

### `ProviderDispatch` [out]

A pointer to a variable that receives a pointer to a structure that contains the dispatch table of
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions for the provider
module. The contents of the structure are
NPI-specific.

## Return value

The
**NmrClientAttachProvider** function returns one of the following NTSTATUS codes:

| Return code | Description |
| --- | --- |
| **STATUS_SUCCESS** | The client module was successfully attached to the provider module. |
| **STATUS_NOINTERFACE** | The provider module did not attach to the client module. |
| **Other status codes** | An error occurred. |

## Remarks

A client module calls the
**NmrClientAttachProvider** function from its
[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn) callback
function to attach itself to a provider module.

When a client module calls the
**NmrClientAttachProvider** function, the NMR calls the provider module's
[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn) callback
function to complete the attachment process. The
**NmrClientAttachProvider** function returns the status code that is returned by the provider module's
*ProviderAttachClient* callback
function.

If the
**NmrClientAttachProvider** function does not return STATUS_SUCCESS, the client module should perform
any necessary cleanup of the data contained within its binding context structure. The client module
should then free the memory for its binding context structure if it dynamically allocated the memory for
the structure.

If the
**NmrClientAttachProvider** function returns STATUS_SUCCESS and the client module dynamically allocated
the memory for its binding context, the client module should free that allocated memory when the NMR
calls the client module's
[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn) callback function after the client module and provider module are
detached from each other.

If the
**NmrClientAttachProvider** function returns STATUS_SUCCESS, the client module must save the pointers
returned in the
*ProviderBindingContext* and
*ProviderDispatch* parameters so that it can call the provider module's
[NPI](https://learn.microsoft.com/windows-hardware/drivers/network/network-programming-interface) functions.

## See also

[ClientAttachProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_attach_provider_fn)

[ClientCleanupBindingContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_client_cleanup_binding_context_fn)

[ProviderAttachClient](https://learn.microsoft.com/windows-hardware/drivers/ddi/netioddk/nc-netioddk-npi_provider_attach_client_fn)