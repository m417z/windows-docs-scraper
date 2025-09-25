# _SM_RemovePort_IN structure

## Description

The SM_RemovePort_IN structure is used to provide input parameters to the SM_RemovePort WMI method.

## Members

### `PortWWN`

A worldwide name (WWN) that indicates the port that should be removed from the list of ports whose events are reported to the WMI client.

### `EventType`

An event type value.

## Remarks

The WMI tool suite generates a declaration of the SM_RemovePort_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_EventControl WMI class.