# CM_MapCrToWin32Err function

## Description

Converts a specified **CONFIGRET** code to its equivalent system error
code.

## Parameters

### `CmReturnCode` [in]

The **CONFIGRET** code to be converted. **CONFIGRET**
error codes are defined in CfgMgr32.h.

### `DefaultErr` [in]

A default system error code to be returned when no system error code is mapped to the specified
**CONFIGRET** code.

## Return value

The system error code that corresponds to the **CONFIGRET** code. System error codes
are defined in Winerror.h.

When there is no mapping from the specified **CONFIGRET** code to a system error
code, **CM_MapCrToWin32Err** returns the value
specified in the *DefaultErr* parameter.