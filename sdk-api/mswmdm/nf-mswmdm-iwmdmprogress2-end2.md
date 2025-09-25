# IWMDMProgress2::End2

## Description

The **End2** method extends [IWMDMProgress::End](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress-end) by providing a completion status indicator.

## Parameters

### `hrCompletionCode` [in]

The return value of the operation that ended.

## Return value

The return value from the method is ignored by Windows Media Device Manager.

## Remarks

**IWMDMProgress2** is a callback interface provided by the application to Windows Media Device Manager for a particular operation. **End2** is called when that operation is completed. The *hrCompletionCode* parameter is the completion status of the operation that was in progress. For example, an application can provide an **IWMDMProgress2** interface pointer to the **Insert2** method. When the file transfer done by **Insert2** is completed, **End2** is called on the **IWMDMProgress2** interface pointer with the completion status of the file transfer as the *hrCompletion* parameter.

[IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3) provides more information, and should be implemented instead of this method.

#### Examples

The following C++ code is a simple implementation of the **Progress2** method.

```cpp

HRESULT Progress(DWORD  dwTranspiredTicks)
{
    // TODO: Display the message: "IWMDMProgress::Progress called."
    // followed by the dwTranspiredTicks value.
    return S_OK;
}

```

## See also

[Enabling Notifications](https://learn.microsoft.com/windows/desktop/WMDM/enabling-notifications)

[IWMDMProgress2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmprogress2)

[IWMDMProgress3::End3](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmprogress3-end3)