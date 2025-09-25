# _SetPresharedKeyForId_IN structure

## Description

The SetPresharedKeyForId_IN structure holds the input data for the [SetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/setpresharedkeyforid) method.

## Members

### `PortNumber`

The number of the port that the initiator uses the preshared key with. A value of 0xffffffff indicates all ports.

### `SecurityFlags`

A bitwise OR of flags that indicate the security requirements of a target. For a list of possible values for this member, see [SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers).

### `IdType`

The type of identifier to associate with the preshared key. The initiator puts this identifier (ID) in the Internet key exchange (IKE) identification payload to identify itself to the target. The following table describes the possible identification payload types.

| Identification payload type | Meaning |
| --- | --- |
| ID_IPV4_ADDR | The initiator identifies itself to the target during the key exchange with a single 4-byte version 4 IP address. |
| ID_FQDN | The initiator identifies itself to the target during the key exchange with a fully qualified domain name string (for example, "website.com"). |
| ID_USER_FQDN | The initiator identifies itself to the target during the key exchange with a fully qualified user name string (for example, "sample@example.com"). |
| ID_IPV6_ADDR | The initiator identifies itself to the target during the key exchange with a single 16-byte version 6 IP address. |

### `IdSize`

The size, in bytes, of the identifier in **Id***.*

### `KeySize`

The size, in bytes, of the key in **Key***.*

### `Id`

The ID to associate with the key. The initiator uses this ID to identify itself to the target during key exchange.

## Remarks

You must implement this method.

## See also

[SECURITY_FLAG_QUALIFIERS](https://learn.microsoft.com/windows-hardware/drivers/storage/security-flag-qualifiers)

[SetPresharedKeyForId](https://learn.microsoft.com/windows-hardware/drivers/storage/setpresharedkeyforid)

[SetPresharedKeyForId_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setpresharedkeyforid_out)