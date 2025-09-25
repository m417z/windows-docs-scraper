# WdsBpInitialize function

## Description

Constructs options for the WDS network boot program.

## Parameters

### `bPacketType` [in]

The type of boot program. This parameter may have one of the following values.

| Value | Meaning |
| --- | --- |
| **WDSBP_PK_TYPE_WDSNBP**<br><br>2 | Specify this value to build a boot program using options for the "wdsnbp.com" boot program. The "wdsnbp.com" boot program is the WDS network boot program for IPv4 PXE on legacy BIOS systems and does not support other systems. |
| **WDSBP_PK_TYPE_BCD**<br><br>4 | Specify this value to build a boot program using the **WDSBP_OPT_BCD_FILE_PATH** option. It may be used with "wdsnbp.com" or other boot programs. |
| **WDSBP_PK_TYPE_DHCPV6**<br><br>8 | Specify this value to indicate that the packet contains a path to a Boot Configuration Data (BCD) file. Use this value for any and all DHCPv6 options. The presence of this value indicates that the packet contains a path to a Boot Configuration Data (BCD) file. |

### `phHandle` [out]

A pointer to the handle to the packet. This handle can be used by the [WdsBpAddOption](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpaddoption) function to add options for the WDS network boot program. After all the options have been added, use the [WdsBpGetOptionBuffer](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpgetoptionbuffer) function to add these to the DHCP options list sent to WDS network boot program. The handle must be closed using the [WdsBpCloseHandle](https://learn.microsoft.com/windows/desktop/api/wdsbp/nf-wdsbp-wdsbpclosehandle) function.

## Return value

If the function succeeds, the return is **S_OK**.