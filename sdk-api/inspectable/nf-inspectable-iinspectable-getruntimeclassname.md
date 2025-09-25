## Description

Gets the fully qualified name of the current Windows Runtime object.

## Parameters

### `className` [out]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)***

The fully qualified name of the current Windows Runtime object.

## Return value

Type: **HRESULT**

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The *className* string was created successfully. |
| **E_OUTOFMEMORY** | Failed to allocate *className* string. |
| **E_ILLEGAL_METHOD_CALL** | *className* refers to a class factory or a static interface. |

## Remarks

Use the **GetRuntimeClassName** method to retrieve the namespace-qualified name of a Windows Runtime object.

The caller is responsible for freeing the *className* string by using the [WindowsDeleteString](https://learn.microsoft.com/windows/desktop/api/winstring/nf-winstring-windowsdeletestring) function.

The following table shows example class name strings that could be returned by the **GetRuntimeClassName** method.

| Example Class Name | Description |
| --- | --- |
| Fabrikam.Kitchen.IToaster | An interface in the Fabrikam.Kitchen namespace. |
| Fabrikam.Kitchen.Chef | An class in the Fabrikam.Kitchen namespace. |
| Windows.Foundation.Collections.IVector`1<TailspinToys.IStore> | A vector of TailspinToys.IStore interfaces. |
| Windows.Foundation.Collections.IVector`1<Windows.Foundation.Collections.IMap`2<String, TailspinToys.IStore>> | A vector of maps of strings to TailspinToys.IStore interfaces. |

The **GetRuntimeClassName** method provides the most specific type information that the server object guarantees that it implements. The type name may be a runtime class name, interface group name, interface name, or parameterized interface name.

The **GetRuntimeClassName** method returns **E_ILLEGAL_METHOD_CALL** if the class name refers to a class factory or a static interface.

## See also

[IInputPaneInterop](https://learn.microsoft.com/windows/desktop/api/inputpaneinterop/nn-inputpaneinterop-iinputpaneinterop)

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)

[winrt::get_class_name](https://learn.microsoft.com/uwp/cpp-ref-for-winrt/get-class-name)