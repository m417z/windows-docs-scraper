# IS_OFFICIAL_DDI_INTERFACE_VERSION macro

## Description

The **IS_OFFICIAL_DDI_INTERFACE_VERSION** macro indicates whether the specified interface version is an official DXGK interface version.

## Parameters

### `version`

The version to test. See **IS_OFFICIAL_DDI_INTERFACE_VERSION**'s definition in *d3dukmdt.h* for a list of valid values.

## Remarks

**IS_OFFICIAL_DDI_INTERFACE_VERSION** returns TRUE if **version** is set to an official DXGK interface version. Otherwise, it returns FALSE.