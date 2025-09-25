# SCESVC_ANALYSIS_LINE structure

## Description

The **SCESVC_ANALYSIS_LINE** structure contains the key, value, and value length for a specific line specified by an
[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info) structure.

## Members

### `Key`

String that contains data key. Typically, this is the name of the configuration parameter to which the **Value** data applies.

### `Value`

Data describing the analysis result for the key. This can be binary data.

### `ValueLen`

Length of the data stored in **Value**, in bytes.

## See also

[SCESVC_ANALYSIS_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_analysis_info)