# SCESVC_CONFIGURATION_LINE structure

## Description

The **SCESVC_CONFIGURATION_LINE** structure contains information about a line of configuration data. It is used by the
[SCESVC_CONFIGURATION_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info) structure.

## Members

### `Key`

String that contains data key. Typically this is the name of the configuration parameter to which the **Value** data applies.

### `Value`

String that contains data describing the configuration.

### `ValueLen`

Length of the data stored in **Value**, in bytes.

## See also

[SCESVC_CONFIGURATION_INFO](https://learn.microsoft.com/windows/win32/api/scesvc/ns-scesvc-scesvc_configuration_info)