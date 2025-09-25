# WdsBpParseInitialize function

## Description

Receives a handle to the packet sent by the network boot program.

## Parameters

### `pPacket` [in]

A pointer to the packet received from the WDS client. The packet must be a valid DHCP packet.

### `uPacketLen` [in]

The length of the packet, in bytes.

### `pbPacketType` [out, optional]

A value that indicates the type of boot program that sent the packet. The bit flags in the following table can be combined.

| Value | Meaning |
| --- | --- |
| **WDSBP_PK_TYPE_DHCP**<br><br>1 | The presence of this value indicates that the packet is a DHCP packet. |
| **WDSBP_PK_TYPE_WDSNBP**<br><br>2 | This presence of this value indicates that the DHCP packet came from the WDS network boot program. If this value is absent the type of client was not recognized. |
| **WDSBP_PK_TYPE_BCD**<br><br>4 | The presence of this value indicates that the packet contains a path to a Boot Configuration Data (BCD) file. |

### `phHandle` [out]

A handle to the packet. This handle can be used by the [WdsBpQueryOption](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpqueryoption) function and must be closed using the [WdsBpCloseHandle](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpclosehandle) function.

## Return value

If the function succeeds, the return is **S_OK**.