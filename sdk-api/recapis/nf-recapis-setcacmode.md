# SetCACMode function

## Description

Specifies character Autocomplete mode for character or word recognition.

You cannot turn off character Autocomplete after it is set.

## Parameters

### `hrc`

The handle to the recognizer context.

### `iMode`

The following table lists the possible character Autocomplete modes.

| The character Autocomplete mode. | Meaning |
| --- | --- |
| **CAC_FULL** | Recognition occurs as if all strokes have been completed. |
| **CAC_PREFIX** | Recognition occurs on partial input. The order of the strokes must conform to the rules of the language. |
| **CAC_RANDOM** | Recognition occurs on partial input. The order of the strokes can be arbitrary. |

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | The specified mode is invalid. |
| **E_NOTIMPL** | The recognizer does not support this function. |
| **E_FAIL** | Either you have not called the [SetGuide](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setguide) function before calling this function, or the guide has more than one box. |
| **E_POINTER** | The context is invalid or one of the parameters is an invalid pointer. |
| **TPC_E_OUT_OF_ORDER_CALL** | Attempted to set guide when there was already some ink in the reco context, or, in the case of recognizers of East Asian characters, [SetGuide](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-setguide) was called previously. |