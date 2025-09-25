# FWPM_DISPLAY_DATA0 structure

## Description

The **FWPM_DISPLAY_DATA0** structure stores an optional friendly name and an optional description for an object.

## Members

### `name`

 Optional friendly name.

### `description`

Optional description.

## Remarks

In order to
support MUI, both strings may contain indirect strings. See
[SHLoadIndirectString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shloadindirectstring) for details.

**FWPM_DISPLAY_DATA0** is a specific implementation of FWPM_DISPLAY_DATA. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[SHLoadIndirectString](https://learn.microsoft.com/windows/desktop/api/shlwapi/nf-shlwapi-shloadindirectstring)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)