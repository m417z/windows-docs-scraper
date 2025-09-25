# IMFInputTrustAuthority::RequestAccess

## Description

Requests permission to perform a specified action on the stream.

## Parameters

### `Action` [in]

The requested action, specified as a member of the [MFPOLICYMANAGER_ACTION](https://learn.microsoft.com/windows/desktop/api/mfidl/ne-mfidl-mfpolicymanager_action) enumeration.

### `ppContentEnablerActivate` [out]

Receives the value **NULL** or a pointer to the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface. The **IMFActivate** interface is used to create a content enabler object. The caller must release the interface. For more information, see Remarks.

## Return value

The method returns an HRESULT. Possible values include, but are not limited to, those in the following table.

| Return code | Description |
| --- | --- |
| **S_OK** | The user has permission to perform this action. |
| **NS_E_DRM_NEEDS_INDIVIDUALIZATION** | The user must individualize the application. |
| **NS_E_LICENSE_REQUIRED** | The user must obtain a license. |

## Remarks

This method verifies whether the user has permission to perform a specified action on the stream. The ITA does any work needed to verify the user's right to perform the action, such as checking licenses.

To verify the user's rights, the ITA might need to perform additional steps that require interaction with the user or consent from the user. For example, it might need to acquire a new license or individualize a DRM component. In that case, the ITA creates an activation object for a content enabler and returns the activation object's [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) interface in the *ppContentEnablerActivate* parameter. The activation object is responsible for creating a content enabler that exposes the [IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler) interface. The content enabler is used as follows:

1. The Media Session returns the [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer to the application.
2. The application calls [IMFActivate::ActivateObject](https://learn.microsoft.com/windows/desktop/api/mfobjects/nf-mfobjects-imfactivate-activateobject) to activate the content enabler.
3. The application calls [IMFContentEnabler](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfcontentenabler) methods to perform whatever actions are needed, such as individualization or obtaining a license. The content enabler object must encapsulate this functionality through the **IMFContentEnabler** interface.
4. The Media Session calls **RequestAccess** again.

The return value signals whether the user has permission to perform the action:

* If the user already has permission to perform the action, the method returns S_OK and sets **ppContentEnablerActivate* to **NULL**.
* If the user does not have permission, the method returns a failure code and sets **ppContentEnablerActivate* to **NULL**.
* If the ITA must perform additional steps that require interaction with the user, the method returns a failure code and returns the content enabler's [IMFActivate](https://learn.microsoft.com/windows/desktop/api/mfobjects/nn-mfobjects-imfactivate) pointer in *ppContentEnablerActivate*.

The Media Session will not allow the action unless this method returns S_OK. However, a return value of S_OK does not guarantee that the action will be performed, because some other failure might occur after this method is called. When the action is definitely about to happen, the Media Session calls [IMFInputTrustAuthority::BindAccess](https://learn.microsoft.com/windows/desktop/api/mfidl/nf-mfidl-imfinputtrustauthority-bindaccess).

A stream can go to multiple outputs, so this method might be called multiple times with different actions, once for every output.

## See also

[IMFInputTrustAuthority](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfinputtrustauthority)