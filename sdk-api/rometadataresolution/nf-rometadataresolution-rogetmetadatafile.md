# RoGetMetaDataFile function

## Description

Locates and retrieves the metadata file that describes the Application Binary Interface (ABI) for the specified typename.

## Parameters

### `name` [in]

Type: **const [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

The name to resolve, either a typename or a namespace. The name input string must be non-empty and must not contain embedded NUL characters. If the name is a dot-separated string, then the substring to the left of the last dot and the substring to the right of the last dot must be non-empty.

### `metaDataDispenser` [in, optional]

Type: **IMetaDataDispenserEx***

A metadata dispenser that the caller can optionally pass in for the **RoGetMetaDataFile** function to be able to open the metadata files through the provided **IMetaDataDispenserEx::OpenScope** method. If the metadata dispenser parameter is set to **nullptr**, the function creates an internal instance of the refactored metadata reader (RoMetadata.dll) and uses its **IMetaDataDispenserEx::OpenScope** method. You can create a metadata dispenser using the [MetaDataGetDispenser](https://learn.microsoft.com/windows/win32/api/rometadata/nf-rometadata-metadatagetdispenser) function.

### `metaDataFilePath` [out, optional]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)***

The absolute path of the metadata (.winmd) file that describes the ABI, unless set to **nullptr**. The caller is responsible for freeing the [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring) by calling the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) method.

### `metaDataImport` [out, optional]

Type: **IMetaDataImport2****

A pointer to the metadata file reader object. If the caller passes in a **nullptr** , the function releases the **IMetaDataImport2** reference, otherwise the caller must release the reference. The value is set to **nullptr** on failure.

### `typeDefToken` [out, optional]

Type: **mdTypeDef***

If the name input string is resolved successfully as a typename, this parameter is set to the token of the typename.

On failure, this parameter is set to **mdTypeDefNil**.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Resolution was successful, which means that the input string represents a type defined in a .winmd file. |
| **E_INVALIDARG** | At least one of the following properties of the input name string does not hold:<br><br>* Not null, not empty<br>* Does not contain embedded null characters.<br>* If a dot-separated string, the substring to the left of the last dot and the substring to the right of the last dot must be non-empty. |
| **RO_E_METADATA_NAME_NOT_FOUND** | The input string is not a type defined in any examined .winmd file. |
| **RO_E_METADATA_NAME_IS_NAMESPACE** | The input string is an existing namespace rather than a typename. |

## Remarks

The caller can optionally pass-in a metadata dispenser for the **RoGetMetaDataFile** function to open the metadata files through the **IMetaDataDispenserEx::OpenScope** method.

If the metadata dispenser parameter is set to **nullptr**, the function creates an internal instance of the refactored metadata reader and uses that reader’s **IMetaDataDispenserEx::OpenScope** method.

The **RoGetMetaDataFile** function is guaranteed to be thread-safe if you pass-in **nullptr** to the metadata dispenser parameter, as the function creates an internal read-only metadata reader. This guarantee also holds if you pass in the read-only metadata reader, like RoMetadata to the function.

All three output parameters are optional and none of them needs to be specified. Calling the **RoGetMetaDataFile** function with **nullptr** for all output parameters is equivalent to asking whether the input typename or namespace is defined.

The metadata reader object reference and the TypeDef token parameters paired, so both must be set together or be set to **nullptr**.

There are three possible type resolution scenarios:

|  |  |
| --- | --- |
| Scenario #1 | **Typename input string is a type defined in a WinMD file.**<br><br>* Return Value<br><br>  **S_OK**<br>* Metadata file path output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it holds the absolute path of the .winmd file that describes the given type's ABI. The caller is responsible for freeing the **HSTRING** by calling [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring).<br>* Reference to the metadata reader object output parameter<br><br>  This is an optional output parameter. If not **nullptr**, it holds a reference to the metadata reader object (**IMetaDataImport2**) and the caller is responsible for releasing it. If the caller passes **nullptr** for this parameter, it means that the caller does not want the metadata reader object, so the function releases the internal reference.<br>* Typedef token output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it is set to the token of the type’s **typedef** entry. Language projections can use this token to call **IMetaDataImport::GetTypeDefProps** to get metadata about the type. |
| Scenario #2 | **Typename input string is actually an existing namespace rather than a typename.**<br><br>* Return value<br><br>  **RO_E_METADATA_NAME_IS_NAMESPACE**<br>* Metadata file path output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by the caller, it is set to **nullptr**.<br>* Reference to the metadata reader object output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it is set to **nullptr**.<br>* Typedef token output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it will is to **mdTypeDefNil**. |
| Scenario #3 | **Input string is not a type defined in any examined WinMD file**<br><br>* Return value<br><br>  **RO_E_METADATA_NAME_NOT_FOUND**<br>* Metadata file path output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it is set to **nullptr**<br>* Reference to the metadata reader object output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it is set to **nullptr**<br>* Typedef token output parameter<br><br>  This is an optional output parameter. If not set to **nullptr** by caller, it is set to **mdTypeDefNil**. |

The **RoGetMetaDataFile** function resolves an **interfacegroup**, because the **interfacegroup** also is a namespace-qualified typename. The [IInspectable::GetRuntimeClassName](https://learn.microsoft.com/windows/desktop/api/inspectable/nf-inspectable-iinspectable-getruntimeclassname) method returns the string in dot-separated string format for use by **RoGetMetaDataFile**.

Resolving 3rd-party types from a process that's not in a Windows Store app is not supported. In this case, the function returns error **HRESULT_FROM_WIN32(ERROR_NO_PACKAGE)** and sets output parameters to **nullptr**. But Windows types are resolved in a process that's not in a Windows Store app.

#### Examples

The following C++ example shows how to use the **RoGetMetaDataFile** function to find the metadata file for a specified type name.

```cpp
#include <windows.h>
#include <stdio.h>
#include <WinRTString.h>
#include <TypeResolution.h>
#include <atlbase.h>

HRESULT PrintMetaDataFilePathForTypeName(PCWSTR pszTypename);

int ShowUsage()
{
    wprintf(L"Usage: RoGetMetaDataFileSample TypeName\n");
    return -1;
}

int __cdecl wmain(int argc, WCHAR **argv)
{
    if (argc != 2)
    {
        return ShowUsage();
    }

    HRESULT hr = PrintMetaDataFilePathForTypeName(argv[1]);

    if (SUCCEEDED(hr))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

HRESULT PrintMetaDataFilePathForTypeName(PCWSTR pszTypename)
{
    HRESULT hr;
    HSTRING hstrTypeName = nullptr;
    HSTRING hstrMetaDataFilePath = nullptr;
    CComPtr<IMetaDataImport2> spMetaDataImport;
    mdTypeDef typeDef;

    hr = WindowsCreateString(
        pszTypename,
        static_cast<UINT32>(wcslen(pszTypename)),
        &hstrTypeName);

    if (SUCCEEDED(hr))
    {
        hr = RoGetMetaDataFile(
            hstrTypeName,
            nullptr,
            &hstrMetaDataFilePath,
            &spMetaDataImport,
            &typeDef);
    }

    if (SUCCEEDED(hr))
    {
        wprintf(L"Type %s was found in %s\n", pszTypename,  WindowsGetStringRawBuffer(hstrMetaDataFilePath, nullptr));
    }
    else if (hr == RO_E_METADATA_NAME_NOT_FOUND)
    {
        wprintf(L"Type %s was not found!\n", pszTypename);
    }
    else
    {
        wprintf(L"Error %x occurred while trying to resolve %s!\n", hr, pszTypename);
    }

    // Clean up resources.
    if (hstrTypeName != nullptr)
    {
        WindowsDeleteString(hstrTypeName);
    }

    if (hstrMetaDataFilePath != nullptr)
    {
        WindowsDeleteString(hstrMetaDataFilePath);
    }

    return hr;
}

```