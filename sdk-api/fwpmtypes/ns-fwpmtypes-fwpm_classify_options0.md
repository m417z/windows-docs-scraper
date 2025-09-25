# FWPM_CLASSIFY_OPTIONS0 structure

## Description

 The **FWPM_CLASSIFY_OPTIONS0** structure is used to store **FWPM_CLASSIFY_OPTION0** structures.

## Members

### `numOptions`

Number of **FWPM_CLASSIFY_OPTION0** structures in the **options** member.

### `options`

[size_is(numCredentials)]

Pointer to an array of [FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_option0) structures.

## Remarks

**FWPM_CLASSIFY_OPTIONS0** is a specific implementation of FWPM_CLASSIFY_OPTIONS. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_CLASSIFY_OPTION0](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ns-fwpmtypes-fwpm_classify_option0)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)