# IP_ADAPTER_ORDER_MAP structure

## Description

The **IP_ADAPTER_ORDER_MAP** structure stores an array of information about adapters and their relative priority on the local computer.

## Members

### `NumAdapters`

The number of network adapters in the **AdapterOrder** member.

### `AdapterOrder`

An array of adapter indexes on the local computer, provided in the order specified in the **Adapters and Bindings** dialog box for **Network Connections**.

## Remarks

This structure is returned by the GetAdapterOrderMap function, and is used as a tie breaker for otherwise equal interfaces during network operations. The GetAdapterOrderMap function should not be called directly; use the GetAdaptersInfo function instead.

The **IP_ADAPTER_ORDER_MAP** structure contains at least one **AdapterOrder** member even if the **NumAdapters** member of the **IP_ADAPTER_ORDER_MAP** structure indicates no network adapters. When the **NumAdapters** member of the **IP_ADAPTER_ORDER_MAP** structure is zero, the value of the single **AdapterOrder** member is undefined.

This structure is defined in the *Ipexport.h* header file which is automatically included in the *Iphlpapi.h* header file. The *Ipexport.h* header file should never be used directly.

## See also

GetAdapterOrderMap

GetAdaptersInfo