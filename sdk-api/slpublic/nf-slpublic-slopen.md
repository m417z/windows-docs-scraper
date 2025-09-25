# SLOpen function

## Description

Initializes the Software Licensing Client (SLC)
and connects SLC to the Software Licensing Service (SLS).
If the function succeeds, a context handle is returned for subsequent calls.

## Parameters

### `phSLC` [out]

Type: **HSLC***

A pointer to a context handle returned from the Software Licensing Service.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |