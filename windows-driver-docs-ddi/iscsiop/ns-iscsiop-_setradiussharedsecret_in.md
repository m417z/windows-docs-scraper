# _SetRADIUSSharedSecret_IN structure

## Description

The SetRADIUSSharedSecret_IN structure holds the input data for the [SetRADIUSSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setradiussharedsecret) method.

## Members

### `SharedSecretSize`

The size, in bytes, of the shared secret.

### `SharedSecret`

The shared secret.

## Remarks

You must implement this method.

## See also

[SetRADIUSSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setradiussharedsecret)

[SetRADIUSSharedSecret_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setradiussharedsecret_out)