# CreateRecognizer function

## Description

Creates a recognizer.

## Parameters

### `pCLSID`

CLSID of the recognizer. This value is created in the registry when you register the recognizer.

### `phrec`

Handle for the recognizer.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_FAIL** | An unspecified error occurred. |
| **E_POINTER** | The parameter is an invalid pointer. |
| **E_INVALIDARG** | An invalid argument was received. |
| **E_OUTOFMEMORY** | Insufficient memory. |

## See also

[Registering Your Recognizer DLL](https://learn.microsoft.com/windows/desktop/tablet/registering-your-recognizer-dll)