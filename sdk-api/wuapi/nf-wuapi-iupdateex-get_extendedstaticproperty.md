## Description

Gets the value of an extended static property. This value is read-only.

## Parameters

### `propertyName` [in]

The name of the static extended property being queried. The following values are currently supported:

* "ContainsUpdateBootstrapper"

### `retval` [out]

A pointer to a **VARIANT** that contains the value of the queried static property.

## Return value

An **HRESULT** including one of the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| E_INVALIDARG | The specified property is invalid. |
| WU_E_NOT_SUPPORTED | The specified property or operation is unsupported. |

## Remarks

## See also