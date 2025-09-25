# ExReleasePushLockExclusive macro

## Description

Releases a specified push lock for exclusive access owned by the current thread.

## Parameters

### `Lock`

Opaque push lock pointer specified in the [**ExAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockexclusive) call. This pointer must have been initialized by a previous call to [**ExInitializePushLock**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializepushlock).

## Remarks

To acquire a push lock for exclusive access, call [**ExAcquirePushLockExclusive**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockexclusive).

To acquire a push lock for shared access, call [**ExAcquirePushLockShared**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exacquirepushlockshared).

## See also