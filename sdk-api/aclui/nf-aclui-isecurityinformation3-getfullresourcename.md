# ISecurityInformation3::GetFullResourceName

## Description

The **GetFullResourceName** method retrieves the full path and file name of the object associated with the access control editor that is displayed by calling the [OpenElevatedEditor](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation3-openelevatededitor) method.

## Parameters

### `ppszResourceName` [out]

The full path and file name of the object for which permissions are to be edited.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[ISecurityInformation3](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation3)

[OpenElevatedEditor](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation3-openelevatededitor)