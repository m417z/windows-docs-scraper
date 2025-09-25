# FWP_RANGE0 structure

## Description

The **FWP_RANGE0** structure specifies a range of values.

## Members

### `valueLow`

Low value of the range.

See [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0) for more information.

### `valueHigh`

High value of the range.

See [FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0) for more information.

## Remarks

The elements **valueLow** and **valueHigh** must be the same data type and
**valueHigh** must be greater than or equal to **valueLow**.

Ranges are always inclusive. Thus, if a value equals
**valueLow** or **valueHigh**, it is contained in the range.

**FWP_RANGE0** is a specific implementation of FWP_RANGE. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWP_VALUE0](https://learn.microsoft.com/windows/desktop/api/fwptypes/ns-fwptypes-fwp_value0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)