# SHRegGetBoolValueFromHKCUHKLM function

## Description

[This function is no longer supported.]

Evaluates a registry key value and returns a boolean value that reflects whether the value exists and the expected state matches the actual state. This function will first check HKEY_CURRENT_USER for the requested information in the specified subkey. If the information does not exist under the HKEY_CURRENT_USER subtree it will check the HKEY_LOCAL_MACHINE subtree for the same information.

## Parameters

### `pszKey`

Type: **PCWSTR**

A pointer to a null-terminated Unicode string that specifies the path to the key to be checked.

### `pszValue` [in]

Type: **PCWSTR**

A pointer to a null-terminated Unicode string that specifies the value to be evaluated.

### `fDefault` [in]

Type: **BOOL**

The expected state of the evaluation, as defined by the calling function.

## Return value

Type: **BOOL**

**TRUE** if the evaluation matches the *fDefault* value; otherwise, **FALSE**.