# SCESVC_INFO_TYPE enumeration

## Description

The **SCESVC_INFO_TYPE** enumeration is used by
[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info) and
[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info) to indicate the type of information requested from or passed to the security database. It can be one of the following values.

## Constants

### `SceSvcConfigurationInfo`

The data is configuration information.

### `SceSvcMergedPolicyInfo`

The data is merged policy information.

### `SceSvcAnalysisInfo`

The data is analysis information.

### `SceSvcInternalUse`

Reserved. Do not use.

## See also

[PFSCE_QUERY_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_query_info)

[PFSCE_SET_INFO](https://learn.microsoft.com/windows/desktop/api/scesvc/nc-scesvc-pfsce_set_info)

[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info)

[SCESVC_CONFIGURATION_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info)