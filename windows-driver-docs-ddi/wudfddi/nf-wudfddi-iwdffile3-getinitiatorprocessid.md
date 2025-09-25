# IWDFFile3::GetInitiatorProcessId

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **GetInitiatorProcessId** method retrieves the initiator process ID associated with an [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface.

## Parameters

### `pdwProcessId` [out]

Specifies the address of a location that receives the initiator process identifier associated with the file, if any exists. Otherwise, the location receives 0.

## Remarks

Starting in Windows 8, a system component may issue a create on behalf of an app. The driver can call **GetInitiatorProcessId** to determine which process the create operation is ultimately intended for.

**GetInitiatorProcessId** returns zero if no initiator process is associated with the create operation.

For more information about framework file objects, see [Driver-Created Versus Application-Created File Objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/driver-created-versus-application-created-file-objects).

#### Examples

```
VOID
STDMETHODCALLTYPE
CMyQueue::OnCreateFile(
    __in IWDFIoQueue *pWdfQueue,
    __in IWDFIoRequest *pWdfRequest,
    __in IWDFFile*  pWdfFileObject
    )
 ...
    IWDFFile3*  pWdfFileObject3 = NULL;
    HRESULT  hr = S_OK;
    DWORD initiatorProcessId;

    //
    // Obtain IWDFFile3 interface from IWDFFile.
    //
    hr = pWdfFileObject->QueryInterface(IID_PPV_ARGS(&pWdfFileObject3));
    if (!SUCCEEDED(hr))
    {
        goto Done;
    }
    pWdfFileObject3->GetInitiatorProcessId(&initiatorProcessId);
    ...

```

## See also

[IWDFFile3](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile3)