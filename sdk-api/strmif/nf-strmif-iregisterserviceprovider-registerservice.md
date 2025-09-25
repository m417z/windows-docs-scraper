# IRegisterServiceProvider::RegisterService

## Description

\[The feature associated with this page, [DirectShow](https://learn.microsoft.com/windows/win32/directshow/directshow), is a legacy feature. It has been superseded by [MediaPlayer](https://learn.microsoft.com/uwp/api/Windows.Media.Playback.MediaPlayer), [IMFMediaEngine](https://learn.microsoft.com/windows/win32/api/mfmediaengine/nn-mfmediaengine-imfmediaengine), and [Audio/Video Capture in Media Foundation](https://learn.microsoft.com/windows/win32/medfound/audio-video-capture-in-media-foundation). Those features have been optimized for Windows 10 and Windows 11. Microsoft strongly recommends that new code use **MediaPlayer**, **IMFMediaEngine** and **Audio/Video Capture in Media Foundation** instead of **DirectShow**, when possible. Microsoft suggests that existing code that uses the legacy APIs be rewritten to use the new APIs if possible.\]

The `RegisterService` method registers an object as a service.

## Parameters

### `guidService` [in]

Service identifier (SID) of the service.

### `pUnkObject` [in]

Pointer to the **IUnknown** interface of the service object, or **NULL** to unregister the service.

## Return value

Returns an **HRESULT** value.

## Remarks

A service is an interface that a client discovers through the COM **IServiceProvider::QueryService** method, instead of through the usual **IUnknown::QueryInterface** method. The difference between the two methods is that **QueryInterface** returns an interface on the original object, whereas **QueryService** may return an interface on another object. (More precisely, **QueryInterface** guarantees that you can query the original interface and the returned interface for **IUnknown**, and you will get back identical pointers. **QueryService** does not have this guarantee.)

The `RegisterService` method enables you to register a service with the Filter Graph Manager. Other objects can then use the **IServiceProvider** interface to retrieve your object. This facilitates communication between separate COM objects, using the Filter Graph Manager as the central communication point.

A service is identified by a GUID, called the service identifier (SID). One service can support multiple interfaces. To register the service, call `RegisterService`, as shown in the following code:

| C++ |
| --- |
| ``` DEFINE_GUID(SID_MyService, ....); IRegisterServiceProvider *pRSP; hr = pGraph->QueryInterface(IID_IRegisterServiceProvider, (void**)&pRSP); if (SUCCEEDED(hr)) {     IUnknown pServiceObj;     MyCreateServiceHelper(SID_MyService, &pServiceObj);     pRSP->RegisterService(SID_MyService, pServiceObj);     pRSP->Release();     pServiceObj->Release(); } ``` |

This example assumes that MyCreateServiceHelper is a helper function that creates the service object. A client could get a pointer to the service object by calling **IServiceProvider::QueryService**:

| C++ |
| --- |
| ``` IServiceProvider *pSP; hr = pGraph->QueryInterface(IID_IServiceProvider, (void**)&pSP); if (SUCCEEDED(hr)) {     ISomeInterface *pService;     hr = pSP->QueryService(SID_MyService, IID_ISomeInterface, (void**)&pService);     pSP->Release();     if (SUCCEEDED(hr))     {         pService->SomeMethod();         pService->Release();     } }; ``` |

To unregister the service, call `RegisterService` with a **NULL** pointer in the second parameter:

| C++ |
| --- |
| ``` pRSP->RegisterService(SID_MyService, NULL); ``` |

When the Filter Graph Manager is released, it unregisters all services.

The Filter Graph Manager keeps a reference count on the service object until the service is unregistered. To prevent circular reference counts, the service object should not hold a reference count on the Filter Graph Manager. For example, you cannot use the destructor method of the service object to unregister the service, because as long as the service holds a reference count on the Filter Graph Manager, the destructor will never be called. One solution is to create a separate object that registers and unregisters the service. Or, you can simply release the service object after you register it and let the Filter Graph Manager control its lifetime.

## See also

[Error and Success Codes](https://learn.microsoft.com/windows/desktop/DirectShow/error-and-success-codes)

[IRegisterServiceProvider Interface](https://learn.microsoft.com/windows/desktop/api/strmif/nn-strmif-iregisterserviceprovider)