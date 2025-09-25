# IPropertyPage::SetObjects

## Description

Provides the property page with an array of pointers to objects associated with this property page.

When the property page receives a call to [IPropertyPage::Apply](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-apply), it must send value changes to these objects through whatever interfaces are appropriate. The property page must query for those interfaces. This method can fail if the objects do not support the interfaces expected by the property page.

## Parameters

### `cObjects` [in]

The number of pointers in the array pointed to by *ppUnk*. If this parameter is 0, the property page must release any pointers previously passed to this method.

### `ppUnk` [in]

A pointer to an array of [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface pointers where each pointer identifies a unique object affected by the property sheet in which this (and possibly other) property pages are displayed. The property page must cache these pointers calling [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) for each pointer at that time. This array of pointers is the same one that was passed to [OleCreatePropertyFrame](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframe) or [OleCreatePropertyFrameIndirect](https://learn.microsoft.com/windows/desktop/api/olectl/nf-olectl-olecreatepropertyframeindirect) to invoke the property sheet.

## Return value

This method can return the standard return values E_FAIL, E_INVALIDARG, E_OUTOFMEMORY, and E_UNEXPECTED, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The property page successfully saved the pointers it needed. |
| **E_NOINTERFACE** | One of the objects in *ppUnk* did not support the interface expected by this property page, and so this property page cannot communicate with it. |
| **E_POINTER** | The address in *ppUnk* is not valid. For example, it may be **NULL**. |

## Remarks

The property page is required to keep the pointers returned by this method or others queried through them. If these specific [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) pointers are held, the property page must call [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) through each when caching them, until the time when **SetObjects** is called with *cObjects* equal to 0. At that time, the property page must call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) through each pointer, releasing any objects that it held.

The caller must provide the property page with these objects before calling [IPropertyPage::Activate](https://learn.microsoft.com/windows/desktop/api/ocidl/nf-ocidl-ipropertypage-activate), and should call **SetObjects** with zero as the parameter when deactivating the page or when releasing the object entirely. Each call to **SetObjects** with a non-**NULL***ppUnk* parameter must be matched with a later call to **SetObjects** with 0 in the *cObjects* parameter.

### Notes to Implementers

E_NOTIMPL is not a valid return value.

## See also

[IPropertyPage](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ipropertypage)