# ITILSConfig::put_Port

## Description

[Rendezvous IP Telephony Conferencing controls and interfaces are not available for use in Windows Vista, Windows Server 2008, and subsequent versions of the operating system. The RTC Client API
provides similar functionality.]

The
**put_Port** method sets the port number used to connect to the server of a specified ILS directory.

## Parameters

### `Port` [in]

The port number that will be used to connect to the server. This can be any port number in the range of 16-bit unsigned integers.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | The *Port* parameter is not valid. |
| **RND_ALREADY_CONNECTED** | A successful connection has been made. Port cannot be reset. |

## Remarks

Applications use this method only if they need to connect to custom-configured ILS servers listening on strange ports that are not listed in the Active Directory. By default, the Rendezvous control automatically tries to use ports 1002 and 389, the usual ILS ports, for connecting to application-specified ILS servers. Also, the Rendezvous control automatically uses whatever port is published in the Active Directory for ILS servers retrieved from there.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[ITILSConfig](https://learn.microsoft.com/windows/desktop/api/rend/nn-rend-itilsconfig)

[ITILSConfig::get_Port](https://learn.microsoft.com/windows/desktop/api/rend/nf-rend-itilsconfig-get_port)