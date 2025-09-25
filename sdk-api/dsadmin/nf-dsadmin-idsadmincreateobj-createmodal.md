# IDsAdminCreateObj::CreateModal

## Description

The **IDsAdminCreateObj::CreateModal** method displays the object creation wizard and returns the newly created object. The [IDsAdminCreateObj::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadmincreateobj-initialize) method must be called before **IDsAdminCreateObj::CreateModal** can be called.

## Parameters

### `hwndParent` [in]

Contains the window handle of the owner of the wizard. This value cannot be **NULL**. Use the result of the [GetDesktopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdesktopwindow) function if no parent window is available.

### `ppADsObj` [out]

Pointer to an [IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads) interface pointer that receives the newly created object. This parameter receives **NULL** if the object creation wizard fails or is canceled. The caller must release this interface when it is no longer required. This parameter may be **NULL** if this object is not required.

## Return value

This method can return one of these values.

Returns an OLE-defined error code or one of the following values.

## Remarks

If the user cancels the object creation wizard, this method returns S_FALSE. If *ppADsObj* is not **NULL**, *ppADsObj* receives a **NULL** value. Because of this, the use of the [SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded) macro to determine if *ppADsObj* is valid should be avoided. Always test the contents of *ppADsObj* for a non-**NULL** value before using the interface pointer.

## See also

[GetDesktopWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdesktopwindow)

[IADs](https://learn.microsoft.com/windows/desktop/api/iads/nn-iads-iads)

[IDsAdminCreateObj](https://learn.microsoft.com/windows/desktop/api/dsadmin/nn-dsadmin-idsadmincreateobj)

[IDsAdminCreateObj::Initialize](https://learn.microsoft.com/windows/desktop/api/dsadmin/nf-dsadmin-idsadmincreateobj-initialize)

[SUCCEEDED](https://learn.microsoft.com/windows/desktop/api/winerror/nf-winerror-succeeded)