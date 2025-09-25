# IEnumSTATPROPSETSTG::Next

## Description

The **Next** method retrieves a specified number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures that follow subsequently in the enumeration sequence. If fewer than the requested number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures exist in the enumeration sequence, it retrieves the remaining **STATPROPSETSTG** structures.

## Parameters

### `celt` [in]

The number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures requested.

### `rgelt` [out]

An array of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures returned.

### `pceltFetched` [out]

The number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures retrieved in the *rgelt* parameter.

## Return value

This method supports the following return values:

| Return code | Description |
| --- | --- |
| **S_OK** | The number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures returned equals the number specified in the *celt* parameter. |
| **S_FALSE** | The number of [STATPROPSETSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropsetstg) structures returned is less than the number specified in the *celt* parameter. |