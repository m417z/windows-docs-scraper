# SHAddDefaultPropertiesByExt function

## Description

Adds default properties to the property store as registered for the specified file extension.

## Parameters

### `pszExt` [in]

Type: **PCWSTR**

A pointer to a null-terminated, Unicode string that specifies the extension.

### `pPropStore` [in]

Type: **[IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore)***

A pointer to the [IPropertyStore](https://learn.microsoft.com/windows/desktop/api/propsys/nn-propsys-ipropertystore) interface that defines the default properties to add.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The list of properties used to set a default value comes from the `SetDefaultsFor` registry value of the ProgID for the file association of the specified file extension. The list is prefixed by "`prop:`" and contains the canonical names of the properties to set the default value, such as: "`prop:System.Author;System.Document.DateCreated`". The possible properties for this list are **System.Author**, **System.Document.DateCreated**, and **System.Photo.DateTaken**. If the `SetDefaultsFor` value does not exist on the ProgID, this function uses the default found on the `SetDefaultsFor` value of **HKEY_CLASSES_ROOT\***.

**System.Author** has the value of the user that performed the action. **System.Document.DateCreated** and **System.Photo.DateTaken** use the current date. These three properties are the only ones for which the system provides special defaults.

Note that there are several types of properties:

1. Properties that derive from the file system (such as, size and date created)
2. Properties that derive from the file (such as, dimensions and number of pages)
3. Properties that are placed in the file (such as, author and tags)

When creating a new file, types one and two are provided just by creating the file. But properties of type three must be set explicitly by a program. The system provides **SHAddDefaultPropertiesByExt** to provide values for up to three specific properties of type three. Sometimes Windows Explorer uses this API when saving a file for the first time, or when creating a new file after the menu choice **New** is selected from a shortcut menu.