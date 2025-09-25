# LoadEnclaveImageA function

## Description

Loads an image and all of its imports into an enclave.

## Parameters

### `lpEnclaveAddress` [in]

The base address of the image into which to load the image.

### `lpImageName` [in]

A NULL-terminated string that contains the name of the image to load.

## Return value

`TRUE` if the function succeeds; otherwise `FALSE`.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**LoadEnclaveImage** is only supported enclaves that have the **ENCLAVE_TYPE_VBS** enclave type.

You cannot load an image into the enclave after it has been initialized with [InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave).

## See also

[Enclave functions](https://learn.microsoft.com/windows/win32/trusted-execution/enclaves-functions)

[CreateEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-createenclave)

[InitializeEnclave](https://learn.microsoft.com/windows/win32/api/enclaveapi/nf-enclaveapi-initializeenclave)