# SCESVC_CONFIGURATION_INFO structure

## Description

The **SCESVC_CONFIGURATION_INFO** structure provides configuration information for a service. This structure is used by the
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) and
[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info) functions when the configuration information is specified.

## Members

### `Count`

Indicates the number of lines of data returned in the **Lines** array.

### `Lines`

Pointer to an array of
[SCESVC_CONFIGURATION_LINE](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_line) structures which contains the configuration data for this service. Each element represents a line in the security template or database.

## Remarks

When analysis information is specified, the
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) and
[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info) functions use the
[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info) structure.

## See also

[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info)

[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info)

[SCESVC_CONFIGURATION_LINE](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_line)

[SCESVC_INFO_TYPE](https://learn.microsoft.com/windows/desktop/api/scesvc/ne-scesvc-scesvc_info_type)