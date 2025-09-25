# IEnumSTATPROPSETSTG::Skip

## Description

The **Skip** method skips a specified number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures in the enumeration sequence.

## Parameters

### `celt`

The number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures to skip.

## Return value

This method supports the following return values:

## Remarks

A positive value for the *celt* parameter skips forward in the [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structure enumeration. A negative value for the *celt* parameter skips backward in the **STATPROPSETSTG** structure enumeration.