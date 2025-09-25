# IEnumSTATPROPSTG::Next

## Description

The **Next** method retrieves a specified number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures, that follow subsequently in the enumeration sequence. If fewer than the requested number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures exist in the enumeration sequence, it retrieves the remaining **STATPROPSTG** structures.

## Parameters

### `celt` [in]

The number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures requested.

### `rgelt` [out]

An array of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures returned.

### `pceltFetched` [out]

The number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures retrieved in the *rgelt* parameter.

## Return value

This method supports the following return values.

| Return code | Description |
| --- | --- |
| **S_OK** | The number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures returned is equal to the number specified in the *celt* parameter. |
| **S_FALSE** | The number of [STATPROPSTG](https://learn.microsoft.com/windows/desktop/api/propidl/ns-propidl-statpropstg) structures returned is less than the number specified in the *celt* parameter. |