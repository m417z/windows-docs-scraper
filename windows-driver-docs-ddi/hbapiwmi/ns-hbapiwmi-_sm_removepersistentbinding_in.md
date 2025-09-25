# _SM_RemovePersistentBinding_IN structure

## Description

The SM_RemovePersistentBinding_IN structure is used to provide input parameters to the SM_RemovePersistentBinding method.

## Members

### `HbaPortWWN`

The worldwide name (WWN) of the local port whose events the WMI client will receive.

### `DomainPortWWN`

A worldwide name (WWN) that specifies the SAS domain worldwide name of the local port.

### `EntryCount`

The total number of persistent bindings that are associated with the HBA.

### `Entry`

An array of structures of type SMHBA_SCSIENTRY that describes an HBA's bindings between the operating system and the SAS identifiers.

## Remarks

The WMI tool suite generates a declaration of the SM_RemovePersistentBinding_IN structure in *Hbapiwmi.h* when it compiles the MS_SM_TargetInformationMethods WMI class.