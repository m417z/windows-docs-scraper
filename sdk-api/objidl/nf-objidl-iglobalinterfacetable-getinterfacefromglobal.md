# IGlobalInterfaceTable::GetInterfaceFromGlobal

## Description

Retrieves a pointer to an interface on an object that is usable by the calling apartment. This interface must be currently registered in the global interface table.

## Parameters

### `dwCookie` [in]

Identifies the interface (and its object), and is retrieved through a call to [IGlobalInterfaceTable::RegisterInterfaceInGlobal](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iglobalinterfacetable-registerinterfaceinglobal).

### `riid` [in]

The IID of the interface.

### `ppv` [out]

A pointer to the pointer for the requested interface.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One or more parameters are invalid. |

## Remarks

After an interface has been registered in the global interface table, an apartment can get a pointer to this interface by calling the **GetInterfaceFromGlobal** method with the supplied cookie. This pointer to the interface can be used in the calling apartment but not by other apartments in the process.

The application is responsible for coordinating access to the global variable during calls to [IGlobalInterfaceTable::RevokeInterfaceFromGlobal](https://learn.microsoft.com/windows/desktop/api/objidl/nf-objidl-iglobalinterfacetable-revokeinterfacefromglobal). That is, the application should ensure that one thread does not call **RevokeInterfaceFromGlobal** while another thread is calling **GetInterfaceFromGlobal** with the same cookie. Multiple calls to **GetInterfaceFromGlobal** for the same cookie are permitted.

The **GetInterfaceFromGlobal** method calls [AddRef](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-addref) on the pointer obtained in the *ppv* parameter. It is the caller's responsibility to call [Release](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on this pointer.

## See also

[IGlobalInterfaceTable](https://learn.microsoft.com/windows/desktop/api/objidl/nn-objidl-iglobalinterfacetable)