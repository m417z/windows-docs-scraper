# Process function

## Description

Performs ink recognition synchronously.

## Parameters

### `hrc`

The handle to the recognizer context.

### `pbPartialProcessing`

Specify **TRUE** to process a subset of the ink. Partial processing reduces the time the recognizer spends performing recognition if more ink is expected.

Typically an application specifies **FALSE** to process all the ink. The function does not process all the ink if you have not called the [EndInkInput](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-endinkinput) function.

The function sets the *pbPartialProcessing* parameter to **TRUE** if there is enough ink left to continue processing; otherwise, **FALSE**.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | The function did not process the ink because the ink has been fully processed, or the [EndInkInput](https://learn.microsoft.com/windows/desktop/api/msinkaut/nf-msinkaut-iinkrecognizercontext-endinkinput) function has not been called and the recognizer does not support incremental processing of ink. |
| **TPC_S_INTERRUPTED** | The process was interrupted by a call to the [AdviseInkChange](https://learn.microsoft.com/windows/desktop/api/recapis/nf-recapis-adviseinkchange) function. |
| **E_POINTER** | One of the parameters is an invalid pointer. |
| **E_FAIL** | An unspecified error occurred. |
| **E_INVALIDARG** | An invalid argument was received. |