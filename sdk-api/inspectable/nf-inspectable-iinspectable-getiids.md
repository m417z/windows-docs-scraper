## Description

Gets the interfaces that are implemented by the current Windows Runtime class.

## Parameters

### `iidCount` [out]

Type: **ULONG***

The number of interfaces that are implemented by the current Windows Runtime object, excluding the [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) and [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) implementations.

### `iids` [out]

Type: **IID****

A pointer to an array that contains an IID for each interface implemented by the current Windows Runtime object. The [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) and [IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable) interfaces are excluded.

## Return value

Type: **HRESULT**

This function can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The IID array was allocated and saved in *iids* successfully. |
| **E_OUTOFMEMORY** | Failed to allocate *iids*. |

## Remarks

Use the **GetIids** method to discover the interfaces that are implemented by a Windows Runtime object.

A [QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) call on any IID in the *iids* array must succeed.

The caller is responsible for freeing the IID array by using the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function.

## See also

[IInputPaneInterop](https://learn.microsoft.com/windows/desktop/api/inputpaneinterop/nn-inputpaneinterop-iinputpaneinterop)

[IInspectable](https://learn.microsoft.com/windows/desktop/api/inspectable/nn-inspectable-iinspectable)

[winrt::get_interfaces](https://learn.microsoft.com/uwp/cpp-ref-for-winrt/get-interfaces)