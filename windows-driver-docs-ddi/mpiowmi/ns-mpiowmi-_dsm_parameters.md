# _DSM_PARAMETERS structure

## Description

The DSM_PARAMETERS structure holds the DSM version and timer counters information.

## Members

### `DsmName`

A string field of maximum length 63 characters that returns the friendly name of the DSM.

### `DsmContext`

An unsigned 64-bitfield that represents a unique identifier as used by MPIO to address a particular DSM.

### `DsmVersion`

A field that contains an instance of the DSM_VERSION structure with version information for the DSM.

### `DsmCounters`

A field that contains an instance of the DSM_COUNTERS structure with timer counters information that is specific to the particular DSM.