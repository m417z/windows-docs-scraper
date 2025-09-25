# InitializeIpInterfaceEntry function

## Description

The
**InitializeIpInterfaceEntry** function initializes the members of
an **MIB_IPINTERFACE_ROW** entry with default values.

## Parameters

### `Row` [in, out]

A pointer to a
**MIB_IPINTERFACE_ROW** structure to initialize. On successful return, the fields in this parameter are initialized with default information for an interface on the local computer.

## Return value

This function does not return a value.

## Remarks

The **InitializeIpInterfaceEntry** function is defined on Windows Vista and later.

On output, the **Family** member in the **MIB_IPINTERFACE_ROW** structure pointed to by the *Row* parameter will be initialized to either **AF_UNSPEC**, the **InterfaceLuid** member in the **MIB_IPINTERFACE_ROW** structure will be initialized to an unspecified value, and other fields are initialized to zero.

The **InitializeIpInterfaceEntry** function must be used to initialize the fields of a
**MIB_IPINTERFACE_ROW** structure entry with default values. An application can then change the
fields in the **MIB_IPINTERFACE_ROW** entry it wishes to modify, and then call the [SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry) function.

## See also

[GetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfaceentry)

[GetIpInterfaceTable](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-getipinterfacetable)

[IP Helper Function Reference](https://learn.microsoft.com/windows/desktop/IpHlp/ip-helper-function-reference)

**MIB_IPINTERFACE_ROW**

[MIB_IPINTERFACE_TABLE](https://learn.microsoft.com/windows/desktop/api/netioapi/ns-netioapi-mib_ipinterface_table)

[SetIpInterfaceEntry](https://learn.microsoft.com/windows/desktop/api/netioapi/nf-netioapi-setipinterfaceentry)