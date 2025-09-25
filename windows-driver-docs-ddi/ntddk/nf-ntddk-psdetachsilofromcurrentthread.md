## Description

This routine removes a thread from a silo which was added by an attach. For more info about attaching, see the [PsAttachSiloToCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psattachsilotocurrentthread) routine.

The caller is responsible for dereferencing the object after the detach has completed.

## Parameters

### `PreviousSilo` [in]

The value returned from the silo attach call.

## See also

[PsAttachSiloToCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psattachsilotocurrentthread)