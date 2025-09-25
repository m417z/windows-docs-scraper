# FWPS_FILTER_CONDITION0 structure

## Description

The **FWPS_FILTER_CONDITION0** structure defines a run-time filtering condition for a filter.

**Note** **FWPS_FILTER_CONDITION0** is a specific version of **FWPS_FILTER_CONDITION**. See [WFP Version-Independent Names and Targeting Specific Versions of Windows](https://learn.microsoft.com/windows/desktop/FWP/wfp-version-independent-names-and-targeting-specific-versions-of-windows) for more information.

## Members

### `fieldId`

The data field identifier for the data field tested by this filtering condition. The meaning of
the numeric value of this member is specific to the filtering layer specified by the
**layerId** member. For a description of the data field identifiers for each filtering layer, see
[Data Field Identifiers](https://learn.microsoft.com/windows-hardware/drivers/network/data-field-identifiers).

### `reserved`

Reserved for system use. Callout drivers should ignore this member.

### `matchType`

An
[FWP_MATCH_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552437(v=vs.85)) value that specifies the type
of match that the filter engine is to test on the data field to check whether the filtering condition is
true.

### `conditionValue`

An
[FWP_CONDITION_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552430(v=vs.85)) structure that
specifies the value against which the data field is tested.

## Remarks

The
**filterCondition** member of the
[FWPS_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_filter0) structure points to an array of
FWPS_FILTER_CONDITION0 structures that specify the run-time filtering conditions for a filter.

## See also

[FWPS_FILTER0](https://learn.microsoft.com/windows/desktop/api/fwpstypes/ns-fwpstypes-fwps_filter0)

[FWP_CONDITION_VALUE0](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552430(v=vs.85))

[FWP_MATCH_TYPE](https://learn.microsoft.com/previous-versions/windows/hardware/drivers/ff552437(v=vs.85))