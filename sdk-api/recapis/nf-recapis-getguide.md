# GetGuide function

## Description

Retrieves the guide used for boxed, lined, or freeform input.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pGuide`

A guide used for boxed, lined, or freeform input. For guide details, see the [RECO_GUIDE](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_guide) structure.

### `piIndex`

Index value of the first box or line in the context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The context does not contain a guide. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_POINTER** | One of the parameters is an invalid pointer. |

## See also

[RECO_GUIDE Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_guide)

[SetGuide Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setguide)