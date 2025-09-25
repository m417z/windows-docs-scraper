# IWDFFile2::RetrieveCountedFileName

## Description

> [!WARNING]
> UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).

The **RetrieveCountedFileName** method retrieves the full counted file name for a file that is associated with a device.

## Parameters

### `pCountedFileName` [out]

A pointer to a caller-allocated buffer. This buffer receives a **NULL** terminated character string that represents the full name of the file that is associated with the device. If the pointer is **NULL**, **RetrieveCountedFileName** retrieves only the string length.

### `pdwCountedFileNameLengthInChars` [in, out]

A pointer to a caller-allocated variable. On input, the driver sets the variable to the length, in characters, of the buffer to which *pdwCountedFileNameLengthInChars* points. On output, the framework sets the variable to the length, in characters, of the character string (including the terminating **NULL** character) that it placed in the buffer. If a counted file name does not exist, the framework sets the variable to zero.

## Return value

**RetrieveCountedFileName** returns S_OK if the operation succeeds. Otherwise, the method might return one of the following values:

| Return code | Description |
|--|--|
| **E_POINTER** | The *pdwCountedFileNameLength* pointer is **NULL**. |
| **HRESULT_FROM_WIN32 (ERROR_INVALID_PARAMETER)** | The counted file name is invalid. |
| **E_NOT_SUFFICIENT_BUFFER** | The buffer that *pCountedFileName* points to is too small. |

This method might return one of the other values in Winerror.h.

## Remarks

A counted file name is a string that can include embedded **NULL** ('\0') characters in addition to a terminating **NULL**. To obtain a name string without embedded **NULL** characters, drivers can call [IWDFFile::RetrieveFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffile-retrievefilename).

Typically, a driver calls **RetrieveCountedFileName** twice, using the following steps:

1. The driver calls **RetrieveCountedFileName** with the *pCountedFileName* parameter set to **NULL**, to obtain the required buffer length.
1. The driver allocates a buffer of the required size.
1. The driver calls **RetrieveCountedFileName** again to obtain the file name string.

### Examples

The following code example obtains the [IWDFFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile2) interface from the [IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile) interface that a driver's [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function receives. The example calls **RetrieveCountedFileName** twice; once to obtain the file name's length and once to retrieve the file name string.

``` cpp
VOID
STDMETHODCALLTYPE
CMyQueue::OnCreateFile(
    __in IWDFIoQueue *pWdfQueue,
    __in IWDFIoRequest *pWdfRequest,
    __in IWDFFile*  pWdfFileObject
    )
 ...
    IWDFFile2*  pWdfFileObject2 = NULL;
    WCHAR*  countedFileName = NULL;
    DWORD  countedFileNameCch = 0;
    HRESULT  hr = S_OK;

    //
    // Obtain IWDFFile2 interface from IWDFFile.
    //
    hr = pWdfFileObject->QueryInterface(IID_PPV_ARGS(&pWdfFileObject2));
    if (!SUCCEEDED(hr))
    {
        goto Done;
    }
    //
    // Get length of counted filename.
    //
    hr = pWdfFileObject2->RetrieveCountedFileName(NULL,
                                                  &countedFileNameCch);
    if (!SUCCEEDED(hr))
    {
        goto Done;
    }
    if (countedFileNameCch != 0)
    {
        //
        // Allocate a buffer.
        //
        countedFileName = new WCHAR[countedFileNameCch];
        if (countedFileName == NULL)
        {
            hr = E_OUTOFMEMORY;
            goto Done;
        }
        //
        // Get counted file name.
        //
        hr = pWdfFileObject2->RetrieveCountedFileName(countedFileName,
                                                      &countedFileNameCch);
        if (!SUCCEEDED(hr))
        {
            goto Done;
        }
    }
    ...
```

## See also

- [IWDFFile2](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile2)
- [IWDFFile::RetrieveFileName](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdffile-retrievefilename)