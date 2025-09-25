# ILanguageExceptionStackBackTrace::GetStackBackTrace

## Description

Retrieves the back stack trace.

## Parameters

### `maxFramesToCapture` [in]

The maximum number of frames to capture.

### `stackBackTrace` [in, out]

An array containing the stack back trace; the maximum size is the *maxFramesToCapture*.

### `framesCaptured` [out]

On success, contains a pointer to the number of frames actually captured.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

You should implement **GetStackBackTrace** in your language projections when the Global Error Handler surface is unable to capture a backtrace. **GetStackBackTrace** is called by the [RoOriginateLanguageException](https://learn.microsoft.com/windows/desktop/api/roerrorapi/nf-roerrorapi-rooriginatelanguageexception) export and by [CapturePropagationContext](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nf-restrictederrorinfo-ilanguageexceptionerrorinfo2-capturepropagationcontext) when those functions detect, through querying for interface (QI), that the language exception provided to them implements it.

## See also

[ILanguageExceptionStackBackTrace](https://learn.microsoft.com/windows/desktop/api/restrictederrorinfo/nn-restrictederrorinfo-ilanguageexceptionstackbacktrace)