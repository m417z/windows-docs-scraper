# HYPOTHESIS structure

## Description

The **HYPOTHESIS** structure contains data used to submit a hypothesis to NDF for another helper class. The name of the helper class, the number of parameters that the helper class requires, and the parameters to pass to the helper class are contained in this structure.

## Members

### `pwszClassName`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that contains the name of the helper class.

### `pwszDescription`

Type: **[string] LPWSTR**

A pointer to a null-terminated string that contains a user-friendly description of the data being passed to the helper class..

### `celt`

Type: **ULONG**

The count of attributes in this hypothesis.

### `rgAttributes`

Type: **[size_is(celt)]PHELPER_ATTRIBUTE[ ]**

A pointer to an array of [HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute) structures that contains key attributes for this hypothesis.

## See also

[HELPER_ATTRIBUTE](https://learn.microsoft.com/windows/desktop/api/ndattrib/ns-ndattrib-helper_attribute)