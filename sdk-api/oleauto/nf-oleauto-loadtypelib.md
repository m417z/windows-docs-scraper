# LoadTypeLib function

## Description

Loads and registers a type library.

## Parameters

### `szFile`

The name of the file from which the method should attempt to load a type library.

### `pptlib`

The loaded type library.

## Return value

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Success. |
| **E_INVALIDARG** | One or more of the arguments is not valid. |
| **E_OUTOFMEMORY** | Insufficient memory to complete the operation. |
| **TYPE_E_IOERROR** | The function could not write to the file. |
| **TYPE_E_INVALIDSTATE** | The type library could not be opened. |
| **TYPE_E_INVDATAREAD** | The function could not read from the file. |
| **TYPE_E_UNSUPFORMAT** | The type library has an older format. |
| **TYPE_E_UNKNOWNLCID** | The LCID could not be found in the OLE-supported DLLs. |
| **TYPE_E_CANTLOADLIBRARY** | The type library or DLL could not be loaded. |

## Remarks

The function **LoadTypeLib** loads a type library (usually created with MkTypLib) that is stored in the specified file. If *szFile* specifies only a file name without any path, **LoadTypeLib** searches for the file and proceeds as follows:

* If the file is a stand-alone type library implemented by Typelib.dll, the library is loaded directly.
* If the file is a DLL or an executable file, it is loaded. By default, the type library is extracted from the first resource of type [ITypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oaidl/nn-oaidl-itypelib). To load a different type of library resource, append an integer index to *szFile*. For example:

  ```cpp
  ITypeLib *ptlib;
  LoadTypeLib("C:\\MONTANA\\EXE\\MFA.EXE\\3", &ptlib)
  ```

  This statement loads the type library resource 3 from the file Mfa.exe file.
* If the file is none of the above, the file name is parsed into a moniker (an object that represents a file-based link source), and then bound to the moniker. This approach allows **LoadTypeLib** to be used on foreign type libraries, including in-memory type libraries. Foreign type libraries cannot reside in a DLL or an executable file. For more information on monikers, see the COM Programmer's Reference.

If the type library is already loaded, **LoadTypeLib** increments the type library's reference count and returns a pointer to the type library.

For backward compatibility, **LoadTypeLib** will register the type library if the path is not specified in the *szFile* parameter. **LoadTypeLib** will not register the type library if the path of the type library is specified. It is recommended that [RegisterTypeLib](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-registertypelib) be used to register a type library.