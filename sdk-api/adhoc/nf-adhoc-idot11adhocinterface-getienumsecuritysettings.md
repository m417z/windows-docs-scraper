# IDot11AdHocInterface::GetIEnumSecuritySettings

## Description

Gets the collection of security settings associated with this NIC.

## Parameters

### `ppEnum` [out]

A pointer to an [IEnumDot11AdHocSecuritySettings](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-ienumdot11adhocsecuritysettings) interface that contains the collection of security settings.

## Return value

Possible return values include, but are not limited to, the following.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_FAIL** | The method failed. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **E_POINTER** | A pointer passed as a parameter is not valid. |

## See also

[IDot11AdHocInterface](https://learn.microsoft.com/windows/desktop/api/adhoc/nn-adhoc-idot11adhocinterface)