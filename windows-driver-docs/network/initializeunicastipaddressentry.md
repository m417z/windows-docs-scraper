# InitializeUnicastIpAddressEntry function

The **InitializeUnicastIpAddressEntry** function initializes a [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure with default values for a unicast IP address entry on a local computer.

## Parameters

- *Row* \[out\]
On entry, a pointer to a [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry for a unicast IP address entry. On return, the MIB\_UNICASTIPADDRESS\_ROW structure that this parameter points to is initialized with default values for a unicast IP address.

## Return value

None

## Remarks

Your driver must use the **InitializeUnicastIpAddressEntry** function to initialize the members of a [**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row) structure entry with default values for a unicast IP address for later use with the [**CreateUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createunicastipaddressentry) function.

On input, your driver must pass **InitializeUnicastIpAddressEntry** a new MIB\_UNICASTIPADDRESS\_ROW structure to initialize.

On output, the members of the MIB\_UNICASTIPADDRESS\_ROW structure that the *Row* parameter points to are initialized as follows.

- **PrefixOrigin**
Set to the **IpPrefixOriginUnchanged** value of the [**NL\_PREFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-prefix-origin) enumeration.

- **SuffixOrigin**
Set to the **IpSuffixOriginUnchanged** value of the [**NL\_PREFIX\_ORIGIN**](https://learn.microsoft.com/windows-hardware/drivers/network/nl-prefix-origin) enumeration.

- **OnLinkPrefixLength**
Set to an illegal value.

- **PreferredLifetime** and **ValidLifetime**
Set to infinite values.

- **SkipAsSource**
Set to **FALSE**.

- All other members
Set to zero.

After a driver calls **InitializeUnicastIpAddressEntry**, the driver can then change the members in the MIB\_UNICASTIPADDRESS\_ROW entry that it wants to modify, and then call the **CreateUnicastIpAddressEntry** to add the new unicast IP address to the local computer.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**CreateUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/createunicastipaddressentry)

[**DeleteUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/deleteunicastipaddressentry)

[**GetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddressentry)

[**GetUnicastIpAddressTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getunicastipaddresstable)

[**MIB\_UNICASTIPADDRESS\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-row)

[**MIB\_UNICASTIPADDRESS\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-unicastipaddress-table)

[**NotifyUnicastIpAddressChange**](https://learn.microsoft.com/windows-hardware/drivers/network/notifyunicastipaddresschange)

[**SetUnicastIpAddressEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setunicastipaddressentry)