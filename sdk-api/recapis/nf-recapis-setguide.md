# SetGuide function

## Description

Sets the recognition guide to use for boxed or lined input. You must call this function before you add strokes to the context.

## Parameters

### `hrc`

Handle to the recognizer context.

### `pGuide`

Guide to use for box or line input. Setting this parameter to **NULL** means that the context has no guide. This is the default and means the recognizer is in free input mode. For guide details, see the [RECO_GUIDE](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_guide) structure.

### `iIndex`

Index value to use for the first box or line in the context.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |
| **E_OUTOFMEMORY** | Unable to allocate memory to complete the operation. |
| **E_INVALIDARG** | Attempted to set a recognition mode (free, lined, boxed, and so on) that is not supported by the recognizer, or the RECO_GUIDE field values are illegal (negative heights or widths, for example). |
| **E_FAIL** | An unspecified error occurred. |
| **TPC_E_OUT_OF_ORDER_CALL** | Attempted to set guide when there was already some ink in the reco context, or, in the case of recognizers of East Asian characters, [SetCACMode](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setcacmode) was called previously. |

## Remarks

Guide boxes are numbered based on the *iIntex* value.

## See also

[GetGuide Function](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-getguide)

[RECO_GUIDE Structure](https://learn.microsoft.com/windows/desktop/api/rectypes/ns-rectypes-reco_guide)