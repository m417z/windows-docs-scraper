# ITILSConfig::get_Port

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**get_Port** method gets the port number used to connect to the server of a given ILS directory.

## Parameters

### `pPort` [out]

Pointer to receive the port number used in the connection.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | Invalid pointer. |

## See also

[ITILSConfig](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itilsconfig)

[ITILSConfig::put_Port](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itilsconfig-put_port)