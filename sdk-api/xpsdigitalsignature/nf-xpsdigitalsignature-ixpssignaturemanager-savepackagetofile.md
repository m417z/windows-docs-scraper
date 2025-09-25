# IXpsSignatureManager::SavePackageToFile

## Description

Saves the XPS package to a file.

## Parameters

### `fileName` [in]

The name of the file where the XPS package is to be created and saved.

### `securityAttributes` [in]

The [SECURITY_ATTRIBUTES](https://learn.microsoft.com/windows/win32/api/wtypesbase/ns-wtypesbase-security_attributes) structure, which contains two separate but related data members:

* **lpSecurityDescriptor**, an optional security descriptor.
* **bInheritHandle**, a Boolean value that determines whether the returned handle can be inherited by child processes.

If the **lpSecurityDescriptor** member of the structure is **NULL**, the file or device that is associated with the returned handle is assigned a default security descriptor.

For more information about this parameter, see [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

### `flagsAndAttributes` [in]

The file or device attributes and flags that will be used in file creation. For more information about this parameter, see the description of the *dwFlagsAndAttributes* parameter in [CreateFile](https://learn.microsoft.com/windows/desktop/api/fileapi/nf-fileapi-createfilea).

## Return value

The method returns an **HRESULT**. Possible values include, but are not limited to, those in the table that follows. For return values that are not listed in this table, see [XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85)) and [XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85)).

| Return code | Description |
| --- | --- |
| **S_OK** | The method succeeded. |
| **E_POINTER** | *fileName* is **NULL**. |
| **XPS_E_PACKAGE_NOT_OPENED** | An XPS package has not yet been opened in the signature manager. |

## Remarks

If this method returns an **HRESULT** value that is not in the list of return values for this method, the signature manager should be released and recreated.

## See also

[IXpsSignatureManager](https://learn.microsoft.com/windows/desktop/api/xpsdigitalsignature/nn-xpsdigitalsignature-ixpssignaturemanager)

[XML Paper Specification](https://en.wikipedia.org/wiki/Open_XML_Paper_Specification)

[XPS Digital Signature API Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372949(v=vs.85))

[XPS Document Errors](https://learn.microsoft.com/previous-versions/windows/desktop/dd372955(v=vs.85))