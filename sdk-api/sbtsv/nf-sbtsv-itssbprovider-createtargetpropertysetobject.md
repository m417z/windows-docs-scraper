# ITsSbProvider::CreateTargetPropertySetObject

## Description

Creates an [ITsSbTargetPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtargetpropertyset) target property set object.

## Parameters

### `ppPropertySet` [out]

A pointer to a pointer to an [ITsSbTargetPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtargetpropertyset) property set object. When you have finished using the object, release it by calling the [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) method. Because RD Connection Broker is unaware of the contents of the property set object, you should clean the object before calling its **Release** method.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins can use this method to create a target property set object.

## See also

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)

[ITsSbTargetPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbtargetpropertyset)