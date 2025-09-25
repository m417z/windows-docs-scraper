# ISecurityInformation3::OpenElevatedEditor

## Description

The **OpenElevatedEditor** method opens an access control editor when a user clicks the **Edit** button on an access control editor page that displays an image of a shield on that **Edit** button. The image of a shield is displayed when the access control editor is launched by a process with a token that lacks permission to save changes to the object being edited.

## Parameters

### `hWnd` [in]

The parent window of the access control editor.

### `uPage` [in]

A value of the [SI_PAGE_TYPE](https://learn.microsoft.com/windows/desktop/api/aclui/ne-aclui-si_page_type) enumeration that indicates the page type on which to display the elevated access control editor.

## Return value

 If the method succeeds, it returns **S_OK**.

If the method fails, it returns an error code. For a list of common error codes, see [Common HRESULT Values](https://learn.microsoft.com/windows/desktop/SecCrypto/common-hresult-values).

## See also

[GetFullResourceName](https://learn.microsoft.com/windows/desktop/api/aclui/nf-aclui-isecurityinformation3-getfullresourcename)

[ISecurityInformation3](https://learn.microsoft.com/windows/desktop/api/aclui/nn-aclui-isecurityinformation3)