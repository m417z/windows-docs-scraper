# _MPIO_REGISTERED_DSM structure

## Description

The MPIO_REGISTERED_DSM structure represents the top-level view of the registered DSMs on the system. To query this information, the request must be sent to the MPIO control object by using its WMI instance name.

## Members

### `NumberDSMs`

An unsigned 32-bitfield that specifies the number of DSMs that are registered in the system.

### `DsmParameters`

An array that returns information about each of the registered DSMs. The number of elements in the array is given by *NumberDSMs* and each element is an instance of the DSM_PARAMETERS structure.