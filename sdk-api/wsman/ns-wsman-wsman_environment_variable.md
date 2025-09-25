# WSMAN_ENVIRONMENT_VARIABLE structure

## Description

Defines an individual environment variable by using a name and value pair. This structure is used by the [WSManCreateShell](https://learn.microsoft.com/windows/desktop/api/wsman/nf-wsman-wsmancreateshell) method. The representation of the **value** variable is shell specific. The client and server must agree on the format of the **value** variable.

## Members

### `name`

Defines the environment variable name. This parameter cannot be **NULL**.

### `value`

Defines the environment variable value. **NULL** or empty string values are permitted.