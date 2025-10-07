# InitializeIpForwardEntry function

The **InitializeIpForwardEntry** function initializes a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure with default values for an IP route entry on a local computer.

## Parameters

- *Row* \[out\]
On entry, a pointer to a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry for an IP route entry.

 On return, the MIB\_IPFORWARD\_ROW2 structure that this parameter points to is initialized with default values for an IP route entry.

## Return value

None

## Remarks

Your driver must use the **InitializeIpForwardEntry** function to initialize the members of a [**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2) structure entry with default values for an IP route entry for later use with the [**CreateIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/createipforwardentry2) function.

On input, your driver must pass **InitializeIpForwardEntry** a new MIB\_IPFORWARD\_ROW2 structure to initialize.

On output, the members of the MIB\_IPFORWARD\_ROW2 structure that the *Row* parameter points to are initialized as follows.

- **ValidLifetime** and **PreferredLifetime**
Set to an infinite value,

- **Loopback**, **AutoconfigureAddress**, **Publish**, and **Immortal**
Set to **TRUE**.

- **SitePrefixLength**, **Metric**, and **Protocol**
Set to illegal values.

- All other members
Set to zero.

After a driver calls **InitializeIpForwardEntry**, the driver can then change the members in the MIB\_IPFORWARD\_ROW2 entry that it wants to modify, and then call the **CreateIpForwardEntry2** to add the new IP route entry to the local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CreateIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/createipforwardentry2)

[**DeleteIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteipforwardentry2)

[**GetBestRoute2**](https://learn.microsoft.com/windows-hardware/drivers/network/getbestroute2)

[**GetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardentry2)

[**GetIpForwardTable2**](https://learn.microsoft.com/windows-hardware/drivers/network/getipforwardtable2)

[**MIB\_IPFORWARD\_ROW2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-row2)

[**MIB\_IPFORWARD\_TABLE2**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipforward-table2)

[**NotifyRouteChange2**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyroutechange2)

[**SetIpForwardEntry2**](https://learn.microsoft.com/windows-hardware/drivers/network/setipforwardentry2)