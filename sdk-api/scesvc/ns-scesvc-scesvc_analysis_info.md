# SCESVC_ANALYSIS_INFO structure

## Description

The **SCESVC_ANALYSIS_INFO** structure contains the analysis information. It contains a
[SCESVC_ANALYSIS_LINE](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_line) structure that contains lines of analysis information, and it also contains a counter that indicates the number of lines.

A pointer to this structure is returned by calls to
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) and
[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info) when analysis information is specified.

## Members

### `Count`

A **DWORD** that indicates the number of lines in the array.

### `Lines`

Pointer to an array of
[SCESVC_ANALYSIS_LINE](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_line) structures which contain the analysis information.

## See also

[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info)

[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info)

[SCESVC_ANALYSIS_LINE](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_line)

[SCESVC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/scesvc/ne-scesvc-scesvc_info_type)