# GNSS_LKGFIX_PARAM structure

## Description

This structure is not used currently by the system and is not required to be implemented.

## Members

### `Size`

Structure size.

### `Version`

Version number.

## Remarks

No additional parameter is needed for an LKG fix. The GNSS adapter implements any aging heuristics for rejecting an LKG fix received from the GNSS driver based on the difference between the fix time and current time.