# IOleInPlaceSiteEx::RequestUIActivate

## Description

Notifies the container that the object is about to enter the UI-active state.

## Return value

This method returns S_OK if the object can continue the activation process and call [IOleInPlaceSite::OnUIActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuiactivate). Other possible return values include the following.

| Return code | Description |
| --- | --- |
| **S_FALSE** | The object cannot enter the UI-active state. The object must call [IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate) so the container can perform its the necessary processing to restore the focus. |
| **E_FAIL** | The operation failed. |

## Remarks

An object calls this method to determine if it can enter the UI-active state and to notify the container that it is about to make this transition. The container can return S_FALSE to deny this request, for example, if the end user has canceled the operation or if the currently active object will not relinquish its active state.

If the object does not call **IOleInPlaceSiteEx::RequestUIActivate**, the container handles data validation and fires Enter and Exit events from [IOleInPlaceSite::OnUIActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuiactivate).

## See also

[IOleInPlaceSite::OnUIActivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuiactivate)

[IOleInPlaceSite::OnUIDeactivate](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-ioleinplacesite-onuideactivate)

[IOleInPlaceSiteEx](https://learn.microsoft.com/windows/desktop/api/ocidl/nn-ocidl-ioleinplacesiteex)