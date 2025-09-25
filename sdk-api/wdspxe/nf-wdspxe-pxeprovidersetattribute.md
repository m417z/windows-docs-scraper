# PxeProviderSetAttribute function

## Description

Specifies attributes for the provider.

## Parameters

### `hProvider` [in]

**HANDLE** passed to
the [PxeProviderInitialize](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderinitialize) function.

### `Attribute` [in]

Identifies the attribute to set.

| Value | Meaning |
| --- | --- |
| **PXE_PROV_ATTR_FILTER**<br><br>0 | The *pParameterBuffer* parameter points to a **ULONG**. |
| **PXE_PROV_ATTR_FILTER_IPV6**<br><br>1 | The *pParameterBuffer* parameter points to a **ULONG**. Use this attribute with DHCPv6 packets. Available beginning with Windows 8 and Windows Server 2012. |
| **PXE_PROV_ATTR_IPV6_CAPABLE**<br><br>2 | Pointer to a **BOOL** value that is TRUE to indicate the provider is capable of processing IPv6 packets. By default, the server assumes a provider is not capable of processing IPv6 packets and will not deliver them. Available beginning with Windows 8 and Windows Server 2012. |

### `pParameterBuffer` [in]

Pointer to a buffer. The size and contents of this buffer vary depending on the value of the
*Attribute* parameter.

If *Attribute* is PXE_PROV_ATTR_FILTER, the buffer contains one of the following values.

| Value | Meaning |
| --- | --- |
| **PXE_PROV_FILTER_ALL**<br><br>0x0000 | Provider is to see all packets. |
| **PXE_PROV_FILTER_DHCP_ONLY**<br><br>0x0001 | Provider will see only DHCP packets. If **PXE_PROV_ATTR_FILTER_IPV6**, the provider will see only only DHCPv6 packets |
| **PXE_PROV_FILTER_PXE_ONLY**<br><br>0x0002 | Provider will see only DHCP packets that specify the DHCP Vendor Class Identifier option (60) as "PXEClient". If **PXE_PROV_ATTR_FILTER_IPV6**, provider will see only packets that specify a DHCPv6 OPTION_VENDOR_CLASS containing the “PXEClient”. |

### `uParamLen` [in]

The size of the buffer pointed to by the *pParameterBuffer* parameter.

## Return value

If the function succeeds, the return value is **ERROR_SUCCESS**.

## See also

[PxeProviderRecvRequest](https://learn.microsoft.com/windows/desktop/Wds/pxeproviderrecvrequest)

[Windows Deployment Services Server Functions](https://learn.microsoft.com/windows/desktop/Wds/windows-deployment-services-server-functions)