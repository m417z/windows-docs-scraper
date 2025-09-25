# PARAM_BUFFER structure

## Description

The **PARAM_BUFFER** structure describes the format of the parameter buffer that can be included in the [CONTROL_SERVICE](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-control_service) structure.

## Members

### `ParameterId`

Parameter ID, as defined by INTSERV.

### `Length`

Length of the entire **PARAM_BUFFER** structure.

### `Buffer`

Buffer containing the parameter.

## See also

[CONTROL_SERVICE](https://learn.microsoft.com/windows/desktop/api/qossp/ns-qossp-control_service)