# IWDFFile::RetrieveFileName

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **RetrieveFileName** method retrieves the full name of the file that is associated with the underlying kernel-mode device.

## Parameters

### `pFileName` [out]

A pointer to a caller-supplied buffer that receives a **NULL**-terminated string that represents the full name of the file that is associated with the underlying kernel-mode device, if the supplied pointer is non-**NULL** and **RetrieveFileName** is successful.

### `pdwFileNameLengthInChars` [in, out]

A pointer to a caller-supplied variable that receives the size, in characters, of the full file name that *pFileName* points to. If the buffer at *pFileName* is non-**NULL**, the framework returns the size, in characters, of the file name string.

On input, the driver sets this variable to the size, in characters, of the buffer that *pFileName* points to. If the driver supplies **NULL** for *pFileName* and zero for the variable that *pdwFileNameLengthInChars* points to, the framework sets the variable to the size, in characters, that the file name string requires.

## Return value

**RetrieveFileName** returns S_OK for the following scenarios:

* The buffer that the *pFileName* parameter points to was non-**NULL** and large enough to hold the name string, including the **NULL** character, and the framework successfully copied the string into the supplied buffer and set the variable that is pointed to by the *pdwFileNameLengthInChars* parameter to the number of characters in the string.
* The buffer at *pFileName* was **NULL**, the driver preset the variable at *pdwFileNameLengthInChars* to 0, and the framework set the variable at *pdwFileNameLengthInChars* to the number of characters that are required for the string.

**RetrieveFileName** returns HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER) to indicate that the supplied buffer is non-**NULL** and did not contain enough space to hold the file name. The framework sets the variable at *pdwFileNameLengthInChars* to the number of characters that are required for the string.

**RetrieveFileName** might also return other HRESULT values.

## Remarks

Your driver might call **RetrieveFileName** from its [IQueueCallbackCreate::OnCreateFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iqueuecallbackcreate-oncreatefile) callback function. For more information, see [Using Device Interfaces in UMDF Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-device-interfaces-in-umdf-drivers).

#### Examples

The following code example shows how to retrieve the name of a file.

```
    ULONG fileNameCch = 0;
    PWSTR fileName = NULL;
    ULONG index;

    CComObject<CUmdfHidFile> *file = NULL;

    HRESULT hr;

    // Get the length of the file name to allocate a buffer.
    hr = WdfFile->RetrieveFileName(NULL, &fileNameCch);
    //
    // Allocate the buffer.
    //
    if (SUCCEEDED(hr))
    {
        fileName = new WCHAR[fileNameCch];

        if (fileName == NULL)
        {
            hr = E_OUTOFMEMORY;
        }
    }
    //
    // Get the file name.
    //
    if (SUCCEEDED(hr))
    {
        hr = WdfFile->RetrieveFileName(fileName, &fileNameCch);
    }
```

## See also

[IWDFFile](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nn-wudfddi-iwdffile)