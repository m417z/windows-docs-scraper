# WINSAT_ASSESSMENT_STATE enumeration

## Description

[WINSAT_ASSESSMENT_STATE may be altered or unavailable for releases after Windows 8.1.]

Defines the possible states of an assessment.

## Constants

### `WINSAT_ASSESSMENT_STATE_MIN:0`

The minimum enumeration value for this enumeration.

### `WINSAT_ASSESSMENT_STATE_UNKNOWN:0`

The state of the assessment is unknown.

### `WINSAT_ASSESSMENT_STATE_VALID:1`

The assessment data is valid for the current computer configuration.

### `WINSAT_ASSESSMENT_STATE_INCOHERENT_WITH_HARDWARE:2`

The assessment data does not match the current computer configuration. The hardware on the computer has changed since the last time a formal assessment was run.

### `WINSAT_ASSESSMENT_STATE_NOT_AVAILABLE:3`

The assessment data is not available because a formal WinSAT assessment has not been run on this computer.

### `WINSAT_ASSESSMENT_STATE_INVALID:4`

The assessment data is not valid.

### `WINSAT_ASSESSMENT_STATE_MAX:4`

The maximum enumeration value for this enumeration.

## See also

[IProvideWinSATResultsInfo::get_AssessmentState](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-get_assessmentstate)

[IProvideWinSATVisuals::get_Bitmap](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatvisuals-get_bitmap)