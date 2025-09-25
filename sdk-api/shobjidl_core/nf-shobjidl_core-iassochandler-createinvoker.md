# IAssocHandler::CreateInvoker

## Description

Retrieves an object that enables the invocation of the associated handler on the current selection. The invoker includes the ability to verify whether the current selection is supported.

## Parameters

### `pdo` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) that represents the selected item or items on which to invoke the handler. Note that if you have only a single item, [IAssocHandler::Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-invoke) could be the better choice. See Remarks for more details.

### `ppInvoker` [out]

Type: **[IAssocHandlerInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandlerinvoker)****

When this method returns, contains the address of a pointer to an [IAssocHandlerInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandlerinvoker) object. This object is used to invoke the menu item after ensuring that the selected items are supported by the associated handler.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler) objects are typically used to populate an **Open With** menu. When one of those menu items is selected, this method is called to launch the chosen application.

### Invoke and CreateInvoker

The [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) used by these methods can represent either a single file or it may represent a selection of multiple files. Not all applications support the multiple files option. Those applications that do support that scenario might impose other restrictions such as the number of files that can be opened at once, or acceptable combinations of file types.

Therefore, an application often must determine whether the handler supports the selection before trying to invoke the handler. For example, an application might enable a menu item only if it knew that the selection in question was supported by that handler.

It is generally safe to assume that an application will support invocation on a single item; in those cases the application typically calls [IAssocHandler::Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-invoke).

For multiple selection scenarios, the application should call **IAssocHandler::CreateInvoker**. That method retrieves an [IAssocHandlerInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandlerinvoker) object that allows the calling application to first check whether the selection is supported ([SupportsSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandlerinvoker-supportsselection)), then to invoke the handler ([Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandlerinvoker-invoke)).

[IAssocHandler::Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-invoke) can be called on a selection of multiple files, but it is not recommended due to the large processing load involved and no guarantee of success.

## See also

[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler)

[IAssocHandler::Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-invoke)

[IEnumAssocHandlers](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ienumassochandlers)