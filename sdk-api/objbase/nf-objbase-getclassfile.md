# GetClassFile function

## Description

Returns the CLSID associated with the specified file name.

## Parameters

### `szFilename` [in]

A pointer to the filename for which you are requesting the associated CLSID.

### `pclsid` [out]

A pointer to the location where the associated CLSID is written on return.

## Return value

This function can return any of the file system errors, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The CLSID was retrieved successfully. |
| **MK_E_CANTOPENFILE** | Unable to open the specified file name. |
| **MK_E_INVALIDEXTENSION** | The specified extension in the registry is invalid. |

## Remarks

When given a file name, **GetClassFile** finds the CLSID associated with that file. Examples of its use are in the [OleCreateFromFile](https://learn.microsoft.com/windows/desktop/api/ole/nf-ole-olecreatefromfile) function, which is passed a file name and requires an associated CLSID, and in the OLE implementation of [IMoniker::BindToObject](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-imoniker-bindtoobject), which, when a link to a file-based document is activated, calls **GetClassFile** to locate the object application that can open the file.

**GetClassFile** uses the following strategies to determine an appropriate CLSID:

1. If the file contains a storage object, as determined by a call to the [StgIsStorageFile](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-stgisstoragefile) function, **GetClassFile** returns the CLSID that was written with the [IStorage::SetClass](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-istorage-setclass) method.
2. If the file is not a storage object, **GetClassFile** attempts to match various bits in the file against a pattern in the registry. A pattern in the registry can contain a series of entries of the form:

   entry = *offset*, *cb*, *mask*, *value*

   The value of the *offset* item is an offset from the beginning or end of the file and the *cb* item is a length in bytes. These two values represent a particular byte range in the file. (A negative value for the offset item is interpreted from the end of the file). The *mask* value is a bitmask that is used to perform a logical AND operation with the byte range specified by *offset* and *cb*. The result of the logical AND operation is compared with the *value* item. If the *mask* is omitted, it is assumed to be all ones.

   Each pattern in the registry is compared to the file in the order of the patterns in the database. The first pattern where each of the value items matches the result of the AND operation determines the CLSID of the file. For example, the pattern contained in the following entries of the registry requires that the first four bytes be AB CD 12 34 and that the last four bytes be FE FE FE FE:

   ```
   HKEY_CLASSES_ROOT
      FileType
         {12345678-0000-0001-C000-000000000095}
            0 = 0, 4, FFFFFFFF, ABCD1234
            1 = -4, 4, , FEFEFEFE
   ```

   If a file contains such a pattern, the CLSID {12345678-0000-0001-C000-000000000095} will be associated with this file.
3. If the above strategies fail, **GetClassFile** searches for the **File Extension** key in the registry that corresponds to the .ext portion of the file name. If the database entry contains a valid CLSID, **GetClassFile** returns that CLSID.
4. If all strategies fail, the function returns MK_E_INVALIDEXTENSION.

## See also

[WriteClassStg](https://learn.microsoft.com/windows/desktop/api/coml2api/nf-coml2api-writeclassstg)