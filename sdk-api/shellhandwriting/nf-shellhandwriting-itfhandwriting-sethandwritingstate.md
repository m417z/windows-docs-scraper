# SetHandwritingState function

## Description

Sets the current handwriting state for the [Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) (TSF) thread manager.

## Parameters

### `handwritingState` [in]

The system handwriting support. The default is TF_HANDWRITING_AUTO.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

This method can be called at any time, however the new state is applied only to the next input that requires handwriting target proximity determination.

## See also

[TfHandwritingState enumeration](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate)