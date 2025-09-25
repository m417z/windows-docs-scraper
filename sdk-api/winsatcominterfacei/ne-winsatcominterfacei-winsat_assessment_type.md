# WINSAT_ASSESSMENT_TYPE enumeration

## Description

[WINSAT_ASSESSMENT_TYPE may be altered or unavailable for releases after Windows 8.1.]

Defines the possible subcomponents of an assessment.

## Constants

### `WINSAT_ASSESSMENT_MEMORY:0`

Assess the memory of the computer.

### `WINSAT_ASSESSMENT_CPU:1`

Assess the processors on the computer.

### `WINSAT_ASSESSMENT_DISK:2`

Assess the primary hard disk on the computer.

### `WINSAT_ASSESSMENT_D3D:3`

After Windows 8.1, WinSAT no longer assesses the three-dimensional graphics (gaming) capabilities of the computer and the graphics driver's ability to render objects and execute shaders using this assessment. For compatibility, WinSAT reports sentinel values for the metrics and scores, however these are not calculated in real time.

### `WINSAT_ASSESSMENT_GRAPHICS:4`

 Assess the video card abilities required for Desktop Window Manager (DWM) composition.

## See also

[IProvideWinSATResultsInfo::GetAssessmentInfo](https://learn.microsoft.com/windows/desktop/api/winsatcominterfacei/nf-winsatcominterfacei-iprovidewinsatresultsinfo-getassessmentinfo)