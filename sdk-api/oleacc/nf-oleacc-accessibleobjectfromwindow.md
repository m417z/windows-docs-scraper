# AccessibleObjectFromWindow function

## Description

Retrieves the address of the specified interface for the object associated with the specified window.

## Parameters

### `hwnd` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the handle of a window for which an object is to be retrieved. To retrieve an interface pointer to the cursor or caret object, specify **NULL** and use the appropriate object ID in *dwObjectID*.

### `dwId` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies the object ID. This value is one of the standard [object identifier](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers) constants or a custom object ID such as [OBJID_NATIVEOM](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers), which is the object ID for the Office native object model. For more information about **OBJID_NATIVEOM**, see the Remarks section in this topic.

### `riid` [in]

Type: **REFIID**

Specifies the reference identifier of the requested interface. This value is either IID_IAccessible or IID_IDispatch, but it can also be IID_IUnknown, or the IID of any interface that the object is expected to support.

### `ppvObject` [out]

Type: **void****

Address of a pointer variable that receives the address of the specified interface.

## Return value

Type: **STDAPI**

If successful, returns S_OK.

If not successful, returns one of the following or another standard [COM error code](https://learn.microsoft.com/windows/desktop/WinAuto/return-values).

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | An argument is not valid. |
| **E_NOINTERFACE** | The requested interface is not supported. |

## Remarks

Clients call this function to retrieve the address of an object's [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible), [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface), [IEnumVARIANT](https://learn.microsoft.com/windows/win32/api/oaidl/nn-oaidl-ienumvariant), [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or other supported interface pointer.

As with other [IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible) methods and functions, clients might receive errors for **IAccessible** interface pointers because of a user action. For more information, see [Receiving Errors for IAccessible Interface Pointers](https://learn.microsoft.com/windows/desktop/WinAuto/receiving-errors-for-iaccessible-interface-pointers).

Clients use this function to obtain access to the Microsoft Office 2000 native object model. The native object model provides clients with accessibility information about an Office application's document or client area that is not exposed by Microsoft Active Accessibility.

To obtain an [IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface) interface pointer to a class supported by the native object model, specify [OBJID_NATIVEOM](https://learn.microsoft.com/windows/desktop/WinAuto/object-identifiers) in *dwObjectID*. When using this object identifier, the *hwnd* parameter must match the following window class types.

| Office application | Window class | IDispatch pointer to |
| --- | --- | --- |
| Word | _WwG | Window |
| Excel | EXCEL7 | Window |
| PowerPoint | paneClassDC | DocumentWindow |
| Command Bars | MsoCommandBar | CommandBar |

Note that the above window classes correspond to the innermost document window or pane window. For more information about the Office object model, see the [Microsoft Office 2000/Visual Basic Programmer's Guide](https://learn.microsoft.com/previous-versions/office/developer/office2000/aa141393(v=office.10)).

## See also

[AccessibleObjectFromEvent](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessibleobjectfromevent)

[AccessibleObjectFromPoint](https://learn.microsoft.com/windows/desktop/api/oleacc/nf-oleacc-accessibleobjectfrompoint)

[IAccessible](https://learn.microsoft.com/windows/desktop/api/oleacc/nn-oleacc-iaccessible)

[IDispatch](https://learn.microsoft.com/windows/desktop/WinAuto/idispatch-interface)