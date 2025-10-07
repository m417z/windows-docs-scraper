# MIB\_INVERTEDIFSTACK\_ROW structure

The MIB\_INVERTEDIFSTACK\_ROW structure represents the relationship between two network interfaces.

## Members

- **LowerLayerInterfaceIndex**
The network interface index for the interface that is lower in the interface stack table.

- **HigherLayerInterfaceIndex**
The network interface index for the interface that is higher in the interface stack table.

## Remarks

The relationship between the interfaces in the interface stack is that the interface with the index in the **HigherLayerInterfaceIndex** member is immediately above the interface with the index in the **LowerLayerInterfaceIndex** member.

## Requirements

|  |  |
| --- | --- |
| Version | Available in Windows Vista and later versions of the Windows operating systems. |
| Header | Netioapi.h (include Netioapi.h) |

## See also

[**GetIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getifstacktable)

[**GetInvertedIfStackTable**](https://learn.microsoft.com/windows-hardware/drivers/network/getinvertedifstacktable)

[**MIB\_IFSTACK\_ROW**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-row)

[**MIB\_IFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-ifstack-table)

[**MIB\_INVERTEDIFSTACK\_TABLE**](https://learn.microsoft.com/windows-hardware/drivers/network/mib-invertedifstack-table)