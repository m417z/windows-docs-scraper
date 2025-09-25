# IAccessibleHandler::AccessibleObjectFromID

## Description

The **AccessibleObjectFromID** method retrieves an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for the interface associated with the given object ID. Oleacc.dll uses this method to obtain an **IAccessible** interface pointer for proxies that are supplied by other code.

**Note** **IAccessibleHandler::AccessibleObjectFromID** is deprecated and should not be used.

## Parameters

### `hwnd` [in]

Type: **long**

Specifies the handle of a window for which an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer is to be retrieved.

### `lObjectID` [in]

Type: **long**

Specifies the object ID. This value is one of the standard [object identifier](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers) constants or a custom object ID.

### `pIAccessible` [out]

Type: **LPACCESSIBLE***

Specifies the address of a pointer variable that receives the address of the object's [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, returns S_OK.

If not successful, returns one of the following or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Error | Description |
| --- | --- |
| **E_INVALIDARG** | An argument is not valid. |
| **E_NOINTERFACE** | The requested interface is not supported. |

## Remarks

Oleacc calls this function to obtain an [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer for **HWND**s that have the class name that this handler is registered for.

At startup, Oleacc looks in the registry key HKLM\SOFTWARE\Microsoft\Active Accessibility\Handlers and enumerates over each subkey (Oleacc expects the subkey to be a GUID). Oleacc reads the associated class name from HKCR\CLSID\{guid}\AccClassName, where {guid} was the GUID found under the HKLM\SOFTWARE\Microsoft\Active Accessibility\Handlers key. When Oleacc finds a window with a class name that matches the GUID, it CoCreates the object using the GUID, retrieves the [IAccessibleHandler](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessiblehandler) interface pointer, and calls **AccessibleObjectFromID** on it to get at [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) interface pointer.

As with other [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and functions, clients might receive errors for **IAccessible** interface pointers because of a user action. For more information, see [Receiving Errors for IAccessible Interface Pointers](https://learn.microsoft.com/windows/desktop/WinAuto/receiving-errors-for-iaccessible-interface-pointers).