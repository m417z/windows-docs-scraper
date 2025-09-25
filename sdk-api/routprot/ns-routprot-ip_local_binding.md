# IP_LOCAL_BINDING structure

## Description

The
**IP_LOCAL_BINDING** structure contains IP address information for an adapter.

## Members

### `Address`

Specifies an IP address for the adapter.

### `Mask`

Specifies the subnet mask for the IP address.

## Remarks

Since an adapter can have more than one IP address, the
[IP_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_adapter_binding_info) structure maintains an array of
**IP_LOCAL_BINDING** structures.

## See also

[IP_ADAPTER_BINDING_INFO](https://learn.microsoft.com/windows/desktop/api/routprot/ns-routprot-ip_adapter_binding_info)

[Router Management Reference](https://learn.microsoft.com/windows/desktop/RRAS/router-management-reference)

[Router Management Structures](https://learn.microsoft.com/windows/desktop/RRAS/router-management-structures)