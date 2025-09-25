# STOR_EVENT structure

## Description

The **STOR_EVENT** structure describes an event object.

## Members

### `Header`

An opaque [**STOR_DISPATCHER_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_dispatcher_header) structure that describes an event object.

## Remarks

Callers of [**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent) must first allocate space for a **STOR_EVENT** structure.

## See also

[**KeInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-keinitializeevent)
[STOR_EVENT](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_event)

[**STOR_DISPATCHER_HEADER**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/ns-storport-stor_dispatcher_header)

[**StorPortInitializeEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportinitializeevent)

[**StorPortSetEvent**](https://learn.microsoft.com/windows-hardware/drivers/ddi/storport/nf-storport-storportsetevent)