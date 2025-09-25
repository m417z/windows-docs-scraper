# IFileOperation::CopyItem

## Description

Declares a single item that is to be copied to a specified destination.

## Parameters

### `psiItem` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the source item.

### `psiDestinationFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that specifies the destination folder to contain the copy of the item.

### `pszCopyName` [in]

Type: **LPCWSTR**

Pointer to a new name for the item after it has been copied. This is a null-terminated Unicode string and can be **NULL**. If **NULL**, the name of the destination item is the same as the source.

### `pfopsItem` [in]

Type: **[IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink)***

Pointer to an [IFileOperationProgressSink](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperationprogresssink) object to be used for progress status and error notifications for this specific copy operation. If you call [IFileOperation::Advise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-advise) for the overall operation, progress status and error notifications for the copy operation are included there, so set this parameter to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method does not copy the item, it merely declares the item to be copied. To copy an object, you must make at least the sequence of calls detailed here:

1. Call **IFileOperation::CopyItem** to declare the source item, destination folder, and destination name.
2. Call [IFileOperation::PerformOperations](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-performoperations) to begin the copy operation.

#### Examples

The following example code shows a sample implementation of this method.

```cpp
HRESULT CopyItem(__in PCWSTR pszSrcItem, __in PCWSTR pszDest, PCWSTR pszNewName)
{
    //
    // Initialize COM as STA.
    //
    HRESULT hr = CoInitializeEx(NULL, COINIT_APARTMENTTHREADED | COINIT_DISABLE_OLE1DDE);
    if (SUCCEEDED(hr))
    {
        IFileOperation *pfo;

        //
        // Create the IFileOperation interface
        //
        hr = CoCreateInstance(CLSID_FileOperation,
                              NULL,
                              CLSCTX_ALL,
                              IID_PPV_ARGS(&pfo));
        if (SUCCEEDED(hr))
        {
            //
            // Set the operation flags. Turn off all UI from being shown to the
            // user during the operation. This includes error, confirmation,
            // and progress dialogs.
            //
            hr = pfo->SetOperationFlags(FOF_NO_UI);
            if (SUCCEEDED(hr))
            {
                //
                // Create an IShellItem from the supplied source path.
                //
                IShellItem *psiFrom = NULL;
                hr = SHCreateItemFromParsingName(pszSrcItem,
                                                 NULL,
                                                 IID_PPV_ARGS(&psiFrom));
                if (SUCCEEDED(hr))
                {
                    IShellItem *psiTo = NULL;

                    if (NULL != pszDest)
                    {
                        //
                        // Create an IShellItem from the supplied
                        // destination path.
                        //
                        hr = SHCreateItemFromParsingName(pszDest,
                                                         NULL,
                                                         IID_PPV_ARGS(&psiTo));
                    }

                    if (SUCCEEDED(hr))
                    {
                        //
                        // Add the operation
                        //
                        hr = pfo->CopyItem(psiFrom, psiTo, pszNewName, NULL);

                        if (NULL != psiTo)
                        {
                            psiTo->Release();
                        }
                    }

                    psiFrom->Release();
                }

                if (SUCCEEDED(hr))
                {
                    //
                    // Perform the operation to copy the file.
                    //
                    hr = pfo->PerformOperations();
                }
            }

            //
            // Release the IFileOperation interface.
            //
            pfo->Release();
        }

        CoUninitialize();
    }
    return hr;
}
```

## See also

[IFileOperation](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifileoperation)

[IFileOperation::CopyItems](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperation-copyitems)

[PostCopyItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-postcopyitem)

[PreCopyItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileoperationprogresssink-precopyitem)