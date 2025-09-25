# SLClose function

## Description

Closes the Software Licensing Client (SLC) context handle. When this function is called,
the associated context on the Software Licensing Service (SLS) is released.

## Parameters

### `hSLC` [in]

Type: **HSLC**

The handle to the current SLC context.

## Return value

Type: **HRESULT WINAPI**

If this function succeeds, it return **S_OK**. Otherwise, it returns an **HRESULT** error code.

| Return code/value | Description |
| --- | --- |
| **E_INVALIDARG**<br><br>0x80070057 | One or more arguments are not valid. |