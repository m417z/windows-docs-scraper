# FWPM_FIELD0 structure

## Description

The **FWPM_FIELD0** structure specifies schema information for a field.

## Members

### `fieldKey`

Uniquely identifies the field. See FWPM_CONDITION_* identifiers in the topic [Filtering Condition Identifiers](https://learn.microsoft.com/windows/desktop/FWP/filtering-condition-identifiers-).

### `type`

Determines how **dataType** is interpreted.

See [FWPM_FIELD_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_field_type) for more information.

### `dataType`

Data type passed to classify.

See [FWP_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_data_type) for more information.

## Remarks

**FWPM_FIELD0** is a specific implementation of FWPM_FIELD. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## See also

[FWPM_FIELD_TYPE](https://learn.microsoft.com/windows/desktop/api/fwpmtypes/ne-fwpmtypes-fwpm_field_type)

[FWP_DATA_TYPE](https://learn.microsoft.com/windows/desktop/api/fwptypes/ne-fwptypes-fwp_data_type)

[Windows Filtering Platform API Structures](https://learn.microsoft.com/windows/desktop/FWP/fwp-structs)