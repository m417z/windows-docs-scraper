# IEnumSTATPROPSTG::Skip

## Description

The **Skip** method skips the specified number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures in the enumeration sequence.

## Parameters

### `celt`

The number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures to skip.

## Return value

This method supports the following return values:

## Remarks

A positive value for the *celt* parameter skips forward in the [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structure enumeration. A negative value for the *celt* parameter skips backward in the **STATPROPSTG** structure enumeration.