# IUnknown_QueryService function

## Description

Retrieves an interface for a service from a specified object.

## Parameters

### `punk` [in]

Type: **[IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) instance of the COM object that supports the service.

### `guidService` [in]

Type: **REFGUID**

The service's unique identifier (SID).

### `riid` [in]

Type: **REFIID**

The IID of the desired service interface.

### `ppvOut` [out]

Type: **void****

When this method returns, contains the interface pointer requested *riid*. If successful, the calling application is responsible for calling [IUnknown::Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) using this value when the service is no longer needed. In the case of failure, this value is **NULL**.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful. Returns **E_FAIL** if the object does not support [IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)). Otherwise, the function returns the **HRESULT** returned by the object's [QueryService](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678966(v=vs.85)) method.

## Remarks

If the object passed in the *punk* parameter supports the [IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85)) interface, then its [QueryService](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678966(v=vs.85)) method is invoked, passing the *guidService*, *riid*, and *ppvOut* parameters and propagating the return value. Otherwise, the function returns E_FAIL.

For those versions of Windows that do not include **IUnknown_QueryService** in Shlwapi.h, this function must be called directly from Shlwapi.dll using ordinal 176.

## See also

[IServiceProvider](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678965(v=vs.85))

[QueryService](https://learn.microsoft.com/previous-versions/windows/internet-explorer/ie-developer/platform-apis/cc678966(v=vs.85))