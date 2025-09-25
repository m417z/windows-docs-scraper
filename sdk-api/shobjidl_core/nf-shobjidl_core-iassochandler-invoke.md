# IAssocHandler::Invoke

## Description

Directly invokes the associated handler.

## Parameters

### `pdo` [in]

Type: **[IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject)***

A pointer to an [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) that represents the selected item on which to invoke the handler. Note that you should not call **IAssocHandler::Invoke** with a selection of multiple items. If you have multiple items, call [IAssocHandler::CreateInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-createinvoker) instead. See Remarks for more details.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

[IAssocHandler](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandler) objects are typically used to populate an **Open With** menu. When one of those menu items is selected, this method is called to launch the chosen application.

### Invoke and CreateInvoker

The [IDataObject](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-idataobject) used by these methods can represent either a single file or a selection of multiple files. Not all applications support the multiple file option. The applications that do support that scenario might impose other restrictions, such as the number of files that can be opened simultaneously, or the acceptable combination of file types.

Therefore, an application often must determine whether the handler supports the selection before trying to invoke the handler. For example, an application might enable a menu item only if it has verified that the selection in question was supported by that handler.

It is generally safe to assume that an application will support invocation on a single item, and in those cases the application typically calls **IAssocHandler::Invoke** based on that assumption.

For multiple selection scenarios, however, the application should call [IAssocHandler::CreateInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandler-createinvoker). That method retrieves an [IAssocHandlerInvoker](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iassochandlerinvoker) object that allows the calling application to first check whether the selection is supported ([SupportsSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandlerinvoker-supportsselection)), then to invoke the handler ([Invoke](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iassochandlerinvoker-invoke)).

**IAssocHandler::Invoke** can be called on a selection of multiple files, but it is not recommended because of the large processing load involved and no guarantee that it will succeed.