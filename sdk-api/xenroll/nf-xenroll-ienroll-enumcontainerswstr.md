# IEnroll::enumContainersWStr

## Description

[This method is no longer available for use as of Windows Server 2008 and Windows Vista.]

The **enumContainersWStr** method retrieves the names of containers for the [cryptographic service provider](https://learn.microsoft.com/windows/desktop/SecGloss/c-gly) (CSP) specified by the
[ProviderNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_providernamewstr) property. This method was first defined in the [IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll) interface.

## Parameters

### `dwIndex` [in]

Specifies the ordinal position of the container whose name will be retrieved. Specify zero for the first container.

### `pbstr` [out]

A pointer to a **LPWSTR** variable that receives the name of the container.

## Return value

The return value is an **HRESULT**. A value of S_OK indicates success. The value ERROR_NO_MORE_ITEMS is returned when there are no more items.

## Remarks

If the
[ProviderNameWStr](https://learn.microsoft.com/windows/desktop/api/xenroll/nf-xenroll-ienroll-get_providernamewstr) property value has not been set, the default value (usually Microsoft Base Cryptographic Provider) of **ProviderNameWStr** as set in the registry is used.

## See also

[IEnroll](https://learn.microsoft.com/windows/desktop/api/xenroll/nn-xenroll-ienroll4)