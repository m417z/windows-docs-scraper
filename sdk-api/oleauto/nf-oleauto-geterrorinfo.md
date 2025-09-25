# GetErrorInfo function

## Description

Obtains the error information pointer set by the previous call to [SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo) in the current logical thread.

## Parameters

### `dwReserved` [in]

Reserved for future use. Must be zero.

### `pperrinfo` [out]

An error object.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **S_FALSE** | There was no error object to return. |

## Remarks

This function returns a pointer to the most recently set [IErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-ierrorinfo) pointer in the current logical thread. It transfers ownership of the error object to the caller, and clears the error state for the thread.

Making a COM call that goes through a proxy-stub will clear any existing error object for the calling thread. A called object should not make any such calls after calling [SetErrorInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-seterrorinfo) and before returning. The caller should not make any such calls after the call returns and before calling **GetErrorInfo**. As a rule of thumb, an interface method should return as soon as possible after calling **SetErrorInfo**, and the caller should call **GetErrorInfo** as soon as possible after the call returns.