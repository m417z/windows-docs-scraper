# RoGetParameterizedTypeInstanceIID function

## Description

Computes the interface identifier (IID) of the interface or delegate type that results when a parameterized interface or delegate is instantiated with the specified type arguments.

## Parameters

### `nameElementCount`

Type: **UINT32**

Number of elements in *nameElements.*

### `nameElements` [in]

Type: **PCWSTR***

A parsed Windows Runtime type name, as returned by the [RoParseTypeName](https://learn.microsoft.com/windows/desktop/api/rometadataresolution/nf-rometadataresolution-roparsetypename) function.
For example, "Windows.Foundation.Collections.IVector`1", and "N1.N2.IFoo".

### `metaDataLocator` [in]

Type: **const [IRoMetaDataLocator](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/ns-roparameterizediid-irometadatalocator)**

A callback to use for resolving metadata.
An implementation should use the [RoGetMetaDataFile](https://learn.microsoft.com/windows/desktop/api/rometadataresolution/nf-rometadataresolution-rogetmetadatafile) function to discover the necessary metadata (.winmd) file and examine the metadata to determine the necessary type information. Because the **RoGetMetaDataFile** function does not cache results, locators should cache the results as appropriate for the programming model being implemented.

### `iid` [out]

Type: **GUID***

The IID of the interface or delegate that corresponds with *nameElements*.

### `pExtra` [out, optional]

Type: **ROPARAMIIDHANDLE***

Handle to the IID that corresponds with *nameElements*.

## Return value

Type: **HRESULT**

| Return code | Description |
| --- | --- |
| **S_OK** | The call was successful. |
| **E_OUTOFMEMORY** | Insufficient memory available to complete the task. |
| **E_INVALIDARG** | The wrong number of type arguments are provided for a parameterized type. |

A failure may also occur if a type is inappropriate for the context in which it appears.

## Remarks

The **RoGetParameterizedTypeInstanceIID** function is for use by programming language implementers.

This function is stateless. The *metaDataLocator* argument is not preserved between calls and may be released as soon as the call returns.

The **RoGetParameterizedTypeInstanceIID** function does not perform deep semantic analysis. For instance, if [IRoSimpleMetaDataBuilder](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/ns-roparameterizediid-irosimplemetadatabuilder) specifies that a structure contains an interface pointer, this function returns success, even though such metadata is semantically invalid. The value of the returned IID is unspecified in such cases.

This function may recursively invoke the metadata locator provided as an argument.

If a call to the [IRoSimpleMetaDataBuilder](https://learn.microsoft.com/windows/desktop/api/roparameterizediid/ns-roparameterizediid-irosimplemetadatabuilder) function fails, this function will return that failure code.

#### Examples

```cpp

#include <stdlib.h>
#include <windows.h>
#include <winrt/paraminstanceapi.h>

HRESULT ExampleMetadataLocator(
    PCWSTR name,
    IRoSimpleMetaDataBuilder& builder)
{
    if (wcscmp(L"Example.IParam`1", name) == 0)
    {
        GUID piidParam= { /* 22046e87-28b5-4c53-9804-bc69f6ee0299 */
            0x22046e87,
            0x28b5,
            0x4c53,
            {0x98, 0x04, 0xbc, 0x69, 0xf6, 0xee, 0x02, 0x99}
        };
        builder.SetParameterizedInterface(piidParam, 1);
    }
    else if (wcscmp(L"Example.InterfaceGroup", name) == 0)
    {
        builder.SetInterfaceGroupSimpleDefault(name, L"Example.IFoo", nullptr);
    }
    else if (wcscmp(L"Example.IFoo", name) == 0)
    {
        GUID iidFoo = { /* f7f968c2-b1d8-47e0-98db-1b04f2bba657 */
            0xf7f968c2,
            0xb1d8,
            0x47e0,
            {0x98, 0xdb, 0x1b, 0x04, 0xf2, 0xbb, 0xa6, 0x57}
        };
        builder.SetWinRtInterface(iidFoo);
    }
    return E_ABORT;
}

int main()
{
    // example, compute IID
    GUID iidResult;
    PCWSTR names = { L"Example.IParam`1", L"Example.InterfaceGroup" };
    HRESULT hr = RoGetParameterizedTypeInstanceIID(
        2,
        names,
        Ro::Locator(&ExampleMetadataLocator),
        &iidResult);
}

```