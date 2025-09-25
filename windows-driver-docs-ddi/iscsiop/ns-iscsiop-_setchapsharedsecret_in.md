# _SetCHAPSharedSecret_IN structure

## Description

The SetCHAPSharedSecret_IN structure holds the input data for the [SetCHAPSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setchapsharedsecret) method.

## Members

### `SharedSecretSize`

The size, in bytes, of the shared secret.

### `SharedSecret`

A variable-length array that contains the shared secret.

## Remarks

You must implement this method.

## See also

[SetCHAPSharedSecret](https://learn.microsoft.com/windows-hardware/drivers/storage/setchapsharedsecret)

[SetCHAPSharedSecret_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setchapsharedsecret_out)