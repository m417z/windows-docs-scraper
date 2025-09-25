# ITsSbProvider::CreatePluginPropertySet

## Description

Creates an [ITsSbPluginPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginpropertyset) plug-in property set object.

## Parameters

### `ppPropertySet` [out, retval]

A pointer to a pointer to an
[ITsSbPluginPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginpropertyset) property set object. When you have finished
using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method.
Because RD Connection Broker is unaware of the contents of the property set object, you should clean the object before calling
its **Release** method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

 Plug-ins can use this method to create a plug-in property set object.

## See also

[ITsSbPluginPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbpluginpropertyset)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)