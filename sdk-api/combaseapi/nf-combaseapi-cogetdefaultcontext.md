# CoGetDefaultContext function

## Description

Retrieves a reference to the default context of the specified apartment.

## Parameters

### `aptType` [in]

The apartment type of the default context that is being requested. This parameter can be one of the following values.

| Value | Meaning |
| --- | --- |
| **APTTYPE_CURRENT**<br><br>-1 | The caller's apartment. |
| **APTTYPE_MTA**<br><br>1 | The multithreaded apartment for the current process. |
| **APTTYPE_NA**<br><br>2 | The neutral apartment for the current process. |
| **APTTYPE_MAINSTA**<br><br>3 | The main single-threaded apartment for the current process. |

The [APTTYPE](https://learn.microsoft.com/windows/desktop/api/objidl/ne-objidl-apttype) value APTTYPE_STA (0) is not supported. A process can contain multiple single-threaded apartments, each with its own context, so **CoGetDefaultContext** could not determine which STA is of interest. Therefore, this function returns E_INVALIDARG if APTTYPE_STA is specified.

### `riid` [in]

The interface identifier (IID) of the interface that is being requested on the default context. Typically, the caller requests IID_IObjectContext. The default context does not support all of the normal object context interfaces.

### `ppv` [out]

A reference to the interface specified by riid on the default context. If the object's component is non-configured, (that is, the object's component has not been imported into a COM+ application), or if the **CoGetDefaultContext** function is called from a constructor or an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) method, this parameter is set to a **NULL** pointer.

## Return value

This method can return the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **E_INVALIDARG** | One of the parameters is invalid. |
| **CO_E_NOTINITIALIZED** | The caller is not in an initialized apartment. |
| **E_NOINTERFACE** | The object context does not support the interface specified by *riid*. |

## Remarks

Every COM apartment has a special context called the default context. A default context is different from all the other, non-default contexts in an apartment because it does not provide runtime services. It does not support all of the normal object context interfaces.

The default context is also used by instances of non-configured COM components, (that is, components that have not been part of a COM+ application), when they are created from an apartment that does not support their threading model. In other words, if a COM object creates an instance of a non-configured component and the new object cannot be added to its creator's context because of its threading model, the new object is instead added to the default context of an apartment that supports its threading model.

An object should never pass an [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext) reference to another object. If you pass an **IObjectContext** reference to another object, it is no longer a valid reference.

When an object obtains a reference to an [IObjectContext](https://learn.microsoft.com/windows/desktop/api/comsvcs/nn-comsvcs-iobjectcontext), it must release the **IObjectContext** object when it is finished with it.

## See also

[COM+ Contexts and Threading Models](https://learn.microsoft.com/windows/desktop/cossdk/com--contexts-and-threading-models)