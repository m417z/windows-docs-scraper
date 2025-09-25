# RoResolveNamespace function

## Description

Determine the direct children, types, and sub-namespaces of the specified Windows Runtime namespace, from any programming language supported by the Windows Runtime.

## Parameters

### `name` [in, optional]

Type: **const [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

Full namespace for which we are trying to retrieve direct children. This is a required parameter.

If this namespace is empty or **nullptr**, the **RoResolveNamespace** function returns top-level namespaces. Both Windows and other top-level namespaces are in the package graph.

### `windowsMetaDataDir` [in, optional]

Type: **const [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

Optional parameter that contains a path to the SDK directory to search for metadata (.winmd) files.

If this parameter is not specified (either empty or **nullptr**), the function searches in the default Windows metadata directory, %windir%\System32\WinMetadata.

### `packageGraphDirsCount` [in]

Type: **const DWORD**

Count of paths in the *packageGraphDirs* array.

### `packageGraphDirs` [in, optional]

Type: **const [HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)***

Count of package paths in the explicit package dependency graph array. The count is ignored if *packageGraphDirs* is **nullptr**.

### `metaDataFilePathsCount` [out, optional]

Type: **DWORD***

Count of metadata files in the *metaDataFilePaths* array.

### `metaDataFilePaths` [out, optional]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)****

Optional output parameter that contains callee-allocated array of absolute file paths of all metadata (.winmd) files that could possibly contain direct children of *name*.

### `subNamespacesCount` [out, optional]

Type: **DWORD***

Count of metadata files in the *subNamespaces* array.

### `subNamespaces` [out, optional]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)****

Optional output parameter that contains a callee-allocated array of names of direct children of the given namespace. This list is a hint of other subnamespaces and is not necessarily complete.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Namespace direct children resolution is successful, which means that at least one file or one subnamespace name was found. |
| **RO_E_METADATA_NAME_NOT_FOUND** | Indicates one of the following:<br><br>* *metaDataFilePaths* and *subNamespaces* output parameters are set, but no metadata files and no subnamespaces for the given namespace were found.<br>* *metaDataFilePaths* only is set, but no metadata files for the given namespace were found.<br>* *subNamespaces* only is set, but no subnamespaces for the given namespace were found. |
| **E_INVALIDARG** | Indicates one of the following:<br><br>* Both *metaDataFilePaths* and *subNamespaces* are not set.<br>* Namespace name has embedded null characters.<br>* Namespace is empty or **NULL** and *subNamespaces* is not set.<br>* Namespace is empty or **NULL** and *metaDataFilePaths* is set. |

## Remarks

Use the **RoResolveNamespace** function to explore Windows Runtime namespace hierarchies.

#### Examples

The following C++ example shows how to use the **RoResolveNamespace** function to find the direct child namespaces for a specified type name.

```cpp
#include <windows.h>
#include <stdio.h>
#include <WinRTString.h>
#include <TypeResolution.h>
#include <atlbase.h>

HRESULT PrintDirectChildrenSubNamespacesAndTypesPaths(PCWSTR pszName);

int ShowUsage()
{
    wprintf(L"Usage: RoResolveNamespaceSample TypeName\n");
    return -1;
}

int __cdecl wmain(int argc, WCHAR **argv)
{
    if (argc != 2)
    {
        return ShowUsage();
    }

    HRESULT hr = PrintDirectChildrenSubNamespacesAndTypesPaths(argv[1]);

    if (SUCCEEDED(hr))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

HRESULT PrintDirectChildrenSubNamespacesAndTypesPaths(PCWSTR pszName)
{
    HRESULT hr;
    HSTRING hstrName = nullptr;
    DWORD cRetrievedSubNamespaces = 0;
    HSTRING *phstrRetrievedSubNamespaces = nullptr;
    DWORD cRetrievedMetaDataFilePaths = 0;
    HSTRING *phstrRetrievedMetaDataFiles = nullptr;

    hr = WindowsCreateString(
        pszName,
        static_cast<UINT32>(wcslen(pszName)),
        &hstrName);

    if (SUCCEEDED(hr))
    {
        hr = RoResolveNamespace(
            hstrName,
            nullptr,
            0,
            nullptr,
            &cRetrievedMetaDataFilePaths,
            &phstrRetrievedMetaDataFiles,
            &cRetrievedSubNamespaces,
            &phstrRetrievedSubNamespaces);
    }

    if (SUCCEEDED(hr))
    {
        if (cRetrievedSubNamespaces != 0)
        {
            wprintf(L"Direct-children subnamespaces of %s are:\n", pszName);

            for (DWORD i = 0; i < cRetrievedSubNamespaces; i++)
            {
                wprintf(L"Subnamespace %d: %s\n", i, WindowsGetStringRawBuffer(phstrRetrievedSubNamespaces[i], nullptr));
            }
        }

        if (cRetrievedMetaDataFilePaths != 0)
        {
            wprintf(L"Potential direct-children types of %s could be found in:\n", pszName);

            for (DWORD i = 0; i < cRetrievedMetaDataFilePaths; i++)
            {
                wprintf(L"Metadata file path %d: %s\n", i, WindowsGetStringRawBuffer(phstrRetrievedMetaDataFiles[i], nullptr));
            }
        }
    }
    else if (hr == RO_E_METADATA_NAME_NOT_FOUND)
    {
        wprintf(L"Name %s was not found!\n", pszName);
    }
    else
    {
        wprintf(L"Error %x occurred while trying to resolve %s!\n", hr, pszName);
    }

    // Clean up resources.
    if (hstrName != nullptr)
    {
        WindowsDeleteString(hstrName);
    }

    for (DWORD i = 0; i < cRetrievedSubNamespaces; i++)
    {
        WindowsDeleteString(phstrRetrievedSubNamespaces[i]);
    }

    CoTaskMemFree(phstrRetrievedSubNamespaces);

    for (DWORD i = 0; i < cRetrievedMetaDataFilePaths; i++)
    {
        WindowsDeleteString(phstrRetrievedMetaDataFiles[i]);
    }

    CoTaskMemFree(phstrRetrievedMetaDataFiles);

    return hr;
}

```