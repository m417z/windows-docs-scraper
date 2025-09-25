# IViewObject::GetAdvise

## Description

Retrieves the advisory connection on the object that was used in the most recent call to [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise).

## Parameters

### `pAspects` [out]

Pointer to where the *dwAspect* parameter from the previous [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise) call is returned. If this pointer is **NULL**, the caller does not permit this value to be returned.

### `pAdvf` [out]

Pointer to where the *advf* parameter from the previous [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise) call is returned. If this pointer is **NULL**, the caller does not permit this value to be returned.

### `ppAdvSink` [out]

Address of [IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink) pointer variable that receives the interface pointer to the advise sink. The connection to this advise sink must have been established with a previous [IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise) call, which provides the *pAdvSink* parameter. If *ppvAdvSink* is **NULL**, there is no established advisory connection.

## Return value

This method returns S_OK on success.

## See also

[ADVF](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-advf)

[IAdviseSink](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iadvisesink)

[IViewObject](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iviewobject)

[IViewObject::SetAdvise](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iviewobject-setadvise)