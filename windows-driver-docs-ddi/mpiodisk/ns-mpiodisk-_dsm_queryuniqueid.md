# _DSM_QueryUniqueId structure

## Description

The DSM_QueryUniqueId structure is used to query the DSM for a unique identifier. This unique identifier can be used together with the DsmPathId to create a 128-bit identifier for a path that is unique among all paths, as well as all DSMs, that are known to a management application. This is especially useful if the management application is managing devices that are spread across various systems. To query for this 64-bit unique identifier, the application must target the request to a pseudo-LUN that is addressed by its WMI instance name. This class is mandatory for any DSM that supports VDS.

## Members

### `DsmUniqueId`

An unsigned 64-bitfield that represents an identifier that must be set by DSMs that want management applications, such as VDS, to be able to manage the devices that are controlled by the particular DSM. This structure is used together with the DsmPathId structure to create a 128-bit identifier that is unique, not just among all the paths that are known to this DSM, but also among all the DSMs that are present in the system.