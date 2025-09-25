# PsUnregisterSiloMonitor function

## Description

This routine unregisters a server silo monitor.

## Parameters

### `Monitor` [in]

The server silo monitor to unregister.

## Remarks

The monitor will not receive further notifications after this routine completes.
If the monitor allocated a silo context slot, this routine will not complete until all silo contexts have been removed from slot.