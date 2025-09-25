# CoGetApartmentType function

## Description

Returns the current apartment type and type qualifier.

## Parameters

### `pAptType` [out]

[APTTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttype) enumeration value that specifies the type of the current apartment.

### `pAptQualifier` [out]

[APTTYPEQUALIFIER](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttypequalifier) enumeration value that specifies the type qualifier of the current apartment.

## Return value

Returns S_OK if the call succeeded. Otherwise, one of the following error codes is returned.

| Return code | Description |
| --- | --- |
| **E_FAIL** | The call could not successfully query the current apartment type and type qualifier. |
| **E_INVALIDARG** | An invalid parameter value was supplied to the function. Specifically, one or both of the parameters were set to **NULL** by the caller. |
| **CO_E_NOTINITIALIZED** | [CoInitialize](https://learn.microsoft.com/windows/desktop/api/objbase/nf-objbase-coinitialize) or [CoInitializeEx](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coinitializeex) was not called on this thread prior to calling [CoGetApartmentType](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetapartmenttype). |

## Remarks

On Windows platforms prior to Windows 7, the following actions must be taken on a thread to query the apartment type:

* Call [CoGetContextToken](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cogetcontexttoken) to obtain the current context token.
* Cast the context token to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)* pointer.
* Call the [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) method on that pointer to obtain the [IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo) interface.
* Call the [GetCurrentApartmentType](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-icomthreadinginfo-getcurrentapartmenttype) method of the [IComThreadingInfo](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-icomthreadinginfo) interface to obtain the current apartment type.

In multithreaded scenarios, there is a race condition which can potentially cause an Access Violation within the process when executing the above sequence of operations. The **CoGetApartmentType** function is recommended as it does not potentially incur the Access Violation.

## See also

[APTTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttype)

[APTTYPEQUALIFIER](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttypequalifier)