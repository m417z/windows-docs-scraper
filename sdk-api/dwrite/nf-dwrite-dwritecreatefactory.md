# DWriteCreateFactory function

## Description

Creates a DirectWrite factory object that is used for subsequent creation of individual DirectWrite objects.

## Parameters

### `factoryType` [in]

Type: **[DWRITE_FACTORY_TYPE](https://learn.microsoft.com/windows/win32/api/dwrite/ne-dwrite-dwrite_factory_type)**

A value that specifies whether the factory object will be shared or isolated.

### `iid` [in]

Type: **REFIID**

A GUID value that identifies the DirectWrite factory interface, such as __uuidof([IDWriteFactory](https://learn.microsoft.com/windows/win32/api/dwrite/nn-dwrite-idwritefactory)).

### `factory` [out]

Type: **IUnknown****

An address of a pointer to the newly created DirectWrite factory object.

## Return value

Type: **HRESULT**

If this function succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This function creates a [DirectWrite](https://learn.microsoft.com/windows/win32/DirectWrite/direct-write-portal) factory object that is used for subsequent creation of individual DirectWrite objects.
DirectWrite factory contains internal state data such as font loader registration and cached font data.
In most cases it is recommended you use the shared factory object, because it allows multiple components that use DirectWrite to share internal DirectWrite state data, and thereby reduce memory usage.
However, there are cases when it is desirable to reduce the impact of a component,
such as a plug-in from an untrusted source, on the rest of the process, by sandboxing and isolating it from the rest of the process components. In such cases, it is recommended you use an isolated factory for the sandboxed component.

The following example shows how to create a shared [DirectWrite](https://learn.microsoft.com/windows/win32/DirectWrite/direct-write-portal) factory.

```cpp

if (SUCCEEDED(hr))
{
    hr = DWriteCreateFactory(
        DWRITE_FACTORY_TYPE_SHARED,
        __uuidof(IDWriteFactory),
        reinterpret_cast<IUnknown**>(&pDWriteFactory_)
        );
}

```