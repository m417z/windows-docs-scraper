# IPublishingWizard::Initialize

## Description

Initializes the [Publishing Wizard](https://learn.microsoft.com/windows/desktop/shell/scriptable-shell-objects-roadmap) object with the files to transfer, the settings to use, and the type of wizard to create.

**Note** Windows Vista no longer supports the Online Print Wizard. However, this method can still be used to generate the Add Network Place Wizard.

## Parameters

### `pdo` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an instance of [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) that represents the files or folder to be transferred, if *pszServiceProvider* is `InternetPhotoPrinting`. If *pszServiceProvider* is `AddNetPlace`, this parameter is **NULL**.

### `dwOptions` [in]

Type: **DWORD**

A combination of the following flags.

#### SHPWHF_NORECOMPRESS

Do not allow recompression of image data. For use with the Online Print Wizard.

#### SHPWHF_NONETPLACECREATE

Do not create a network place shortcut when the data transfer is complete. This flag is for use with the Add Network Place Wizard.

#### SHPWHF_NOFILESELECTOR

Do not allow the user to change the file selection within the wizard.

#### SHPWHF_USEMRU

Not supported.

#### SHPWHF_ANYLOCATION

**Windows Vista and later.** For use with the Add Network Place Wizard. If this flag is set, and *pszServiceProvider* is `AddNetPlace`, the Add Network Place wizard shows an option to select a network location other than the locations or providers that are registered to appear in the wizard.

#### SHPWHF_VALIDATEVIAWEBFOLDERS

For use with the Add Network Place Wizard. In Windows XP, if this flag is set and an attempt to open the network location using WebDAV fails, the Add Network Place Wizard attempts to create a web folder for the location, using support for WEC. In Windows Vista and Windows Server 2003, this flag has no effect and network locations without support for WebDAV may not be opened as web folders.

### `pszServiceScope` [in]

Type: **LPCWSTR**

Unicode string that indicates the type of wizard to display. The following case-sensitive values are supported in Windows Vista.

#### AddNetPlace

Initialize the Add Network Place Wizard.

#### InternetPhotoPrinting

Initialize the Online Print Wizard. Not supported in Windows Vista.

## Return value

Type: **HRESULT**

Returns S_OK if successful or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | In Windows Vista, may indicate an attempt to initialize the unsupported Online Print Wizard by passing `InternetPhotoPrinting` in *pszServiceProvider*. <br><br> <br><br>In Windows XP, may indicate that when initializing the Online Print Wizard, the *pdo* parameter is **NULL** or points to an empty selection. |
| **E_NOTIMPL** | The *pszServiceProvider* parameter is not one of the supported values or the *dwOptions* parameter contains an unsupported combination of flags. |

## Remarks

**IPublishingWizard::Initialize**, implemented by a [Publishing Wizard](https://learn.microsoft.com/windows/desktop/shell/scriptable-shell-objects-roadmap) object, is called to initialize the wizard object.

The following sample does not work on Windows Vista because the Online Print Wizard cannot be instantiated through [IPublishingWizard](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ipublishingwizard) in Windows Vista.

```
/* initializing the Online Print Wizard in Windows XP or Windows 2003 Server*/
hr = pPublish->Initialize(pDataObject,  // A data object that represents files or
                                        // folders to transfer.
                          SHPWHF_NOFILESELECTOR,     // Flags
                          L"InternetPhotoPrinting"); // Display the Online Print Wizard.
```

**IPublishingWizard::Initialize** does not actually display the initialized wizard. See the [IPublishingWizard](https://learn.microsoft.com/windows/desktop/api/shobjidl/nn-shobjidl-ipublishingwizard) topic for information on how to display the wizard.