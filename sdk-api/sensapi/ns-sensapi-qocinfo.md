# QOCINFO structure

## Description

The
**QOCINFO** structure is returned by the
[IsDestinationReachable](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isdestinationreachablea) function and provides Quality of Connection information to the caller.

## Members

### `dwSize`

Upon calling
[IsDestinationReachable](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isdestinationreachablea), the caller must specify the size of the **QOCINFO** structure being provided to the function using dwSize. The size should be specified in bytes. Upon return from [IsDestinationReachable](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isdestinationreachablea), dwSize contains the size of the provided structure in bytes.

### `dwFlags`

Provides information on the type of network connection available. The following table lists the possible values.

| Flag | Meaning |
| --- | --- |
| **NETWORK_ALIVE_LAN**<br><br>0x00000001 | The computer has one or more active LAN cards. |
| **NETWORK_ALIVE_WAN**<br><br>0x00000002 | The computer has one or more active RAS connections. |
| **NETWORK_ALIVE_AOL**<br><br>0x00000004 | This flag is not supported. |

### `dwInSpeed`

Speed of data coming in from the destination in bytes per second.

### `dwOutSpeed`

Speed of data sent to the destination in bytes per second.

## See also

[IsDestinationReachable](https://learn.microsoft.com/windows/desktop/api/sensapi/nf-sensapi-isdestinationreachablea)