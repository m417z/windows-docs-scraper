# CLUSCTL_USER_CODE macro

## Description

Generates a correctly
formatted user-defined control code. For more information on the bit layout of control codes, see
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture).

## Parameters

### `Function`

Value that specifies the operation code (bits 0–23) and, optionally, the access code
(bits 0–1) of the resulting control code. The operation code can be any 19-bit value chosen
by the caller. The access code (if specified) should be set to one of the following values.

#### 0 (CLUS_ACCESS_ANY)

The control code has no access requirements.

#### 1 (CLUS_ACCESS_READ)

Use of the control code requires read access.

#### 2 (CLUS_ACCESS_WRITE)

Use of the control code requires write access.

### `Object`

An 8-bit value that specifies the object code (bits 24–31) of the resulting control
code. For more information on the bit layout of control codes, see
[Control Code Architecture](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/control-code-architecture). The
object code can be set to any value greater than **CLUS_OBJECT_USER** (128).

## Remarks

Do not pass bit-shifted values for *Function* or *Object*. The
macro performs the required bit shifts.

If no access code is specified, the control code will default to
**CLUS_ACCESS_ANY**.

#### Examples

See the example under
[Creating Control Codes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-control-codes).

## See also

[CLUSCTL_GET_ACCESS_MODE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusctl_get_access_mode)

[CLUSCTL_GET_CONTROL_FUNCTION](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusctl_get_control_function)

[CLUSCTL_GET_CONTROL_OBJECT](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusctl_get_control_object)