# STOR_DISPATCHER_HEADER structure

## Description

The **STOR_DISPATCHER_HEADER** structure is an opaque structure that describes a dispatcher object.

## Members

### `Data`

Reserved for system use.

### `Data.Type`

Reserved for system use.

### `Data.Flags`

Reserved for system use.

### `Data.Size`

Reserved for system use.

### `Data.Inserted`

Reserved for system use.

### `Data.DebugActive`

Reserved for system use.

### `Lock`

Reserved for system use.

### `SignalState`

Reserved for system use.

### `WaitListHead`

Reserved for system use.

## Remarks

**STOR_DISPATCHER_HEADER** is a member of the [**STOR_EVENT**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event) structure that is passed to [**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent) and [**StorPortSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetevent).

## See also

[**KeInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)
[STOR_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event)

[**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent)

[**StorPortSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetevent)