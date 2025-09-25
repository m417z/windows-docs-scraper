# _GetPresharedKeyForId_IN structure

## Description

The GetPresharedKeyForId_IN structure holds the input data for the [GetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/getpresharedkeyforid) method. This method is required if the initiator supports Internet Key Exchange (IKE). It can help to determine whether IKE identification payload is configured with a preshared key.

## Members

### `PortNumber`

The number of the port that the connection was made through. A value of -1 indicates that the connection can be made through any available port.

### `IdType`

The type of identifier that the initiator puts in the Internet Key Exchange (IKE) identification payload to identify itself to the target.

| Identification payload type | Meaning |
| --- | --- |
| ID_IPV4_ADDR | The initiator identifies itself to the target during the key exchange with a single 4-byte version 4 IP address. |
| ID_FQDN | The initiator identifies itself to the target during the key exchange with a fully qualified domain name string (for example, "website.com"). |
| ID_USER_FQDN | The initiator identifies itself to the target during the key exchange with a fully qualified user name string (for example, "someone@example.com"). |
| ID_IPV6_ADDR | The initiator identifies itself to the target during the key exchange with a single 16-byte version 6 IP address. |

### `IdSize`

The size, in bytes, of the identifier in **Id***.*

### `Id`

The identifier that the initiator uses to identify itself to the target during key exchange.

## Remarks

You must implement this method if the initiator supports IKE.

## See also

[GetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/getpresharedkeyforid)

[GetPresharedKeyForId_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_getpresharedkeyforid_out)

[MSiSCSI_SecurityConfigOperations WMI Class](https://learn.microsoft.com/windows-hardware/drivers/storage/msiscsi-securityconfigoperations-wmi-class)