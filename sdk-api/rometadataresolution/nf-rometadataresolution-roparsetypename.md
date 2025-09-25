# RoParseTypeName function

## Description

Parses a type name and existing type parameters, in the case of parameterized types.

## Parameters

### `typeName` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)**

String-encoded typename. The typename can be a non-namespace-qualified type, a non-parameterized namespace-qualified type or a fully instantiated namespace-qualified parameterized type.

### `partsCount` [out]

Type: **DWORD***

Number of elements in the *typenameParts* array.

### `typeNameParts`

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)****

The first element of the array is the specified type, and the remaining array elements are the type parameters (if any) in prewalk tree order.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Parsing was successful. |
| **E_INVALIDARG** | *typeName* contains embedded nulls or is empty. |
| **RO_E_METADATA_INVALID_TYPE_FORMAT** | *typename* is not well formed. |

## Remarks

The **RoParseTypeName** function parses the string-encoded type name and returns an array of **HSTRING** values. The first element of the array is the base type, and the remaining array elements are the type parameters, if any, in pre-order tree traversal order. **S_OK** is returned if the parsing was successful.

Here are examples of different possible input typenames:

* Example 1 (non-namespace-qualified type)

  + **Input typename**

    String
  + **Output**

    Array element 0: String
* Example 2 (non-parameterized namespace-qualified type)

  + **Input typename**

    Windows.Foundation.IExtensionInformation
  + **Output**

    Array element 0: Windows.Foundation.IExtensionInformation
* Example 3 (instantiated parameterized interface type)

  + **Input typename**

    Windows.Foundation.Collections.IIterator`1<Windows.Foundation.Collections.IMapView`2<Windows.Foundation.Collections.IVector`1<String>, String>>
  + **Output**

    Array element 0: Windows.Foundation.Collections.IIterator`1

    Array element 1: Windows.Foundation.Collections.IMapView`2

    Array element 2: Windows.Foundation.Collections.IVector`1

    Array element 3: String

    Array element 4: String

When parsing a non-parameterized type, the **RoParseTypeName** function returns an array that has one element. Please refer to example 1 and example 2 above.

The input string must be non-empty and it must not contain any embedded null characters. Otherwise, the API fails with **E_INVALIDARG**. If the *typename* is ill-formed, like IVector`1<, then the API will fail with the **RO_E_METADATA_INVALID_TYPE_FORMAT** error code.

The **RoParseTypeName** function validates only the format of the *typename* and not its syntax. For example, the function validates that a namespace-qualified parameterized interface *typename* follows the format shown in the following table, but it does not impose any requirements on what characters/symbols can be used in the *typename*, except that it should not contain ` , <, or > characters.

The format for a string-encoded instantiated parameterized interface is as follows:

|  |  |  |  |  |  |
| --- | --- | --- | --- | --- | --- |
| Name of parameterized interface | Backtick character (`) | Number of type parameters | Left angle bracket (<) | Namespace qualified name of each type parameter, separated by commas. | Right angle bracket (>) |

Type parameters may be:

* Non-parameterized, non-namespace-qualified types, like WinRT fundamental types.
* Non-parameterized namespace-qualified types.
* Fully-instantiated namespace-qualified parameterized interfaces.

On success, the caller is responsible for deallocating the *typenameParts* array returned by **RoParseTypeName** by using [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) to free the array and [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) to free the **HSTRING** values.

#### Examples

The following C++ example shows how to use the **RoParseTypeName** function to find the direct child namespaces for a specified type name.

```cpp
#include <windows.h>
#include <stdio.h>
#include <WinRTString.h>
#include <TypeResolution.h>

HRESULT PrintParameterizedInterfaceParts(PCWSTR pszTypename);

int ShowUsage()
{
    wprintf(L"Usage: RoParseTypeNameSample \"TypeName\"\n");
    return -1;
}

int __cdecl wmain(int argc, WCHAR **argv)
{
    if (argc != 2)
    {
        return ShowUsage();
    }

    HRESULT hr = PrintParameterizedInterfaceParts(argv[1]);

    if (SUCCEEDED(hr))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

HRESULT PrintParameterizedInterfaceParts(PCWSTR pszTypename)
{
    HRESULT hr;
    HSTRING hstrTypeName = nullptr;
    HSTRING *phstrNameParts = nullptr;
    DWORD cRetrievedNameParts = 0;

    hr = WindowsCreateString(
        pszTypename,
        static_cast<UINT32>(wcslen(pszTypename)),
        &hstrTypeName);

    if (SUCCEEDED(hr))
    {
        hr = RoParseTypeName(
            hstrTypeName,
            &cRetrievedNameParts,
            &phstrNameParts);
    }

    if (SUCCEEDED(hr))
    {
        wprintf(L"Parameterized interface %s is composed of:\n", pszTypename);

        for (UINT32 i = 0; i < cRetrievedNameParts; i++)
        {
            wprintf(L"Element %d: %s\n", i, WindowsGetStringRawBuffer(phstrNameParts[i], nullptr));
        }
    }
    else
    {
        wprintf(L"Invalid parameterized interface syntax: %s!\n", pszTypename);
    }

    // Clean up resources.
    if (hstrTypeName != nullptr)
    {
        WindowsDeleteString(hstrTypeName);
    }

    for (UINT32 i = 0; i < cRetrievedNameParts; i++)
    {
        WindowsDeleteString(phstrNameParts[i]);
    }

    CoTaskMemFree(phstrNameParts);

    return hr;
}

```