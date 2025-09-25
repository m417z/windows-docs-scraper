# LANA_ENUM structure

## Description

[[Netbios](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal) is not supported on Windows Vista, Windows Server 2008, and subsequent versions of the operating system]

The **LANA_ENUM** structure contains the numbers for the current LAN adapters.

## Members

### `length`

Specifies the number of valid entries in the array of LAN adapter numbers.

### `lana`

Specifies an array of LAN adapter numbers.

## Remarks

The **LANA_ENUM** structure is pointed to by the ncb_buffer member of the [NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb) structure when an application issues the **NCBENUM** command. The **NCBENUM** command is not part of the IBM NetBIOS 3.0 specification.

## See also

[NCB](https://learn.microsoft.com/windows/desktop/api/nb30/ns-nb30-ncb)

[NetBIOS Structures](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/netbios-structures)

[The NetBIOS Interface Overview](https://learn.microsoft.com/previous-versions/windows/desktop/netbios/portal)