# IWDFRemoteInterfaceInitialize::RetrieveSymbolicLink

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveSymbolicLink** method retrieves the symbolic link name that the operating system assigned to a [device interface](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

## Parameters

### `pSymbolicLink` [out, optional]

A pointer to a buffer that receives a **null**-terminated Unicode character string that represents the symbolic link name. Set this pointer to **NULL** to obtain the required buffer size.

### `pdwSymbolicLinkLengthInChars` [in, out]

A pointer to a caller-allocated location. On input, this location must contain the caller-supplied length of the buffer that *pSymbolicLink* points to. On output, the location receives the length, in characters, of the symbolic link name, including the **NULL** terminating character.

## Return value

**RetrieveSymbolicLink** returns S_OK if the operation succeeds. Otherwise the method might return the following value:

| Return code | Description |
| --- | --- |
| **E_NOT_SUFFICIENT_BUFFER** | The buffer that *pSymbolicLink* points to is too small. In this case, the framework stores the required buffer size in the location that *pdwSymbolicLinkLengthInChars* points to. |

This method might return one of the other values that Winerror.h contains.

## Remarks

The symbolic link name can include an appended backslash (\) character, followed by an instance-specific reference string.

Typically, your driver should call **RetrieveSymbolicLink** twice, as follows:

1. Set the *pSymbolicLink* parameter to **NULL** and call **RetrieveSymbolicLink**. The location that *pdwSymbolicLinkLengthInChars* points to receives the number of characters that the symbolic link name contains.
2. Allocate a buffer that is large enough to receive the symbolic link name.
3. Call **RetrieveSymbolicLink** again, and set the *pSymbolicLink* parameter to the address of the buffer that you allocated.

For more information about the **RetrieveSymbolicLink** method, see [Using Device Interfaces in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how a driver's [IPnpCallbackRemoteInterfaceNotification::OnRemoteInterfaceArrival](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipnpcallbackremoteinterfacenotification-onremoteinterfacearrival) callback function can determine the length of device interface's symbolic link name, allocate a buffer for the name, and then retrieve the name.

```
void
STDMETHODCALLTYPE
CMyDevice::OnRemoteInterfaceArrival(
    __in IWDFRemoteInterfaceInitialize  *FxRemoteInterfaceInit
    )
{
    HRESULT hr;
    INT BufferSize;
    hr= FxRemoteInterfaceInit->RetrieveSymbolicLink(NULL,
                                                    &BufferSize);
    if (FAILED(hr)) goto Error;
    hr = FxDriver->CreateWdfMemory(BufferSize,
                                   NULL,
                                   FxRemoteInterface,
                                   &FxSymLinkBuffer);
    if (FAILED(hr)) goto Error;
    hr= FxRemoteInterfaceInit->RetrieveSymbolicLink(FxSymLinkBuffer->GetDataBuffer(NULL),
                                                    &BufferSize);
    if (FAILED(hr)) goto Error;
...
Error:
...
}
```

## See also

[IWDFRemoteInterfaceInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdfremoteinterfaceinitialize)

[IWDFRemoteInterfaceInitialize::GetInterfaceGuid](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfremoteinterfaceinitialize-getinterfaceguid)