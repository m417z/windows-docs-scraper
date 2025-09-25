# SetErrorInfo function

## Description

Sets the error information object for the current logical thread of execution.

## Parameters

### `dwReserved` [in]

Reserved for future use. Must be zero.

### `perrinfo` [in, optional]

An error object.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function releases the existing error information object, if one exists, and sets the pointer to *perrinfo*. Use this function after creating an error object that associates the object with the current logical thread of execution.

If the property or method that calls **SetErrorInfo** is called by [DispInvoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-dispinvoke), then **DispInvoke** will fill the EXCEPINFO parameter with the values specified in the error information object. **DispInvoke** will return DISP_E_EXCEPTION when the property or method returns a failure return value for **DispInvoke**

Virtual function table (VTBL) binding controllers that do not use [IDispatch::Invoke](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nf-oaidl-idispatch-invoke) can get the error information object by using [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo). This allows an object that supports a dual interface to use **SetErrorInfo**, regardless of whether the client uses VTBL binding or [IDispatch](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-idispatch).

When a cross apartment call is made COM clears out any error object.

Making a COM call that goes through a proxy-stub will clear any existing error object for the calling thread. A called object should not make any such calls after calling **SetErrorInfo** and before returning. The caller should not make any such calls after the call returns and before calling [GetErrorInfo](https://learn.microsoft.com/windows/desktop/api/oleauto/nf-oleauto-geterrorinfo). As a rule of thumb, an interface method should return as soon as possible after calling **SetErrorInfo**, and the caller should call **GetErrorInfo** as soon as possible after the call returns.

Entering the COM modal message loop will clear any existing error object. A called object should not enter a message loop after calling **SetErrorInfo**.

#### Examples

```cpp
ICreateErrorInfo *pcerrinfo;
IErrorInfo *perrinfo;
HRESULT hr;

hr = CreateErrorInfo(&pcerrinfo);
if (SUCCEEDED(hr))
{
   hr = pcerrinfo->QueryInterface(IID_IErrorInfo, (LPVOID FAR*) &perrinfo);
   if (SUCCEEDED(hr))
   {
      SetErrorInfo(0, perrinfo);
      perrinfo->Release();
   }
   pcerrinfo->Release();
}

```