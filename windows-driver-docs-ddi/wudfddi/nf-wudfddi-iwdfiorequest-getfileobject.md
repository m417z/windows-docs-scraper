# IWDFIoRequest::GetFileObject

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetFileObject** method retrieves a pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface that is associated with an I/O request.

## Parameters

### `ppFileObject` [out]

A pointer to a buffer that receives a pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface for the file object. Note that returning **NULL** is valid.

## Remarks

When your driver calls **GetFileObject**, the framework increments the reference count on the interface. Your driver is responsible for releasing the reference when finished with the interface pointer. To do so, either use a smart pointer that automatically decrements the reference count when the object goes out of context, or call [Release](https://learn.microsoft.com/windows/win32/api/unknwn/nf-unknwn-iunknown-release) on the interface when finished with it.

#### Examples

The following code example is taken from the WpdMultiTransportDriver sample in the WDK. The example declares a smart pointer to an [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface, calls **GetFileObject**, and then calls [RetrieveContext](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfobject-retrievecontext) on the file object.

```
  CComPtr<IWDFFile>   pFileObject;

  ...

  // Get the Context map for this client

  pRequest->GetFileObject(&pFileObject);

  if (pFileObject != NULL)
  {
      hr = pFileObject->RetrieveContext((void**)&pClientContextMap);
      CHECK_HR(hr, "Failed to get Contextmap from WDF File Object");
  }

```

## See also

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)

[IWDFIoRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfiorequest)