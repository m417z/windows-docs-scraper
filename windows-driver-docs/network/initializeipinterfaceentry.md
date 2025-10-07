# InitializeIpInterfaceEntry function

The **InitializeIpInterfaceEntry** function initializes the members of an [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structure entry with default values.

## Parameters

- *Row* \[in, out\]
A pointer to a [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structure to initialize. On successful return, the fields in this parameter are initialized with default information for an interface on the local computer.

## Return value

**InitializeIpInterfaceEntry** returns STATUS\_SUCCESS if the function succeeds.

If the function fails, **InitializeIpInterfaceEntry** returns one of the following error codes:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | An invalid parameter was passed to the function. This error is returned if a **NULL** pointer is passed in the *Row* parameter |
| **Other** | Use the [FormatMessage](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-formatmessage) function to obtain the message string for the returned error. |

## Remarks

On output, the members of the [**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row) structure that the *Row* parameter points to are initialized as follows.

- **Family**
Set to AF\_UNSPEC.

- **InterfaceLuid**
Set to an unspecified value.

- All other members
Set to zero.

Your driver must use the **InitializeIpInterfaceEntry** function to initialize the fields of a MIB\_IPINTERFACE\_ROW structure entry with default values. A driver can then change the fields in the MIB\_IPINTERFACE\_ROW entry that it wants to modify, and then call the [**SetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setipinterfaceentry) function.

## Requirements

|  |  |
| --- | --- |
| Target platform | [Universal](https://learn.microsoft.com/windows-hardware/drivers/develop/target-platforms) |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |
| Library | Netio.lib |
| IRQL | < DISPATCH_LEVEL |

## See also

[**GetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfaceentry)

[**GetIpInterfaceTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getipinterfacetable)

[**MIB\_IPINTERFACE\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-row)

[**MIB\_IPINTERFACE\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ipinterface-table)

[**SetIpInterfaceEntry**](https://learn.microsoft.com/windows-hardware/drivers/network/setipinterfaceentry)