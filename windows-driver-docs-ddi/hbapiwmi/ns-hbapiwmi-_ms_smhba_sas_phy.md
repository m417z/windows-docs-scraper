# _MS_SMHBA_SAS_PHY structure

## Description

The MS_SMHBA_SAS_PHY structure is used to report the SAS physical port information.

## Members

### `PhyIdentifier`

The port whose physical configuration and link information is being returned. It is unique within the context of the SAS device that contains the physical port.

### `NegotiatedLinkRate`

The state or the transmission speed that is negotiated by the physical port for the physical link.

### `ProgrammedMinLinkRate`

The minimum physical link rate that is set by the physical port control mechanism.

### `HardwareMinLinkRate`

The minimum physical link rate that is supported by the physical port.

### `ProgrammedMaxLinkRate`

The maximum physical link rate that is set by the physical port control mechanism.

### `HardwareMaxLinkRate`

The maximum physical link rate that is supported by the physical port.

### `domainPortWWN`

The Port_Identifier that has the smallest value of any Port_Identifier of an expander SMP.

## Remarks

Link rates are defined in hpaapi.h as HBA_SASSPEED_1_5GBIT and HBA_SASSPEED_3GBIT.