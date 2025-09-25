# _SetGroupPresharedKey_IN structure

## Description

The SetGroupPresharedKey_IN structure holds the input data for the [SetGroupPresharedKey](https://learn.microsoft.com/windows-hardware/drivers/storage/setgrouppresharedkey) method.

## Members

### `KeySize`

The size, in bytes, of the key in **Key***.*

### `Key`

The preshared group key*.*

## Remarks

You must implement this method.

## See also

[SetGroupPresharedKey](https://learn.microsoft.com/windows-hardware/drivers/storage/setgrouppresharedkey)

[SetGroupPresharedKey_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setgrouppresharedkey_out)