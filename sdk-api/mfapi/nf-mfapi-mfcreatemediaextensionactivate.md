# MFCreateMediaExtensionActivate function

## Description

Creates an activation object for a Windows Runtime class.

## Parameters

### `szActivatableClassId` [in]

The class identifier that is associated with the activatable runtime class.

### `pConfiguration` [in]

A pointer to an optional [IPropertySet](https://learn.microsoft.com/uwp/api/windows.foundation.collections.ipropertyset) object, which is used to configure the Windows Runtime class. This parameter can be **NULL**.

### `riid` [in]

The interface identifier (IID) of the interface being requested. The activation object created by this function supports the following interfaces:

* [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory)
* [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate)
* [IPersistStream](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-ipersiststream)

### `ppvObject` [out]

Receives a pointer to the requested interface. The caller must release the interface.

## Return value

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To create the Windows Runtime object, call [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) or [IClassFactory::CreateInstance](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iclassfactory-createinstance).

## See also

[Media Foundation Functions](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-functions)