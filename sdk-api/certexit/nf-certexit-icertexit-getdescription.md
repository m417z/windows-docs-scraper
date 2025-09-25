# ICertExit::GetDescription

## Description

The **GetDescription** method returns a human-readable description of the exit module and its function. This method was first defined in the [ICertExit](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit) interface.

## Parameters

### `pstrDescription` [out]

A pointer to the **BSTR** that describes the exit module.

## Return value

### C++

If the method succeeds, the method returns S_OK.

If the method fails, it returns an **HRESULT** value that indicates the error. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

### VB

Returns a string that describes the exit module and its function.

## Remarks

When you write a custom exit module, implement this method.

#### Examples

```cpp
STDMETHODIMP
CCertExit::GetDescription(
    /* [out, retval] */ BSTR __RPC_FAR *pstrDescription)
{
    if (NULL == pstrDescription)
    {
        // Bad pointer address.
        return (E_POINTER);
    }
    if (NULL != *pstrDescription)
    {
        SysFreeString(*pstrDescription);
        *pstrDescription=NULL;
    }
    // wszMyExitModuleDesc defined elsewhere, for example:
    // #define wszMyExitModuleDesc L"My Exit Module"
    *pstrDescription = SysAllocString(wszMyExitModuleDesc);
    if (NULL == *pstrDescription)
    {
        // Not enough memory
        return ( E_OUTOFMEMORY );
    }
    // Success
    return( S_OK );
}
```

## See also

[ICertExit](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit)

[ICertExit2](https://learn.microsoft.com/windows/desktop/api/certexit/nn-certexit-icertexit2)