# IFaxDoc::get_RecipientState

## Description

Sets or retrieves the **RecipientState** property of a [FaxDoc](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-faxdoc) object. The **RecipientState** property is a null-terminated string that contains the state of the recipient of the fax transmission.

This property is read/write.

## Parameters

## Remarks

The fax recipient's state name or state abbreviation can appear on the cover page.

The **get_RecipientState** method allocates the memory required for the buffer pointed to by the *pVal* parameter. The client application must call the [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) function to deallocate the resources associated with this parameter. For more information, see [Freeing Fax Resources](https://learn.microsoft.com/previous-versions/windows/desktop/fax/-mfax-freeing-fax-resources).