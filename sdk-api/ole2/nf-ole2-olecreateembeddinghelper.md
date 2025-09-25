# OleCreateEmbeddingHelper function

## Description

Creates an OLE embedding helper object using application-supplied code aggregated with pieces of the OLE default object handler. This helper object can be created and used in a specific context and role, as determined by the caller.

## Parameters

### `clsid` [in]

CLSID of the class to be helped.

### `pUnkOuter` [in]

If the embedding helper is to be aggregated, pointer to the outer object's controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) interface. If it is not to be aggregated, although this is rare, the value should be **NULL**.

### `flags` [in]

DWORD containing flags that specify the role and creation context for the embedding helper. For legal values, see the following Remarks section.

### `pCF` [in]

Pointer to the [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) interface on the class object the function uses to create the secondary object. In some situations, this value may be **NULL**. For more information, see the following Remarks section.

### `riid` [in]

Reference to the identifier of the interface desired by the caller.

### `lplpObj` [out]

Address of pointer variable that receives the interface pointer requested in riid. Upon successful return, **ppvObj* contains the requested interface pointer on the newly created embedding helper.

## Return value

This function returns S_OK on success. Other possible values include the following.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Insufficient memory for the operation. |
| **E_INVALIDARG** | One or more parameters are invalid. |
| **E_UNEXPECTED** | An unexpected error has occurred. |
| **E_NOINTERFACE** | The provided interface identifier is invalid. |

## Remarks

The **OleCreateEmbeddingHelper** function creates an object that supports the same interface implementations found in the default handler, but which has additional hooks that allow it to be used more generally than just as a handler object. The following two calls produce the same result:

``` syntax
OleCreateEmbeddingHelper(clsid, pUnkOuter, EMBDHLP_INPROC_HANDLER |
    EMBDHLP_CREATENOW, NULL, iid, ppvObj)

OleCreateDefaultHandler(clsid, pUnkOuter, iid, ppvObj)
```

The embedding helper is aggregatable; *pUnkOuter* is the controlling [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown) of the aggregate of which the embedding helper is to be a part. It is used to create a new instance of the OLE default handler, which can be used to support objects in various roles. The caller passes a pointer to its [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) implementation to **OleCreateEmbeddingHelper**. This object and the default handler are then aggregated to create the new embedding helper object.

The **OleCreateEmbeddingHelper** function is usually used to support one of the following implementations:

* An EXE object application that is being used as both a container and a server, and which supports inserting objects into itself. For this case, **CreateEmbeddingHelper** allows the object to support the interfaces usually supported only in the handler. To accomplish this, the application must first register its CLSID for different contexts, making two registration calls to the [CoRegisterClassObject](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-coregisterclassobject) function, rather than one, as follows:

  ``` syntax
  CoRegisterClassObject(clsidMe, pUnkCfLocal, CLSCTX_LOCAL_SERVER,
          REGCLS_MULTI_SEPARATE...)

      CoRegisterClassObject(clsidMe, pUnkCfInProc, CLSCTX_INPROC_SERVER,

          REGCLS_MULTI_SEPARATE...)
  ```

  In these calls, you would pass along different class factory implementations to each of *pUnkCfLocal* and *pUnkCfInProc*. The class factory pointed to by *pUnkCfLocal* would be used to create objects that are to be embedded in a remote process, which is the normal case which uses a handler object associated with the client. However, when a server both creates an object and embeds it within itself, *pUnkCfInProc* points to a class object that can create an object that supports the handler interfaces. The local class is used to create the object and the in-process class creates the embedding helper, passing in the pointer to the first object's class factory in *pCF*.
* A custom in-process object handler, in which case, the DLL creates the embedding helper by passing in a pointer to a private implementation of [IClassFactory](https://learn.microsoft.com/windows/desktop/api/unknwnbase/nn-unknwnbase-iclassfactory) in *pCF*.

The flags parameter indicates how the embedding helper is to be used and how and when the embedding helper is initialized. The values for flags are obtained by OR-ing together values from the following table.

| Values for *flags* Parameter | Purpose |
| --- | --- |
| EMBDHLP_INPROC_HANDLER | Creates an embedding helper that can be used with DLL object applications; specifically, the helper exposes the caching features of the default object handler. |
| EMBDHLP_INPROC_SERVER | Creates an embedding helper that is to be used as part of an in-process server. *pCF* cannot be **NULL**. |
| EMBDHLP_CREATENOW | Creates the secondary object using *pCF* immediately; if pCF is **NULL**, the standard proxy manager is used. |
| EMBDHLP_DELAYCREATE | Delays creation of the secondary object until it is needed (when the helper is put into the running state) to enhance speed and memory use. *pCF* must not be **NULL**. The EMBDHLP_INPROC_HANDLER flag cannot be used with this flag. |

## See also

[OleCreateDefaultHandler](https://learn.microsoft.com/windows/desktop/api/ole2/nf-ole2-olecreatedefaulthandler)