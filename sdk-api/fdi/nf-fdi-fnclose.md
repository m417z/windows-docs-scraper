# FNCLOSE macro

## Description

The **FNCLOSE** macro provides the declaration for the application-defined callback function to close a file in an FDI context.

## Parameters

### `fn` [in]

An application-defined value used to identify the open file.

## Remarks

The function accepts parameters similar to [_close](https://msdn.microsoft.com/library/5fzwd5ss(VS.80).aspx).

#### Examples

```cpp
FNCLOSE(fnFileClose)
{
    return ( CloseHandle((HANDLE)hf) == TRUE ) ? 0 : -1;
}

```