# TfHandwritingState enumeration

## Description

Specifies how handwriting is processed by the system.

## Constants

### `TF_HANDWRITING_AUTO`

Handwriting behavior is automatically configured based on the presence of a pen and the current handwriting user settings.

### `TF_HANDWRITING_DISABLED`

Handwriting behavior is disabled by the [Text Services Framework](https://learn.microsoft.com/windows/win32/tsf/text-services-framework) (TSF) client.

### `TF_HANDWRITING_ENABLED`

Handwriting behavior is enabled by the TSF client (pen input is withheld from the client).

### `TF_HANDWRITING_POINTERDELIVERY`

Handwriting behavior is enabled by the TSF client (pen input is not withheld from the client), which is responsible for analyzing the pen input and handling buffering, intent determination, and target determination.

## Remarks

## See also

[GetHandwritingState method](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-gethandwritingstate), [SetHandwritingState method](https://learn.microsoft.com/windows/win32/api/shellhandwriting/nf-shellhandwriting-itfhandwriting-sethandwritingstate)