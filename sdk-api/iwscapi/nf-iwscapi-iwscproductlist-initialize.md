# IWSCProductList::Initialize

## Description

Gathers information on all of the providers of the specified type on the computer.

## Parameters

### `provider` [in]

A value from the [WSC_SECURITY_PROVIDER](https://learn.microsoft.com/windows/desktop/api/wscapi/ne-wscapi-wsc_security_provider) enumeration with the name of the provider as one of the following values. Note that the possible values can't be combined in a logical OR as they can when used with the [WscGetSecurityProviderHealth](https://learn.microsoft.com/windows/desktop/api/wscapi/nf-wscapi-wscgetsecurityproviderhealth) function.

| Value | Meaning |
| --- | --- |
| **WSC_SECURITY_PROVIDER_ANTIVIRUS** | Antivirus products. |
| **WSC_SECURITY_PROVIDER_ANTISPYWARE** | Anti-spyware products. |
| **WSC_SECURITY_PROVIDER_FIREWALL** | Firewall products. |

## Return value

If the method succeeds, returns S_OK.

If the method fails, returns a Win32 error code.

## Remarks

Once the client gets an [IWSCProductList](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproductlist) pointer, they must call **Initialize** with a provider type, which gathers information on all the providers of that type installed on the system. Only one type of provider can be specified when calling **Initialize**, and the **Initialize** method may only be called once for each instance of an **IWSCProductList** pointer. After the list has been initialized, the user is free to call [Count](https://learn.microsoft.com/windows/desktop/api/iwscapi/nf-iwscapi-iwscproductlist-get_count) to obtain the number of providers in the list and [Item](https://learn.microsoft.com/windows/desktop/api/iwscapi/nf-iwscapi-iwscproductlist-get_item) to retrieve an individual provider.

## See also

[IWSCProductList](https://learn.microsoft.com/windows/desktop/api/iwscapi/nn-iwscapi-iwscproductlist)