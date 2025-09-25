# NETINFOSTRUCT structure

## Description

The
**NETINFOSTRUCT** structure contains information describing the network provider returned by the
[WNetGetNetworkInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetnetworkinformationa) function.

## Members

### `cbStructure`

Type: **DWORD**

The size, in bytes, of the
**NETINFOSTRUCT** structure. The caller must supply this value to indicate the size of the structure passed in. Upon return, it has the size of the structure filled in.

### `dwProviderVersion`

Type: **DWORD**

The version number of the network provider software.

### `dwStatus`

Type: **DWORD**

The current status of the network provider software. This member can be one of the following values.

| Value | Meaning |
| --- | --- |
| **NO_ERROR** | The network is running. |
| **ERROR_NO_NETWORK** | The network is unavailable. |
| **ERROR_BUSY** | The network is not currently able to service requests, but it should become available shortly. (This value typically indicates that the network is starting up.) |

### `dwCharacteristics`

Type: **DWORD**

Characteristics of the network provider software.

This value is zero.

**Windows Me/98/95:** This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **NETINFO_DLL16** | The network provider is running as a 16-bit Windows network driver. |
| **NETINFO_DISKRED** | The network provider requires a redirected local disk drive device to access server file systems. |
| **NETINFO_PRINTERRED** | The network provider requires a redirected local printer port to access server file systems. |

### `dwHandle`

Type: **ULONG_PTR**

An instance handle for the network provider or for the 16-bit Windows network driver.

### `wNetType`

Type: **WORD**

The network type unique to the running network. This value associates resources with a specific network when the resources are persistent or stored in links. You can find a complete list of network types in the header file Winnetwk.h.

### `dwPrinters`

Type: **DWORD**

A set of bit flags indicating the valid print numbers for redirecting local printer devices, with the low-order bit corresponding to LPT1.

**Windows Me/98/95:** This value is always set to –1.

### `dwDrives`

Type: **DWORD**

A set of bit flags indicating the valid local disk devices for redirecting disk drives, with the low-order bit corresponding to A:.

**Windows Me/98/95:** This value is always set to –1.

## Remarks

The **NETINFOSTRUCT** structure contains information describing the network, such as the version of the network provider software and the network's current status.

## See also

[WNetGetNetworkInformation](https://learn.microsoft.com/windows/desktop/api/winnetwk/nf-winnetwk-wnetgetnetworkinformationa)

[Windows Networking (WNet) Overview](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-wnet-)

[Windows Networking Structures](https://learn.microsoft.com/windows/desktop/WNet/windows-networking-structures)