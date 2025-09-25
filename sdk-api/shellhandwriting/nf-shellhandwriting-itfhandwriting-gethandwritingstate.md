# GetHandwritingState function

## Description

Retrieves the current handwriting state for the [Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) (TSF) thread manager.

## Parameters

### `handwritingState` [out]

The system handwriting support. The default is TF_HANDWRITING_AUTO.

## Return value

If the method succeeds, it returns **S_OK**. If it fails, it returns an **HRESULT** error code.

## Remarks

## See also

[TfHandwritingState enumeration](https://learn.microsoft.com/windows/win32/api/shellhandwriting/ne-shellhandwriting-tfhandwritingstate)