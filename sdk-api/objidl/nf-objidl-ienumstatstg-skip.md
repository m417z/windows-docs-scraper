# IEnumSTATSTG::Skip

## Description

The **Skip** method skips a specified number
of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures in the enumeration
sequence.

## Parameters

### `celt`

The number of [STATSTG](https://learn.microsoft.com/windows/desktop/api/objidl/ns-objidl-statstg) structures to skip.

## Return value

This method supports the following return values:

| Return code | Description |
|----------------|---------------|
| S_OK | The specified number of **STATSTG** structures that were successfully skipped. |
| S_FALSE | The number of **STATSTG** structures skipped is less than the *celt* parameter. |