# _SetGenerationalGuid_IN structure

## Description

The SetGenerationalGuid_IN structure holds the input data for the [SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid) method.

## Members

### `GenerationalGuid`

A 16-byte GUID that identifies the version of the information that is currently in the initiator cache.

## Remarks

You must implement this method.

## See also

[SetGenerationalGuid](https://learn.microsoft.com/windows-hardware/drivers/storage/setgenerationalguid)

[SetGenerationalGuid_OUT](https://learn.microsoft.com/windows-hardware/drivers/ddi/iscsiop/ns-iscsiop-_setgenerationalguid_out)