# MI_ParameterSet_GetParameter function

## Description

Gets a method's parameter information based on a parameter name.

## Parameters

### `self` [in]

[MI_ParameterSet](https://learn.microsoft.com/windows/desktop/api/mi/ns-mi-mi_parameterset) structure.

### `name` [in]

Name of the parameter to get.

### `parameterType` [out]

Returned parameter type.

### `referenceClass` [out]

Returned reference class.

### `qualifierSet` [out]

Returned qualifier set of the parameter.

### `index` [out]

Returned zero-based index of the parameter.

## Return value

This function returns MI_INLINE MI_Result.