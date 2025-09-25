# IWDFFile2::GetRelatedFileObject

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetRelatedFileObject** method retrieves the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface of a *related file object*, which is a file object that has a technology-specific relationship with another file object.

## Parameters

### `ppRelatedFileObj` [out]

The address of a location that receives a pointer to the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface of a UMDF file object. This file object is related to the file object that exposes the [IWDFFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile2) interface's parent **IWDFFile** interface.

## Remarks

Use of related file objects is technology-specific. For example, [kernel streaming](https://learn.microsoft.com/windows-hardware/drivers/stream/kernel-streaming) uses related file objects to represent the parent filters of child pins.

For more information about related file objects, see the **GetRelatedFileObject** member of the kernel-mode [FILE_OBJECT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_file_object) structure.

#### Examples

The following code example retrieves the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface of a related file object, from the **IWDFFile** interface that a driver's [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function receives.

```
VOID
STDMETHODCALLTYPE
CMyQueue::OnCreateFile(
    __in IWDFIoQueue *pWdfQueue,
    __in IWDFIoRequest *pWdfRequest,
    __in IWDFFile*  pWdfFileObject
    )
 ...
    IWDFFile*  pWdfRelatedFileObject = NULL;
    IWDFFile2*  pWdfFileObject2 = NULL;
    HRESULT  hr = S_OK;

    //
    // Obtain IWDFFile2 interface from IWDFFile.
    //
    hr = pWdfFileObject->QueryInterface(IID_PPV_ARGS(&pWdfFileObject2));
    if (!SUCCEEDED(hr))
    {
        goto Done;
    }
    pWdfFileObject2->GetRelatedFileObject(&pWdfRelatedFileObject);
    ...
```

## See also

[IWDFFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile2)