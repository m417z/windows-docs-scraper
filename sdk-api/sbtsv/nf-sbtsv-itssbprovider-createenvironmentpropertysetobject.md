# ITsSbProvider::CreateEnvironmentPropertySetObject

## Description

Creates an [ITsSbEnvironmentPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironmentpropertyset) environment property set object.

## Parameters

### `ppPropertySet` [out]

A pointer to the created [ITsSbEnvironmentPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironmentpropertyset) environment property set object.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Plug-ins can use this method to create an environment property set object.

## See also

[ITsSbEnvironmentPropertySet](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbenvironmentpropertyset)

[ITsSbProvider](https://learn.microsoft.com/windows/desktop/api/sbtsv/nn-sbtsv-itssbprovider)