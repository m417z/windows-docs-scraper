## Description

Evaluates the value of an extended dynamic property. This value is read-only.

## Parameters

### `propertyName` [in]

The name of the dynamic extended property whose value should be evaluated. The following values are currently supported:

* "DoesUpdateRequireReboot" - Evaluating this attribute requires the update bootstrapper to be downloaded at a minimum.

### `retval` [out]

A pointer to a **VARIANT** that contains the value of the evaluated dynamic property.

## Return value

An **HRESULT** including one of the following values:

| Value | Description |
|-------|-------------|
| S_OK | Success. |
| E_INVALIDARG | The specified property is invalid. |
| WU_E_NOT_SUPPORTED | The specified property is unsupported for reasons such as when the update doesn't contain the required update bootstrapper. |
| WU_E_DM_NOTDOWNLOADED | The update contains an update bootstrapper, but it was not downloaded. |

## Remarks

## See also