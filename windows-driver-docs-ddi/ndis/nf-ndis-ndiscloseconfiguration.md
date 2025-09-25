# NdisCloseConfiguration function

## Description

The
**NdisCloseConfiguration** function releases the handle to the registry key that was returned by the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex),
[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex), or
[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname) function.

## Parameters

### `ConfigurationHandle` [in]

The handle that the
[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex) function
returns.

## Remarks

This function frees any temporary storage allocated in calls to other
**Ndis*Xxx*** functions that required the returned
*ConfigurationHandle* as a parameter.

## See also

[DriverEntry of NDIS Protocol
Drivers](https://learn.microsoft.com/previous-versions/windows/embedded/gg156036(v=winembedded.80))

[MiniportInitializeEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-miniport_initialize)

[NdisOpenConfigurationEx](https://learn.microsoft.com/windows-hardware/drivers/devtest/ndis-ndisopenconfigurationex)

[NdisOpenConfigurationKeyByIndex](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyindex)

[NdisOpenConfigurationKeyByName](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisopenconfigurationkeybyname)

[NdisReadConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadconfiguration)

[NdisReadNetworkAddress](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndisreadnetworkaddress)

[NdisWriteConfiguration](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nf-ndis-ndiswriteconfiguration)

[ProtocolBindAdapterEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ndis/nc-ndis-protocol_bind_adapter_ex)