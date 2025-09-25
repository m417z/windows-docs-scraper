# SILO_MONITOR_TERMINATE_CALLBACK callback function

## Description

This callback is invoked when a silo is terminated.

## Parameters

### `Silo` [in]

The silo to be terminated.

## Remarks

The expected behavior is that the component will drop any outstanding silo references. A driver may no longer operate within the namespace of a silo (via [PsAttachSiloToCurrentThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntddk/nf-ntddk-psattachsilotocurrentthread)) once it has returned from this function.